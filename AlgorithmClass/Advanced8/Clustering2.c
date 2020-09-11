//Clustering
//How to classify the samples?? ex)size, sweetness level...
//PCA(principle component analysis) deleting unnecessary standard.
//How to decide the K(group number)?
//The most distance samples in each group are the centers of the groups.
//depending on which sameple chosen first.
//Even k=3 problem is same. Simple idea is the maximum of the closest point between x1 and x2.
//the moment when ths graph is slowly decreasing. Like k is equal to 5 or 6 is the best moment.

//k-means clustering is for random header. And the header keep chaning to be the best. This used for machine learning.
//k-means clustering is for analyzing words and standard face of the country.
//The more it is doing, the better?..
//The weak point is we have to put the numbers of cluster header.
//At the first, we should decide the random k value.
//array > SLL(in view of the speed, safety). sometimes malloc failed from memory and link dropped.
//array is sequential and SLL is not.

#include <stdio.h>
#include <stdlib.h>

#define SZ 100

void initData(void); //forward declaration

struct idxNode { //SLL
	int nodeNum;
	struct idxNode *next;
};

struct idxNode *head = 0;

struct point { //Coordinate.
	int x;
	int y;
	int ch; //cluster head;
};

struct point points[SZ];

int idx = 0;
//the space for cluster headers whose number is 3.
struct point clusterHeads[3];

int firstClusterHead = 27; //first index.

int calcDistance(int x1, int y1, int x2, int y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

//Saving cluster head's index in SLL
void addToSLL(int _idx) {
	struct idxNode *new_one = (struct idxNode *)malloc(sizeof(struct idxNode));
	new_one->nodeNum = _idx;
	new_one->next = 0;

	if (head == 0) {
		head = new_one;
		return;
	}
	struct idxNode *temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}
	temp->next = new_one;
}

//return cluster secondary index.
//_first is the first cluster index.
int findSecondClusterHead(int _first) {
	int mostDistantPointIndex = -1; //
	int mostDistantDistance = 0;
	int fx = points[_first].x; //value of x
	int fy = points[_first].y; //value of y
	for (int i = 0;i < SZ;i++) {
		int x = points[i].x;
		int y = points[i].y;
		int dist = (fx - x)*(fx - x) + (fy - y)*(fy - y); //square of distance 
		if (dist > mostDistantDistance) {
			mostDistantDistance = dist;
			mostDistantPointIndex = i;
		}
	}
	return mostDistantPointIndex;
}




void addPoint(int x, int y) {
	points[idx].x = x;
	points[idx].y = y;
	points[idx].ch = -1;

	idx++;
}

