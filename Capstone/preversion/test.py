#import the necessary packages
from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import cv2
import numpy as np
from CameraCalibration import get_camera_calibration, CameraCalibrator
import RPi.GPIO as GPIO
import bluetooth
import sys
import signal

def sendMessageTo1(targetBluetoothMacAddress):
  port = 3
  sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
  sock.connect((targetBluetoothMacAddress, port))
  sock.send("1")
  sock.close()
  time.sleep(0.1)
def sendMessageTo2(targetBluetoothMacAddress):
  port = 3
  sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
  sock.connect((targetBluetoothMacAddress, port))
  sock.send("2")
  sock.close()
  time.sleep(0.1)
def sendMessageTo3(targetBluetoothMacAddress):
  port = 3
  sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
  sock.connect((targetBluetoothMacAddress, port))
  sock.send("3")
  sock.close()
  time.sleep(0.1)
def region_of_interest(img,vertices):
    #Define a blank matrix that matches the image height/width
    mask=np.zeros_like(img)
    #Create a match color with the same color channel counts
    match_mask_color=255
    #Fill inside the polygon
    cv2.fillPoly(mask,vertices,match_mask_color)
    #Returning the image only where mask pixels match
    masked_image=cv2.bitwise_and(img,mask)
    return masked_image
# cm 환산 함수
# 아두이노 UltraDistSensor 코드에서 가져옴
def distanceInCm(duration):
    # 물체에 도착후 돌아오는 시간 계산
    # 시간 = cm / 음속 * 왕복
    # t   = 0.01/340 * 2= 0.000058824초 (58.824us)

    # 인식까지의 시간
    # t = 0.01/340 = 0.000029412초 (29.412us)

    # duration은 왕복 시간이니 인식까지의 시간에서 2로 나눔
    return (duration/2)/29.1

# 거리 표시
def print_distance(distance):
    if distance == 0:
        distanceMsg = 'Distance : out of range                   \r'
    else:
        distanceMsg = 'Distance : ' + str(distance) + 'cm' + '        \r'
    sys.stdout.write(distanceMsg)
    sys.stdout.flush()
     
#initialize the camera and grab a reference to the raw camera capture
camera=PiCamera()
camera.resolution=(640,480)
camera.framerate=32
rawCapture=PiRGBArray(camera, size=(640,480))
FRAME_SHAPE=(640,480)
#allow the camera to warmup
time.sleep(0.1)

cam_calibration = get_camera_calibration()
cam_calibrator = CameraCalibrator(FRAME_SHAPE, cam_calibration)

motor=18
#GPIO 핀
TRIG = 23 # 트리거
ECHO = 24 # 에코

#거리 타임 아웃 용
MAX_DISTANCE_CM = 300
MAX_DURATION_TIMEOUT = (MAX_DISTANCE_CM * 2 * 29.1) #17460 # 17460us = 300cm

#GPIO.setmode(GPIO.BCM)
#GPIO.setup(motor,GPIO.OUT)
#GPIO.output(motor,GPIO.LOW)

