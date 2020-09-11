//�󵵼��� ������ ���������� �켱���� ť�̿�

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

//�󵵼��� �𸣱⶧���� ������ ��.
struct node **heap;
int lastHeapIdx = 0;
char codeBuf[100];
int codeBufIdx = -1;

int charFreq[NUM_ASCII]; //charFreq[97]=10: a�� 10�� ��Ÿ����.
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
	//-e�̸�
	if (strcmp(argv[1], "-e") == 0) {
		//huffman coding
		printf("Start Huffman Encoding\n");
		performEncoding(argv[2]);
	}
	//-d�̸�
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

	//�󵵼��� 1�̻��� ���� ������ ����.
	int cnt = countNonZeroCharacters();
	//�ε��� 0���� �Ⱦ��Ƿ� cnt+1.�� �����Ҵ�
	heap = (struct node**)malloc((cnt + 1) * sizeof(struct node*));
	memset(heap, 0, (cnt + 1) * sizeof(struct node*));

	//Min heap�� �����Ѵ�.
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

	//Huffman tree�� ����
	struct node *first = 0;
	struct node *second = 0;

	while (1) {
		first = deleteFromHeap();
		second = deleteFromHeap();
		//��Ʈ��� �ϳ��� ������ (first) ����.
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

	//symCode�� �ʱ�ȭ
	memset(symCode, 0, sizeof(symCode));

	//first�� Huffman tree�� root��带 ����Ų��.
	traverse(first->left, '0');
	traverse(first->right, '1');

	int numOfSym = 0;

	//symCode�� ����� ���ڿ� �ش��ϴ� �������ڵ带 ����غ���.
	for (int i = 0;i < NUM_ASCII;i++) {
		if (symCode[i] != 0) {
			numOfSym++;
			printf("Symbol %c ==> %s\n", (char)i, symCode[i]);
		}
	}
	printf("Number of Symbols is %d\n", numOfSym);

	//������ ���Ͽ� ����ϴ� ����

	//1.����� �����̸� �����: alice.txt->alice.encoded, fName
	char outputFileName[100];
	char *period = strchr(fName, (int)'.'); //fName���� .�� �ִ� ������
	strncpy(outputFileName, fName, (int)(period - fName)); //�տ������� n���� ���� => outputFileName="alice"
	outputFileName[(int)(period - fName)] = 0; //outputFileName="alice"+\0;
	strcat(outputFileName, ".encoded");

	printf("output file is %s\n", outputFileName);

	FILE *fout = 0;
	fout = fopen(outputFileName, "wb"); //write binary
	if (fout != 0) {
		fwrite(&numOfSym, sizeof(numOfSym), 1, fout); //��ü symbol�� ����
		char writeBuf[100];
		for (int i = 0;i < NUM_ASCII;i++) {
			if (symCode[i] != 0) {
				//����+����+�ڵ�
				writeBuf[0] = (char)i;
				writeBuf[1] = (char)strlen(symCode[i]);
				strcpy(&writeBuf[2], symCode[i]);
				fwrite(writeBuf, sizeof(char), 2 + strlen(symCode[i]), fout);
			}
		}

		//Encoded file contents
		//alice.txt�� �ٽ� ����.
		FILE *fin;
		fin = fopen(fName, "rt");
		if (fin != 0) {
			//��ü ��Ʈ ������ ����� ��ġ�� ����صд�.
			int locTotalNumBit;
			locTotalNumBit = ftell(fout); //���� ������ ũ�⸦ ��´�.

			if (fseek(fout, 4, SEEK_CUR) != 0) { //���� fout�� ������ġ���� 4��ŭ �ڷ� �̵�.
				printf("Failed to move the file pointer\n");
				fclose(fin);
				fclose(fout);
				return;
			}

			char bitBuf[BUF_SZ]; //�����Ǵ� ��Ʈ��Ʈ���� ������ ����
			int bitBufIdx = 0; //���� ��Ʈ��Ʈ���� �����ϴ� ��ġ
			int bitShiftCnt = 7; //��Ʈ����Ʈ Ƚ��
			int totalBitNum = 0;
			char flag = 0; //0:����� ���� ����, 1:����� ���� ����.

			//bitBuf�� ��� 0���� �ʱ�ȭ
			memset(bitBuf, 0, BUF_SZ);

			//������ ������ �о encoding
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

			if (fseek(fout, locTotalNumBit, SEEK_SET) == 0) { //����ó������ ��ġ����
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

	//ã�� ��,
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

	//ã�� ��,
	if (cur->left == 0 && cur->right == 0) {
		//printf("character %d (%c):%s\n", (int)cur->c, cur->c, codeBuf);
		//symCode�� �ɺ�(cur->c)�� �ش��ϴ� HuffamCode(codeBuf) ����
		char *hufCode = (char*)malloc(strlen(codeBuf) + 1); //null������ +1
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

//heap���� root�� ������.
struct node* deleteFromHeap(void) {
	if (lastHeapIdx <= 0) {
		printf("Heap is empty\n");
		return 0;
	}
	struct node *retVal = heap[1];
	//�ٽ� �������ϴ� �ܰ�.
	heap[1] = heap[lastHeapIdx];
	lastHeapIdx--;

	int parent = 1;
	int left = 2 * parent;
	int right = left + 1;

	while (1) {
		//���Ұ� ���� ��, �ڽ��� ������
		if (left > lastHeapIdx) {
			break;
		}
		//�����ڽĸ� ������ �ִ�.
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
		//�ڽ��� �� ���� ��,
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

//heap�� ���ο� ��带 �߰��Ѵ�.
void addToHeap(struct node *cur) {
	lastHeapIdx++;
	heap[lastHeapIdx] = cur;

	int currentIdx = lastHeapIdx;
	int parentIdx = currentIdx / 2;

	while (parentIdx >= 1) {
		if (heap[parentIdx]->frequency > heap[currentIdx]->frequency) {
			//�θ�� ���� �ٲ�� �ȴ�.
			//���� ���� �ٲٰ� �ε����� �ٲ��ش�.
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

//�����󵵼��� 1�̻��� ���ڵ��� �� ������ ����.
int countNonZeroCharacters() {
	int cnt = 0;
	for (int i = 0;i < NUM_ASCII;i++) {
		//�󵵼� 1�̻��� �͸� ����.
		if (charFreq[i] > 0) {
			cnt++;
		}
	}
	return cnt;
}

void showCharFrequency(void) {
	//charFreq
	for (int i = 0;i < NUM_ASCII;i++) {
		//�󵵼� 1�̻��� �͸� ���
		if (charFreq[i] > 0) {
			printf("ACSII code %d (%c):%d\n", i, (char)i, charFreq[i]);
		}
	}
}

void performDecoding(char *fName) { //alice.encode->alice.decoded<==>(alice.txt)
	FILE* fin = 0;
	fin = fopen(fName, "rb");
	if (fin != 0) {
		//������ Ʈ�� �籸��
		int numOfSym = 0;
		fread(&numOfSym, sizeof(int), 1, fin);
		printf("Number of symbols is %d\n", numOfSym);

		struct node *huffRoot = (struct node*)malloc(sizeof(struct node));
		huffRoot->left = huffRoot->right = 0;
		struct node *cur = huffRoot;

		for (int i = 0;i < numOfSym;i++) {
			char symbolAndLen[2]; //0:symbol, 1:����
			fread(symbolAndLen, 2, 1, fin);
			char buf[100];
			fread(buf, 1, (int)symbolAndLen[1], fin); //������ �ڵ带 �о�´�.
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
		} //������Ʈ�� ���� �Ϸ�

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

		//���ڵ� ����
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
					for (int j = 0;j < 8;j++) { //����Ʈ�� 8���� ��Ʈ�� �����Ǿ� �ֱ� ������
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