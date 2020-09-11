//빈도수가 적은게 먼저나오게 우선순위 큐이용

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define BUF_SZ 100
#define NUM_ASCII 256

struct node {
	char c;
	int frequency;
	struct node *left;
	struct node *right;
};

//빈도수를 모르기때문에 개수를 모름.
struct node **heap;
int lastHeapIdx = 0;
char codeBuf[100];
int codeBufIdx = -1;

int charFreq[NUM_ASCII]; //charFreq[97]=10: a가 10번 나타난다.
char *symCode[NUM_ASCII];

/*------------------------------------------------*/

//Function Forward Declaration.
void performEncoding(char *fName);
void performDecoding(char *fName);
void showCharFrequency(void);
int countNonZeroCharacters();
void addToHeap(struct node *cur);
struct node* deleteFromHeap(void);
void traverse(struct node* cur, char c);
void justTraverse(struct node* cur, char c);



//argc:argument count
//ex) huff.exe -e alice.txt =>argc=3
//argv:argument variable
//argv[0]="huff.exe",argv[1]="-e",argv[2]="alice.txt".
int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Usage:huff.exe -e fileToEncode\n");
		printf("      huff.exe -d fileToDecode\n");
		return -1;
	}
	//-e이면
	if (strcmp(argv[1], "-e") == 0) {
		//huffman coding
		printf("Start Huffman Encoding\n");
		performEncoding(argv[2]);
	}
	//-d이면
	else if (strcmp(argv[1], "-d") == 0) {
		//decoding
		printf("Start Huffman Decoding\n");
		performDecoding(argv[2]); //alice.encoded

	}
	else {
		printf("Usage:huff.exe -e fileToEncode\n");
		printf("      huff.exe -d fileToDecode\n");
		return -1;
	}
	return 0;
}