#capture frames from the camera
for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
	#grabe the raw NumPy array representing the image, then initialize the timestamp
	#and occupied/unoccupied text
        image=frame.array
        img=cv2.GaussianBlur(image,(5,5),0)
        hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
        low=np.array([100,25,30]) #127 12 30
        up=np.array([150,60,200]) #156 76 250
        low2=np.array([25,6,100]) #50 6 100
        up2=np.array([100,25,200]) #100 18 200
        kernelOpen=np.ones((5,5))
        kernelClose=np.ones((20,20))
        mask=cv2.inRange(hsv,low,up)
        mask2=cv2.inRange(hsv,low2,up2)
        maskOpen=cv2.morphologyEx(mask2,cv2.MORPH_OPEN,kernelOpen)
        maskClose=cv2.morphologyEx(maskOpen,cv2.MORPH_CLOSE,kernelClose)
        maskFinal=maskClose
    
        edges=cv2.Canny(mask,150,255)
        edges2=cv2.Canny(maskFinal,150,255)
        region_of_interest_vertices=[(0.1*image.shape[1],image.shape[0]),(0.1*image.shape[1],0.6*image.shape[0]),(0.9*image.shape[1],0.6*image.shape[0]),(0.9*image.shape[1],image.shape[0])] #(128,480),(128,384),(512,384),(512,480)
        cropped_edges=region_of_interest(edges,np.array([region_of_interest_vertices],np.int32),)
        region_of_interest_vertices2=[(0.4*image.shape[1],image.shape[0]),(0.4*image.shape[1],0.9*image.shape[0]),(0.6*image.shape[1],0.9*image.shape[0]),(0.6*image.shape[1],image.shape[0])]
        cropped_edges2=region_of_interest(edges2,np.array([region_of_interest_vertices2],np.int32),)
        mean_edges=np.average(edges2)
        if mean_edges<0.2:
            cv2.putText(image,'road',(400,420),fontFace=16, fontScale=1, color=(255,255,255), thickness=1)
        else:
            cv2.putText(image,'sidewalk',(400,420),fontFace=16, fontScale=1, color=(255,255,255), thickness=1)
        
        
        cv2.rectangle(image, (int(0.4*image.shape[1]),int(image.shape[0])), (int(0.6*image.shape[1]),int(0.9*image.shape[0])), (0, 255, 0), 1);
                
        #_,conts,h=cv2.findContours(maskFinal.copy(),cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
        #cv2.drawContours(image,conts,-1,(255,0,0),3)
	# Hough Transform
        #rho = distance resolution in pixels of the Hough grid
        #theta = angular resolution in radians of the Hough grid
        #threshold = minimum number of votes (intersections in Hough grid cell)
        #minLineLength = minimum number of pixels making up a line
        #maxLineGap = maximum gap in pixels between connectable line segments
        lines = cv2.HoughLinesP(cropped_edges, 2, 1*np.pi/180, 100, np.array([]), minLineLength=100, maxLineGap=200)
        draw_line=True
        if lines is not None:
            #find slopes of all lines
            slopes=[]
            new_lines=[]
            for line in lines:
                x1,y1,x2,y2=line[0]
                #calculate slope
                if x2-x1==0.: #corner case, avoiding division by 0
                    slope=999. #practically infinite slope
                else:
                    slope=(y2-y1)/(x2-x1)
                #Filter lines based on slope
                slopes.append(slope)
                new_lines.append(line)
            lines=new_lines
            real_lines=[]
            for i, line in enumerate(lines):
                x1,y1,x2,y2=line[0]
                real_lines.append(line)
            real_lines_x=[]
            real_lines_y=[]
            
            for line in real_lines:
                x1,y1,x2,y2=line[0]
                
                real_lines_x.append(x1)
                real_lines_x.append(x2)
                
                real_lines_y.append(y1)
                real_lines_y.append(y2)
            if len(real_lines_x)>0:
                real_m,real_b=np.polyfit(real_lines_x,real_lines_y,1)
            else:
                real_m,real_b=1,1
                draw_line=False
            #Find 2 end points for lines, used for drawing the line
            y1=img.shape[0]
            y2=img.shape[0]*(1-0.7)#trap_height=0.7
            
            real_x1=(y1-real_b)/real_m
            real_x2=(y2-real_b)/real_m
            
            #Convert calcuated end points from float to int
            y1=int(y1)
            y2=int(y2)
            real_x1=int(real_x1)
            real_x2=int(real_x2)
            
            #Draw the lines on image
            cv2.line(image,(real_x1,y1),(real_x2,y2),(0,0,255),20)
            #GPIO.output(motor,GPIO.HIGH)
            cv2.putText(image,'Curb',(400,450),fontFace=16, fontScale=1, color=(255,255,255), thickness=1)
            time.sleep(0.1)
            #GPIO.output(motor,GPIO.LOW)
            sendMessageTo1('CC:FA:00:78:57:4B')
            #CC:FA:00:78:57:4B A4:EB:D3:F3:D5:56

	#show the frame
        cv2.imshow("Frame",image)
        #cv2.imshow("Edges",cropped_edges2)
        #cv2.imshow("Edges",edges)
        key=cv2.waitKey(1)&0xFF

	#clear the stream in preparation for the next frame
        rawCapture.truncate(0)

	#if the 'q'key was pressed, break from the loop
        if key==ord("q"):
                break
	# 파이썬 GPIO 모드
        GPIO.setmode(GPIO.BCM)

        # 핀 설정
        GPIO.setup(TRIG, GPIO.OUT) # 트리거 출력
        GPIO.setup(ECHO, GPIO.IN)  # 에코 입력

        # HC-SR04 시작 전 잠시 대기
        GPIO.output(TRIG, False)
        time.sleep(1) # 1초

        #171206 중간에 통신 안되는 문제 개선용      
        fail = False
        time.sleep(0.1)
        # 트리거를 10us 동안 High 했다가 Low로 함.
        # sleep 0.00001 = 10us
        GPIO.output(TRIG, True)
        time.sleep(0.00001)
        GPIO.output(TRIG, False)

        # ECHO로 신호가 들어 올때까지 대기
        timeout = time.time()
        while GPIO.input(ECHO) == 0:
            #들어왔으면 시작 시간을 변수에 저장
            pulse_start = time.time()
            if ((pulse_start - timeout)*1000000) >= MAX_DURATION_TIMEOUT:
                #171206 중간에 통신 안되는 문제 개선용        
                #continue
                fail = True
                break
                
        #171206 중간에 통신 안되는 문제 개선용        
        if fail:
            continue
        #ECHO로 인식 종료 시점까지 대기
        timeout = time.time()
        while GPIO.input(ECHO) == 1:
            #종료 시간 변수에 저장
            pulse_end = time.time()
            if ((pulse_end - pulse_start)*1000000) >= MAX_DURATION_TIMEOUT:
                print_distance(0) 
                #171206 중간에 통신 안되는 문제 개선용        
                #continue
                fail = True
                break

        #171206 중간에 통신 안되는 문제 개선용        
        if fail:
            continue

        #인식 시작부터 종료까지의 차가 바로 거리 인식 시간
        pulse_duration = (pulse_end - pulse_start) * 1000000

        # 시간을 cm로 환산
        distance = distanceInCm(pulse_duration)
        #print(pulse_duration)
        #print('')
        # 자리수 반올림
        distance = round(distance, 2)

        #표시
        print_distance(distance)
        if distance<60:
            sendMessageTo2('CC:FA:00:78:57:4B')
            print('sendMessage\n')
            #cv2.putText(image,'Object',(400,390),fontFace=16, fontScale=1, color=(255,255,255), thickness=1)
            #cv2.putText(image,'(%f)cm'%distance,(400,420),fontFace=16, fontScale=1, color=(255,255,255), thickness=1)

        GPIO.cleanup()

