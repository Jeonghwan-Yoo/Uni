#include <opencv2/highgui.hpp>
#include <raspicam/raspicam_cv.h>
#include <opencv2/opencv.hpp>
#include <ctime>
#include <iostream>
#include <wiringPi.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BeepPin 4
#define MotorPin 18
#define trig 23 
#define echo 24

using namespace std;
using namespace cv;

int maxPo(double _data[], int _start, int _end) {
	int start = _start;
	int end = _end;
	double data[256];
	int largest = start;
	for (start;start <= end;start++) {
		data[start] = _data[start];
		if (data[start] > data[largest]) {
			largest = start;
		}
	}
	return largest;
}

int minPo(double _data[], int _start, int _end) {
	int start = _start;
	int end = _end;
	double data[256];
	int smallest = start;
	for (start;start <= end;start++) {
		data[start] = _data[start];
		if (data[start] < data[smallest]) {
			smallest = start;
		}
	}
	return smallest;
}

double* shiftToM(double _data_std[], double _data[]) {
	double data[256];
	double data_std[256];
	for (int i = 0; i < 256;i++) {
		data[i] = _data[i];
		data_std[i] = _data_std[i];
	}
	int max = maxPo(data, 0, 255);
	int max_std = maxPo(data_std, 0, 255);
	int interval = max - max_std;
	if (interval >= 0) {
		for (int i = 0;i < 256 - interval;i++) {
			_data[i] = data[i + interval];
			if (i + interval == 255) {
				for (i;i < 256;i++) {
					_data[i] = 0.0;
				}
			}
		}
	}
	else {
		for (int i = 255 + interval;i >= 0;i--) {
			_data[i - interval] = data[i];
			if (i == 0) {
				for (i - interval;i - interval < 0;i--) {
					_data[i - interval] = 0.0;
				}
			}
		}
	}
	return _data;
}

double average(double _data[], int _start, int _end) {
	double sum = 0.0;
	int start = _start;
	int end = _end;
	double data[256];
	for (start;start <= end;start++) {
		data[start] = _data[start];
		sum += data[start];
	}
	return sum / (_end - _start + 1);
}

double average2(double _data[], int _start, int _end) {
	double sum = 0.0;
	int start = _start;
	int end = _end;
	int n = _end - _start + 1;
	int count0 = 0;
	double data[256];
	for (start;start <= end;start++) {
		data[start] = _data[start];
		if (data[start] == 0) {
			count0++;
		}
		sum += data[start];
	}
	return sum / (n - count0);
}

double variance(double _data[], int _start, int _end) {
	double sum = 0.0;
	int start = _start;
	int end = _end;
	double data[256];
	double mean = average(_data, _start, _end);
	for (start;start <= end;start++) {
		data[start] = _data[start];
		sum += (data[start] - mean)*(data[start] - mean);
	}
	return sum / (_end - _start + 1);
}

double stdev(double _data[], int _start, int _end) {
	return sqrt(variance(_data, _start, _end));
}

double correlation(double _data_x[], double _data_y[], int _start, int _end) {
	double sum_x = 0.0;
	double sum_y = 0.0;
	double sum_xy = 0.0;
	double sqSum_x = 0.0;
	double sqSum_y = 0.0;
	int start = _start;
	int end = _end;
	int n = _end - _start + 1;
	double data_x[256];
	double data_y[256];
	for (start;start <= end;start++) {
		data_x[start] = _data_x[start];
		data_y[start] = _data_y[start];
		sum_x = sum_x + data_x[start];
		sum_y = sum_y + data_y[start];
		sum_xy = sum_xy + data_x[start] * data_y[start];
		sqSum_x = sqSum_x + data_x[start] * data_x[start];
		sqSum_y = sqSum_y + data_y[start] * data_y[start];
	}
	double corr = (n*sum_xy - sum_x * sum_y) / sqrt((n*sqSum_x - sum_x * sum_x)*(n*sqSum_y - sum_y * sum_y));
	return corr;
}

double* glcm(const Mat img)
{
	double method[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 };
	//0=energy 1=contrast 2=homogeneity 3=IDM 4=entropy 5=sum mean
	int row = img.rows, col = img.cols;
	cv::Mat gl = cv::Mat::zeros(256, 256, CV_32FC1);

	//creating glcm matrix with 256 levels,radius=1 and in the horizontal direction
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col - 1; j++)
			gl.at<float>(img.at<uchar>(i, j), img.at<uchar>(i, j + 1)) = gl.at<float>(img.at<uchar>(i, j), img.at<uchar>(i, j + 1)) + 1;

	// normalizing glcm matrix for parameter determination
	gl = gl + gl.t();
	gl = gl / sum(gl)[0];

	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++)
		{
			//energy
			//method[0] = method[0]+gl.at<float>(i, j)*gl.at<float>(i, j);
			//contrast
			//method[1] = method[1] + (i - j)*(i - j)*gl.at<float>(i, j);
			//homogeneity
			//method[2] = method[2] + gl.at<float>(i, j) / (1 + abs(i - j));
			//Inverse Difference Moment
			//method[3] = method[3] + gl.at<float>(i, j) / (1 + (i - j)*(i - j));
			//entropy
			//if (gl.at<float>(i, j) != 0)
			//	method[4] = method[4] - gl.at<float>(i, j)*log10(gl.at<float>(i, j));			
			//sum mean
			//method[5] = method[5] + 0.5*(i*gl.at<float>(i, j) + j * gl.at<float>(i, j));
		}
	return method;
}