void performEncoding(char *fName) { //alice.txt->alice.encoded
	//fopen, fread, fclose
	FILE *fin;
	char buf[BUF_SZ];

	//rt=read text
	fin = fopen(fName, "rt");
	if (fin == 0) {
		printf("Unable to open %s.Program terminated\n", fName);
		return;
	}

	memset(charFreq, 0, NUM_ASCII * sizeof(int)); //set charFreq as zero

	while (fgets(buf, BUF_SZ, fin) != 0) {
		int len = strlen(buf);
		for (int i = 0;i < len;i++) {
			charFreq[(int)buf[i]]++;
		}
	}
	fclose(fin);

	//showCharFrequency();

	//빈도수가 1이상인 것의 개수를 센다.
	int cnt = countNonZeroCharacters();
	//인덱스 0번은 안쓰므로 cnt+1.로 동적할당
	heap = (struct node**)malloc((cnt + 1) * sizeof(struct node*));
	memset(heap, 0, (cnt + 1) * sizeof(struct node*));

	//Min heap을 구성한다.
	for (int i = 0;i < NUM_ASCII;i++) {
		if (charFreq[i] > 0) {
			struct node *cur = (struct node *)malloc(sizeof(struct node));
			cur->c = (char)i;
			cur->frequency = charFreq[i];
			cur->left = cur->right = 0;
			addToHeap(cur);
		}
	}
	//struct node *temp = deleteFromHeap();
	//printf("previous root %d (%c):%d\n", (int)temp->c, temp->c, temp->frequency);
	//printf("root %d (%c):%d\n", (int)heap[1]->c, heap[1]->c, heap[1]->frequency);

	//Huffman tree를 구성
	struct node *first = 0;
	struct node *second = 0;

	while (1) {
		first = deleteFromHeap();
		second = deleteFromHeap();
		//루트노드 하나만 남을때 (first) 끝남.
		if (second == 0) {
			printf("Huffman tree building ended\n");
			break;
		}
		struct node *newOne = (struct node*)malloc(sizeof(struct node));
		newOne->c = 0;
		newOne->frequency = first->frequency + second->frequency;
		newOne->left = first;
		newOne->right = second;

		addToHeap(newOne);
	}

	//symCode를 초기화
	memset(symCode, 0, sizeof(symCode));

	//first는 Huffman tree의 root노드를 가리킨다.
	traverse(first->left, '0');
	traverse(first->right, '1');

	int numOfSym = 0;

	//symCode에 저장된 문자와 해당하는 허프만코드를 출력해본다.
	for (int i = 0;i < NUM_ASCII;i++) {
		if (symCode[i] != 0) {
			numOfSym++;
			printf("Symbol %c ==> %s\n", (char)i, symCode[i]);
		}
	}
	printf("Number of Symbols is %d\n", numOfSym);

	//실제로 파일에 기록하는 과정

	//1.기록할 파일이름 만들기: alice.txt->alice.encoded, fName
	char outputFileName[100];
	char *period = strchr(fName, (int)'.'); //fName에서 .이 있는 포인터
	strncpy(outputFileName, fName, (int)(period - fName)); //앞에서부터 n개를 복사 => outputFileName="alice"
	outputFileName[(int)(period - fName)] = 0; //outputFileName="alice"+\0;
	strcat(outputFileName, ".encoded");

	printf("output file is %s\n", outputFileName);

	FILE *fout = 0;
	fout = fopen(outputFileName, "wb"); //write binary
	if (fout != 0) {
		fwrite(&numOfSym, sizeof(numOfSym), 1, fout); //전체 symbol의 개수
		char writeBuf[100];
		for (int i = 0;i < NUM_ASCII;i++) {
			if (symCode[i] != 0) {
				//문자+길이+코드
				writeBuf[0] = (char)i;
				writeBuf[1] = (char)strlen(symCode[i]);
				strcpy(&writeBuf[2], symCode[i]);
				fwrite(writeBuf, sizeof(char), 2 + strlen(symCode[i]), fout);
			}
		}

		//Encoded file contents
		//alice.txt를 다시 연다.
		FILE *fin;
		fin = fopen(fName, "rt");
		if (fin != 0) {
			//전체 비트 개수를 기록할 위치를 기억해둔다.
			int locTotalNumBit;
			locTotalNumBit = ftell(fout); //현재 파일의 크기를 얻는다.

			if (fseek(fout, 4, SEEK_CUR) != 0) { //파일 fout의 현재위치에서 4만큼 뒤로 이동.
				printf("Failed to move the file pointer\n");
				fclose(fin);
				fclose(fout);
				return;
			}

			char bitBuf[BUF_SZ]; //생성되는 비트스트림을 저장할 버퍼
			int bitBufIdx = 0; //현재 비트스트림을 저장하는 위치
			int bitShiftCnt = 7; //비트쉬프트 횟수
			int totalBitNum = 0;
			char flag = 0; //0:기록할 것이 없음, 1:기록할 것이 있음.

			//bitBuf를 모두 0으로 초기화
			memset(bitBuf, 0, BUF_SZ);

			//실제로 파일을 읽어서 encoding
			while (fgets(buf, BUF_SZ, fin) != 0) {
				int len = strlen(buf);
				for (int i = 0;i < len;i++) {
					char *huffmanCode = symCode[(int)buf[i]];
					for (int j = 0;j < strlen(huffmanCode);j++) {
						char val = 0;
						if (huffmanCode[j] == '0') {
							val = 0;
						}
						else if (huffmanCode[j] == '1') {
							val = 1;
						}
						else {
							printf("--------- CRITICAL ERROR : INVALID HUFFMAN CODE ------\n");
						}
						val = val << bitShiftCnt;
						bitShiftCnt--;

						bitBuf[bitBufIdx] |= val;
						flag = 1;

						totalBitNum++;
						if (bitShiftCnt < 0) {
							bitShiftCnt = 7;
							bitBufIdx++;
							if (bitBufIdx >= BUF_SZ) {
								fwrite(bitBuf, 1, BUF_SZ, fout);
								flag = 0;
								bitBufIdx = 0;
								memset(bitBuf, 0, BUF_SZ);
							}
						}
					}
				}
			}
			if (flag == 1) {
				fwrite(bitBuf, 1, bitBufIdx + 1, fout);
			}

			if (fseek(fout, locTotalNumBit, SEEK_SET) == 0) { //파일처음부터 위치까지
				fwrite(&totalBitNum, sizeof(totalBitNum), 1, fout);
			}
			else {
				printf("Unable to record total number of bit\n");
			}
			fclose(fin);
		}
		else {
			printf("Unable to open %s\n", fName);
		}
		fclose(fout);
	}
	else {
		printf("error:unable to open %s\n", outputFileName);
	}
}

