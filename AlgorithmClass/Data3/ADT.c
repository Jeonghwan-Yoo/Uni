typedef struct { //making struct call YYY.
	int a;
	float c;
	char k[10];
} YYY;

//or

struct abc { //making struct abc.
	int a;
	float c;
	char k[10];
};
typedef struct abc YYY; //and abc is called by YYY as well.

int main(void) {
	YYY x;
	YYY y, z;
	return 0;
}