//we have to make SLL containing header index.
//and we need to make searching distance.
//inspecting idx is cluster head or not
//return 1, if yes otherwise 0.
int amIClusterHead(int idx) {
	//Judging coincidence of idx in all SLL
	struct idxNode *temp = head;
	while (temp != 0) {
		if (temp->nodeNum == idx) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

//find the nearest cluster header's index and distance.
//i is the point wanted to know
//_cidx is the header's index
//_dist is the header's distance
void findNearestClusterIdxAndDistance(int i, int *_cidx, int *_dist) {
	struct idxNode *temp = head;
	int distance = INT_MAX;
	int cidx = -1;

	while (temp != 0) {
		int d = calcDistance(points[i].x, points[i].y, points[temp->nodeNum].x, points[temp->nodeNum].y);
		if (d < distance) {
			distance = d;
			cidx = temp->nodeNum;
		}
		temp = temp->next;
	}
	*_cidx = cidx;
	*_dist = distance;
}

//returning 가장 작은 값의 거리 값을 
//SLL의 cluster dead들 과의 거리들 중에서 최소인 것을 찾아 그거리를 반환한다.
int findNearestDistanceToClusterHeads(int i) {
	int cidx;
	int distance;
	findNearestClusterIdxAndDistance(i, &cidx, &distance);
	return distance;
}

void findNewClusterHead() {
	int maxDistance = 0;
	int maxDistanceId = -1;
	for (int i = 0;i < SZ;i++) { //for all points.
		if (amIClusterHead(i) == 1) {
			continue;
		}
		int d = findNearestDistanceToClusterHeads(i);
		if (maxDistance < d) {
			maxDistance = d;
			maxDistanceId = i;
		}
	}
	addToSLL(maxDistanceId);
}

void setClusterHead(int idx, int _x, int _y) {
	clusterHeads[idx].x = _x;
	clusterHeads[idx].y = _y;

}

int findNearestClusterHeadIndex(int _x, int _y) {
	int nearestIdx = 0;
	int nearestDistance = calcDistance(_x, _y, clusterHeads[0].x, clusterHeads[0].y);
	for (int i = 0;i < 3;i++) {
		int _d = calcDistance(_x, _y, clusterHeads[i].x, clusterHeads[i].y);
		if (nearestDistance > _d) {
			nearestIdx = i;
			nearestDistance = _d;
		}
	}
	return nearestIdx;
}
void classifyPoints() {
	//for each points, 
	//looking for the nearest cluster headers
	//save the index of the headers.
	for (int i = 0;i < SZ;i++) {
		int cidx = findNearestClusterHeadIndex(points[i].x, points[i].y);
		points[i].ch = cidx;
	}
}
int electNewClusterHeads() {
	int moveDistance = 0;

	for (int ch = 0;ch < 3;ch++) { //for the cluster,
		int sum_x = 0;
		int sum_y = 0;
		int cnt = 0;
		int prev_x = clusterHeads[ch].x;
		int prev_y = clusterHeads[ch].y;

		for (int i = 0;i < SZ;i++) {
			if (points[i].ch == ch) {
				cnt++; //the number of cluster points;
				sum_x += points[i].x;
				sum_y += points[i].y;
			}
		}
		if (cnt == 0) {
			cnt = 1;
		}
		clusterHeads[ch].x = sum_x / cnt;
		clusterHeads[ch].y = sum_y / cnt;
		moveDistance += calcDistance(prev_x, prev_y, clusterHeads[ch].x, clusterHeads[ch].y);
	}
	return moveDistance;
}

void showClusterHeads() {
	for (int i = 0;i < 3;i++) {
		printf("%d: (%d, %d)\n", i, clusterHeads[i].x, clusterHeads[i].y);
	}
}
int main() {

	initData(); //points[100] (x,y) values.
	//case of dense cluster headers.
	setClusterHead(0, 100, 100);
	setClusterHead(1, 101, 101);
	setClusterHead(2, 102, 102);
	showClusterHeads();
	int threshold = 5;
	while (1) {
		//classifying points for distance of cluster headers.
		classifyPoints();

		//make new cluster headers for all cluster groups.
		int moveDistance = electNewClusterHeads();
		if (moveDistance < threshold) {
			break;
		}
		showClusterHeads();
	}
	return 0;
}

void initData(void) {
	addPoint(117, 637);
	addPoint(105, 79);
	addPoint(427, 239);
	addPoint(727, 598);
	addPoint(543, 638);
	addPoint(591, 855);
	addPoint(135, 175);
	addPoint(718, 108);
	addPoint(258, 180);
	addPoint(65, 574);
	addPoint(548, 937);
	addPoint(568, 313);
	addPoint(761, 284);
	addPoint(268, 772);
	addPoint(193, 809);
	addPoint(983, 896);
	addPoint(476, 158);
	addPoint(186, 901);
	addPoint(120, 794);
	addPoint(851, 749);
	addPoint(976, 109);
	addPoint(675, 651);
	addPoint(970, 192);
	addPoint(726, 387);
	addPoint(358, 493);
	addPoint(117, 789);
	addPoint(675, 25);
	addPoint(571, 85);
	addPoint(818, 56);
	addPoint(258, 823);
	addPoint(825, 508);
	addPoint(80, 930);
	addPoint(939, 235);
	addPoint(334, 477);
	addPoint(456, 481);
	addPoint(186, 751);
	addPoint(25, 800);
	addPoint(735, 935);
	addPoint(908, 668);
	addPoint(567, 753);
	addPoint(305, 950);
	addPoint(654, 125);
	addPoint(545, 879);
	addPoint(982, 333);
	addPoint(313, 85);
	addPoint(180, 748);
	addPoint(244, 25);
	addPoint(485, 766);
	addPoint(440, 757);
	addPoint(836, 381);
	addPoint(344, 410);
	addPoint(325, 637);
	addPoint(703, 148);
	addPoint(188, 429);
	addPoint(654, 662);
	addPoint(865, 305);
	addPoint(921, 500);
	addPoint(58, 839);
	addPoint(789, 162);
	addPoint(724, 222);
	addPoint(463, 836);
	addPoint(295, 938);
	addPoint(773, 166);
	addPoint(550, 347);
	addPoint(567, 677);
	addPoint(113, 746);
	addPoint(297, 352);
	addPoint(487, 22);
	addPoint(286, 488);
	addPoint(635, 723);
	addPoint(506, 230);
	addPoint(887, 847);
	addPoint(387, 871);
	addPoint(507, 555);
	addPoint(664, 577);
	addPoint(853, 809);
	addPoint(862, 643);
	addPoint(967, 341);
	addPoint(205, 487);
	addPoint(489, 813);
	addPoint(238, 695);
	addPoint(880, 277);
	addPoint(378, 516);
	addPoint(121, 95);
	addPoint(795, 93);
	addPoint(605, 129);
	addPoint(418, 587);
	addPoint(983, 536);
	addPoint(637, 962);
	addPoint(884, 798);
	addPoint(881, 255);
	addPoint(88, 335);
	addPoint(517, 763);
	addPoint(535, 942);
	addPoint(859, 138);
	addPoint(363, 56);
	addPoint(427, 969);
	addPoint(18, 421);
	addPoint(699, 632);
	addPoint(389, 427);
}