void justTraverse(struct node* cur, char c) {
	codeBufIdx++;
	codeBuf[codeBufIdx] = c;
	codeBuf[codeBufIdx + 1] = 0;

	//찾을 때,
	if (cur->left == 0 && cur->right == 0) {
		printf("character %d (%c):%s\n", (int)cur->c, cur->c, codeBuf);
	}
	else {
		justTraverse(cur->left, '0');
		justTraverse(cur->right, '1');
	}
	codeBuf[codeBufIdx] = 0;
	codeBufIdx--;
	return;
}

void traverse(struct node* cur, char c) {
	codeBufIdx++;
	codeBuf[codeBufIdx] = c;
	codeBuf[codeBufIdx + 1] = 0;

	//찾을 때,
	if (cur->left == 0 && cur->right == 0) {
		//printf("character %d (%c):%s\n", (int)cur->c, cur->c, codeBuf);
		//symCode에 심볼(cur->c)에 해당하는 HuffamCode(codeBuf) 저장
		char *hufCode = (char*)malloc(strlen(codeBuf) + 1); //null떄문에 +1
		strcpy(hufCode, codeBuf);
		symCode[(int)cur->c] = hufCode;
	}
	else {
		traverse(cur->left, '0');
		traverse(cur->right, '1');
	}
	codeBuf[codeBufIdx] = 0;
	codeBufIdx--;
	return;
}

//heap에서 root를 꺼낸다.
struct node* deleteFromHeap(void) {
	if (lastHeapIdx <= 0) {
		printf("Heap is empty\n");
		return 0;
	}
	struct node *retVal = heap[1];
	//다시 재정렬하는 단계.
	heap[1] = heap[lastHeapIdx];
	lastHeapIdx--;

	int parent = 1;
	int left = 2 * parent;
	int right = left + 1;

	while (1) {
		//비교할게 없을 떄, 자식이 없을때
		if (left > lastHeapIdx) {
			break;
		}
		//왼쪽자식만 가지고 있다.
		else if (right > lastHeapIdx) {
			if (heap[left]->frequency < heap[parent]->frequency) {
				struct node *temp = heap[left];
				heap[left] = heap[parent];
				heap[parent] = temp;

				parent = left;
				left = 2 * parent;
				right = left + 1;
			}
			else {
				break;
			}
		}
		//자식이 둘 있을 때,
		else {
			int smaller;
			if (heap[left]->frequency <= heap[right]->frequency) {
				smaller = left;
			}
			else {
				smaller = right;
			}
			if (heap[smaller]->frequency < heap[parent]->frequency) {
				struct node *temp = heap[smaller];
				heap[smaller] = heap[parent];
				heap[parent] = temp;

				parent = smaller; /////////////////////left or smaller???
				left = 2 * parent;
				right = left + 1;
			}
			else {
				break;
			}
		}
	}
	return retVal;
}

//heap에 새로운 노드를 추가한다.
void addToHeap(struct node *cur) {
	lastHeapIdx++;
	heap[lastHeapIdx] = cur;

	int currentIdx = lastHeapIdx;
	int parentIdx = currentIdx / 2;

	while (parentIdx >= 1) {
		if (heap[parentIdx]->frequency > heap[currentIdx]->frequency) {
			//부모와 나를 바꿔야 된다.
			//값을 먼저 바꾸고 인덱스를 바꿔준다.
			struct node *temp = heap[parentIdx];
			heap[parentIdx] = heap[currentIdx];
			heap[currentIdx] = temp;

			currentIdx = parentIdx;
			parentIdx = currentIdx / 2;
		}
		else {
			break;
		}
	}
}

//출현빈도수가 1이상인 문자들의 총 개수를 센다.
int countNonZeroCharacters() {
	int cnt = 0;
	for (int i = 0;i < NUM_ASCII;i++) {
		//빈도수 1이상인 것만 센다.
		if (charFreq[i] > 0) {
			cnt++;
		}
	}
	return cnt;
}