double sonar_distance() {
	int start_time, end_time;
	float distance_cm;
	digitalWrite(trig, LOW);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);

	while (digitalRead(echo) == 0);
	start_time = micros();
	while (digitalRead(echo) == 1);
	end_time = micros();

	distance_cm = (end_time - start_time) / 29. / 2.;

	return distance_cm;
}

void fb_pavement() {
	digitalWrite(BeepPin, HIGH);  //beep on
	delay(100);                  //delay
	digitalWrite(BeepPin, LOW); //beep off
	delay(100);
	digitalWrite(BeepPin, HIGH);  //beep on
	delay(100);                  //delay
	digitalWrite(BeepPin, LOW); //beep off
	return;
}

void fb_barrier() {
	digitalWrite(MotorPin, HIGH);
	delay(300);
	digitalWrite(MotorPin, LOW);
	digitalWrite(BeepPin, HIGH);  //beep on
	delay(300);                  //delay
	digitalWrite(BeepPin, LOW); //beep off
	return;
}

int main() {
	if (wiringPiSetup() == -1)
	{
		cout << "Setup wiring pi failed";
		return 1;
	}
	wiringPiSetupGpio();
	pinMode(BeepPin, OUTPUT);
	pinMode(MotorPin, OUTPUT);
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);

	raspicam::RaspiCam_Cv Camera;
	Mat img_input;
	//frame measuement time.
	time_t start;
	time_t end;
	double frate = 0;
	double rfrate = 0;
	start = time(NULL);
	end = time(NULL);

	Camera.set(CV_CAP_PROP_FORMAT, CV_8UC3);
	Camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	Camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	Camera.set(CV_CAP_PROP_FPS, 30);

	if (!Camera.open()) {
		cerr << "Error opening the camera" << endl;
		return -1;
	}
	/*
	cv::VideoWriter outputVideo;
		cv::Size frameSize(640,480);
		int fps = 30;

		outputVideo.open("output.avi", cv::VideoWriter::fourcc('X','V','I','D'),
					 fps, frameSize, true);
		if (!outputVideo.isOpened())
		{
				cout  << "Could not open the output video for write: " <<
						"output.avi" << endl;
				return -1;
		}
	*/
	while (1) {
		if (sonar_distance() < 70.0) {
			fb_barrier();
		}
		Camera.grab();
		Camera.retrieve(img_input);
		//putText(img_input, "Dist:"+to_string(sonar_distance()) , Point(380, 100), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255,0), 2);

		frate++;
		if (difftime(end, start) >= 1.0) {
			rfrate = frate;
			frate = 0;
			start = time(NULL);
		}
		end = time(NULL);
		putText(img_input, to_string((int)rfrate), Point(580, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 200, 200), 2);
		Mat img_gray[3];
		Mat img_roi[3];
		Mat img_result[3];
		Mat img_histogram[3];
		Mat img_histogram2[3];

		Rect rec[3];
		rec[0] = { 290,420,60,60 }; //640x480인 경우 가운데 아래
		rec[1] = { 260,360,60,60 };
		rec[2] = { 320,360,60,60 };

		//이미지 파일을 읽어와서 img_input에 저장
		if (img_input.empty())
		{
			cout << "파일을 읽어올수 없습니다." << endl;
			exit(1);
		}
		for (int i = 0;i < 3;i++)
			img_roi[i] = img_input(rec[i]); //roi된 이미지

		//입력영상을 그레이스케일 영상으로 변환
		for (int i = 0;i < 3;i++)
			img_gray[i] = Mat(img_roi[i].rows, img_roi[i].cols, CV_8UC1);

		for (int i = 0;i < 3;i++)
		{
			for (int y = 0; y < img_roi_1.rows; y++) //1
			{
				for (int x = 0; x < img_roi_1.cols; x++)
				{
					//img_input으로부터 현재 위치 (y,x) 픽셀의
					//blue, green, red 값을 읽어온다. 
					uchar blue = img_roi[i].at<Vec3b>(y, x)[0];
					uchar green = img_roi[i].at<Vec3b>(y, x)[1];
					uchar red = img_roi[i].at<Vec3b>(y, x)[2];
					//blue, green, red를 더한 후, 3으로 나누면 그레이스케일이 된다.
					uchar gray = (blue + green + red) / 3.0;
					//Mat타입 변수 img_gray에 저장한다. 
					img_gray[i].at<uchar>(y, x) = gray;
				}
			}
		}

		int histogram[3][256] = { 0, };
		for (int i = 0;i < 3;i++)
		{
			//입력 그레이스케일 영상의 히스토그램 계산
			for (int y = 0; y < img_roi[i].rows; y++)
			{
				for (int x = 0; x < img_roi[i].cols; x++)
				{
					int value = img_gray[i].at<uchar>(y, x);
					histogram[i][value] += 1;
				}
			}
		}

		//입력 그레이스케일 영상의 누적 히스토그램 계산
		int cumulative_histogram[3][256] = { 0, };
		int sum[3] = { 0, };
		for (int i = 0;i < 3;i++)
		{
			for (int j = 1; j < 256; j++)
			{
				sum[i] += histogram[i][j];
				cumulative_histogram[i][j] = sum[i];
			}
		}

		//입력 그레이스케일 영상의 정규화된 누적 히스토그램 계산
		float normalized_cumulative_histogram[3][256] = { 0.0, };
		for (int i = 0;i < 3;i++)
			image_size[i] = img_roi[i].rows * img_roi[i].cols;
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0; j < 256; j++)
			{
				normalized_cumulative_histogram[i][j] = cumulative_histogram[i][j] / (float)image_size[i];
			}
		}

		//히스토그램 평활화 적용 및 결과 영상의 히스토그램 계산
		int histogram2[3][256] = { 0, };
		double histo[3][256] = { 0.0, };
		double histo2[3][256] = { 0.0, };
		for (int i = 0;i < 3;i++)
		{
			img_result[i] = Mat(img_roi[i].rows, img_roi[i].cols, CV_8UC1);
			for (int y = 0;y < img_roi_1.rows;y++)
			{
				for (int x = 0;x < img_roi_1.cols;x++)
				{
					img_result[i].at<uchar>(y, x) = normalized_cumulative_histogram[i][img_gray[i].at<uchar>(y, x)] * 255;
					histogram2[i][img_result[i].at<uchar>(y, x)] += 1;
				}
			}
			img_histogram[i] = Mat(100, 300, CV_8UC1, Scalar(0));
			img_histogram2[i] = Mat(100, 300, CV_8UC1, Scalar(0));

			int max = -1;
			for (int j = 0;j < 256;j++) {
				if (max < histogram[i][j]) {
					max = histogram[i][j];
				}
			}

			for (int j = 0; j < 256; j++)
			{
				histo[i][j] = 100 * histogram[i][j] / (float)max;
				histo2[i][j] = 100 * histogram2[i][j] / (float)max;
				//line(img_histogram[i], cvPoint(j, 100), cvPoint(j, 100 - histo[i][j]), Scalar(255, 255, 255));
				//line(img_histogram2[i], cvPoint(j, 100), cvPoint(j, 100 - histo2[i][j]), Scalar(255, 255, 255));
			}
		}

		//standard sameple image for correlation which is 10th image.
		double data_std[256] = { 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.098901, 0.000000, 1.098901, 1.098901, 0.000000, 0.000000, 0.000000, 1.098901, 0.000000, 0.000000, 1.098901, 1.098901, 0.000000, 0.000000, 1.098901, 1.098901, 0.000000, 0.000000, 0.000000, 2.197802, 4.395605, 3.296703, 0.000000, 2.197802, 1.098901, 1.098901, 1.098901, 2.197802, 4.395605, 2.197802, 2.197802, 4.395605, 4.395605, 1.098901, 2.197802, 7.692307, 8.791209, 5.494505, 4.395605, 12.087913, 6.593407, 10.989011, 5.494505, 10.989011, 13.186813, 12.087913, 23.076923, 17.582418, 24.175825, 31.868132, 37.362637, 32.967033, 36.263737, 34.065933, 36.263737, 51.648350, 53.846153, 46.153847, 64.835167, 65.934067, 67.032967, 79.120880, 65.934067, 78.021980, 78.021980, 69.230766, 96.703300, 82.417580, 100.000000, 89.010986, 98.901100, 78.021980, 73.626373, 87.912086, 94.505493, 98.901100, 90.109894, 72.527473, 79.120880, 91.208794, 75.824173, 59.340660, 60.439560, 71.428574, 64.835167, 51.648350, 72.527473, 74.725273, 50.549450, 48.351650, 50.549450, 34.065933, 42.857143, 32.967033, 41.758244, 32.967033, 32.967033, 38.461540, 27.472527, 20.879122, 21.978022, 19.780220, 27.472527, 24.175825, 38.461540, 26.373627, 17.582418, 17.582418, 14.285714, 15.384615, 19.780220, 13.186813, 20.879122, 12.087913, 21.978022, 13.186813, 7.692307, 19.780220, 12.087913, 10.989011, 5.494505, 14.285714, 15.384615, 14.285714, 5.494505, 15.384615, 12.087913, 10.989011, 2.197802, 7.692307, 3.296703, 10.989011, 4.395605, 6.593407, 2.197802, 6.593407, 3.296703, 7.692307, 5.494505, 1.098901, 3.296703, 8.791209, 3.296703, 4.395605, 8.791209, 1.098901, 7.692307, 3.296703, 0.000000, 3.296703, 1.098901, 5.494505, 2.197802, 0.000000, 2.197802, 4.395605, 1.098901, 1.098901, 1.098901, 1.098901, 1.098901, 1.098901, 3.296703, 0.000000, 0.000000, 0.000000, 0.000000, 1.098901, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000 };

		double data_shift[3][256] = { 0, }; //shift한 temp데이터
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 256;j++) {
				data_shift[i][j] = histo[i][j];
			}
			shiftToM(data_std, data_shift[i]);
		}

		//도로와 인도를 구분
		//putText(img_input, "Avg:"+to_string(average2(histo2[0], 36, 48)) , Point(380, 340), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 2);
		//putText(img_input, "Var:"+to_string(variance(histo2[0], 0, 255)), Point(380, 370), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 2);
		//putText(img_input, "Corr:"+to_string(correlation(data_std, data_shift[0], 0, 255)), Point(380, 400), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 2);
		//filtering
		if (500 < variance(histo2[0], 0, 255) && variance(histo2[0], 0, 255) <= 900) {
			if (0.9 < correlation(data_std, data_shift[0], 0, 255) && correlation(data_std, data_shift[0], 0, 255) <= 1.1) {
				//putText(img_input, "pavement", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 2);
				fb_pavement();
			}
			else if (50 < average2(histo2[0], 36, 48) && average2(histo2[0], 36, 48) <= 85) {
				//putText(img_input, "pavement", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 2);
				fb_pavement();
			}
			else if (170 < maxPo(histo[0], 0, 255) && maxPo(histo[0], 0, 255) < 245) {
				//putText(img_input, "pavement", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 2);
				fb_pavement();
			}
			else {
				//putText(img_input, "sidewalk", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 255, 0), 2);
			}
		}
		else if (170 < maxPo(histo[0], 0, 255) && maxPo(histo[0], 0, 255) < 245) {
			//putText(img_input, "pavement", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 2);
			fb_pavement();
		}
		else {
			if ((500 < variance(histo2[1], 0, 255) && variance(histo2[1], 0, 255) <= 900) &&
				(500 < variance(histo2[2], 0, 255) && variance(histo2[2], 0, 255) <= 900)) {
				if ((0.9 < correlation(data_std, data_shift[1], 0, 255) && correlation(data_std, data_shift[1], 0, 255) <= 1.1) &&
					(0.9 < correlation(data_std, data_shift[2], 0, 255) && correlation(data_std, data_shift[2], 0, 255) <= 1.1)) {
					//putText(img_input, "pavement", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 2);
					fb_pavement();
				}
				else if ((50 < average2(histo2[1], 36, 48) && average2(histo2[1], 36, 48) <= 85) &&
					(50 < average2(histo2[2], 36, 48) && average2(histo2[2], 36, 48) <= 85)) {
					//putText(img_input, "pavement", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 2);
					fb_pavement();
				}
				else if ((170 < maxPo(histo[1], 0, 255) && maxPo(histo[1], 0, 255) < 245) &&
					(220 < maxPo(histo[2], 0, 255) && maxPo(histo[2], 0, 255) < 240)) {
					//putText(img_input, "pavement", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 2);
					fb_pavement();
				}
				else {
					//putText(img_input, "sidewalk", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 255, 0), 2);
					fb_pavement();
				}
			}
			else if ((170 < maxPo(histo[1], 0, 255) && maxPo(histo[1], 0, 255) < 245)
				|| (220 < maxPo(histo[2], 0, 255) && maxPo(histo[2], 0, 255) < 240)) {
				//putText(img_input, "pavement", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255), 2);
				fb_pavement();
			}
			else {
				//putText(img_input, "sidewalk", Point(450, 450), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 255, 0), 2);
			}
		}
		//outputVideo.write(img_input);
		imshow("picamera test", img_input);
		if (waitKey(20) == 27) break; //ESC키 누르면 종료
	}
	Camera.release();
}

