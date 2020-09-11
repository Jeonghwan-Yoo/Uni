//c going up from 0 to c
//Bounded knapsack : object number is bounded
//0-1 knapsack : object number is only one
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

int* initKnapsackTable(int _c) {
	int* t = (int*)malloc(sizeof(int)*(_c + 1));
	memset(t, 0, sizeof(int)*(_c + 1)); //(void* ptr, int value, size_t num)
	return t;
}

int findMaximumValue(int* _m, int _c) { //table, maximum weight
	int _maxValue = 0;
	for (int i = 0;i < NUM_OF_PRODUCT; i++) {
		if (products[i].weight <= _c) {
			int newValue = products[i].value + _m[_c - products[i].weight];
			if (newValue > _maxValue) {
				_maxValue = newValue;
			}
		}
	}
	if (_maxValue == 0) { //object weights are too heavy to put maxValue.
		_maxValue = _m[_c - 1];
	}
	return _maxValue;
}

int main(void) {
	int c = 10;  //maximum weight
	int* m = 0;

	initProducts();

	m = initKnapsackTable(c);

	m[0] = 0;
	for (int i = 1;i <= c;i++) {
		m[i] = findMaximumValue(m, i); //m[i]=???
	}

	printf("max value:%d\n", m[c]);
	free(m);

	return 0;

}