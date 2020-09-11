//c going up from 0 to c
//Bounded knapsack : object number is bounded
//0-1 knapsack : object number is only one
//->m[i,c] = if wi>c, m[i-1,c](this is 0-1, so no improvement) else wi<=c,max[m[i-1,c],vi(new value)+m[i-1,c-wi(place for new value)]]
//unbounded knapsack : object number is unbounded 
//->m[c](the best case by c)=max[vi(ith value)+m[c-wi]], wi(ith weight)<=c(maximum weight)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_PRODUCT 3

struct product {
	int value;
	int weight;
};

struct product products[NUM_OF_PRODUCT];

void initProducts() {
	products[0].value = 1;
	products[0].weight = 1;

	products[1].value = 3;
	products[1].weight = 2;

	products[2].value = 5;
	products[2].weight = 3;
}

//int* initKnapsackTable(int _c) {
//	int* t = (int*)malloc(sizeof(int)*(_c + 1));
//	memset(t, 0, sizeof(int)*(_c + 1)); //(void* ptr, int value, size_t num)
//	return t;
//}

int** initKnapsackTable(int _numP, int _c) { //storing column first and then row.
	int** _m = (int**)malloc(sizeof(int*)*(_numP + 1)); //+1 is for 0,0.
	for (int i = 0;i <= _numP;i++) {
		_m[i] = (int*)malloc(sizeof(int)*(_c + 1));
		memset(_m[i], 0, sizeof(int)*(_c + 1));
	}
	return _m;
}

//int findMaximumValue(int* _m, int _c) { //table, maximum weight
//	int _maxValue = 0;
//	for (int i = 0;i < NUM_OF_PRODUCT; i++) {
//		if (products[i].weight <= _c) {
//			int newValue = products[i].value + _m[_c - products[i].weight];
//			if (newValue > _maxValue) {
//				_maxValue = newValue;
//			}
//		}
//	}
//	if (_maxValue == 0) { //object weights are too heavy to put maxValue.
//		_maxValue = _m[_c - 1];
//	}
//	return _maxValue;
//}

int findMaximumValue(int** _m, int _r, int _c) {
	int _maxValue = 0;
	for (int i = 0;i < NUM_OF_PRODUCT;i++) {
		for (_c = 0;i < NUM_OF_PRODUCT;_c++) {
			if (products[i].weight <= _c) {
				if (_m[i - 1][_c] < products[i].value + _m[i - 1][_c - products[i].weight]) {
					_m[i][_c] = products[i].value + _m[i - 1][_c - products[i].weight];
				}
				else {
					_m[i][_c] = _m[i - 1][_c];
				}
			}
			else {
				_m[i][_c] = _m[i - 1][_c];
			}
		}
	}
	if (_maxValue == 0) { //object weights are too heavy to put maxValue.
		_maxValue = _m[_r][_c];
	}
	return _maxValue;
}

int main(void) {
	int capacity = 10;  //maximum weight
	int** m = 0;

	initProducts();

	m = initKnapsackTable(NUM_OF_PRODUCT, capacity);

	for (int r = 0;r <= NUM_OF_PRODUCT;r++) {
		for (int c = 0;c <= capacity;c++) {
			if (r == 0 || c == 0) {
				m[r][c] = 0;
				continue;
			}
			m[r][c] = findMaximumValue(m, r, c);
		}
	}
	printf("the best value:%d\n", m[NUM_OF_PRODUCT][capacity]);
	free(m);

	return 0;
}