void showCharFrequency(void) {
	//charFreq
	for (int i = 0;i < NUM_ASCII;i++) {
		//빈도수 1이상인 것만 출력
		if (charFreq[i] > 0) {
			printf("ACSII code %d (%c):%d\n", i, (char)i, charFreq[i]);
		}
	}
}

void performDecoding(char *fName) { //alice.encode->alice.decoded<==>(alice.txt)
	FILE* fin = 0;
	fin = fopen(fName, "rb");
	if (fin != 0) {
		//허프만 트리 재구성
		int numOfSym = 0;
		fread(&numOfSym, sizeof(int), 1, fin);
		printf("Number of symbols is %d\n", numOfSym);

		struct node *huffRoot = (struct node*)malloc(sizeof(struct node));
		huffRoot->left = huffRoot->right = 0;
		struct node *cur = huffRoot;

		for (int i = 0;i < numOfSym;i++) {
			char symbolAndLen[2]; //0:symbol, 1:길이
			fread(symbolAndLen, 2, 1, fin);
			char buf[100];
			fread(buf, 1, (int)symbolAndLen[1], fin); //허프만 코드를 읽어온다.
			buf[(int)symbolAndLen[1]] = 0;
			printf("%c (%d) ==> %s\n", symbolAndLen[0], (int)symbolAndLen[1], buf);

			cur = huffRoot;
			for (int i = 0;i < (int)symbolAndLen[1];i++) {
				if (buf[i] == '0') {
					if (cur->left == 0) {
						cur->left = (struct node*)malloc(sizeof(struct node));
						cur->left->left = 0;
						cur->left->right = 0;
					}
					cur = cur->left;
				}
				else if (buf[i] == '1') {
					if (cur->right == 0) {
						cur->right = (struct node*)malloc(sizeof(struct node));
						cur->right->left = 0;
						cur->right->right = 0;
					}
					cur = cur->right;
				}
				else {
					printf("-------- CRITICAL ERROR -------\n");
					exit(0);
				}
			}
			cur->c = symbolAndLen[0];
		} //허프만트리 복구 완료

		//codeBuf[]
		//codeBufIdx = -1;
		//justTraverse(huffRoot->left, '0');
		//justTraverse(huffRoot->right, '1');

		FILE* decodedFile;
		char decodedFName[100];
		char *period = strchr(fName, (int)'.');
		strncpy(decodedFName, fName, (int)(period - fName));
		decodedFName[(int)(period - fName)] = 0;
		strcat(decodedFName, ".decoded");
		printf("Decoded file name is %s\n", decodedFName);

		decodedFile = fopen(decodedFName, "wt");
		if (decodedFile == 0) {
			printf("Unable to create the file %s\n", decodedFName);
			exit(0);
		}

		//디코딩 수행
		int numBitsToRead = 0;
		fread(&numBitsToRead, sizeof(int), 1, fin);
		printf("Total number of bits to read is %d\n", numBitsToRead);

		cur = huffRoot;
		char buf[BUF_SZ];
		while (1) {
			int sz = fread(buf, 1, BUF_SZ, fin);
			if (sz == 0) {
				printf("End of file reached.\n");
				break;
			}
			else {
				for (int i = 0;i < sz;i++) {
					for (int j = 0;j < 8;j++) { //바이트가 8개의 비트로 구성되어 있기 때문에
						if ((char)(buf[i] & 0x80) == 0) {
							cur = cur->left;
						}
						else { //1
							cur = cur->right;
						}
						buf[i] = buf[i] << 1;
						numBitsToRead--;

						if (cur->left == 0 && cur->right == 0) {
							//printf("%c", cur->c);
							fputc(cur->c, decodedFile);
							cur = huffRoot;
						}
						if (numBitsToRead == 0) {
							printf("\n===== End of decoding ======\n");
							fclose(decodedFile);
							fclose(fin);
							return;
						}
					}
				}
			}
		}
		fclose(fin);
	}
	else {
		printf("Unable to open %s\n", fName);
		return;
	}
}