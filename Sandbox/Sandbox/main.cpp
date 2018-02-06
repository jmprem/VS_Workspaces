#include "Utils.h"

#include <iostream>

using namespace std;

extern void printHello();
extern bool isJumpingNumber(unsigned int num);
extern bool checkSubArrayWithSum(int arr[], int arrSize, int sum, int &start, int &end);

#define MAX_SIZE    100

int main() {
	//code
	int numTestcases = 0;
	int *vals[MAX_SIZE];
	int numVals[MAX_SIZE];
	int sum[MAX_SIZE];
	cin >> numTestcases;
	//assert(numTestcases < MAX_SIZE);
	for (int i = 0; i<numTestcases; i++)
	{
		cin >> numVals[i] >> sum[i];
		vals[i] = new int[numVals[i]];
		for (int j = 0; j<numVals[i]; j++)
			cin >> vals[i][j];
	}

	for (int i = 0; i<numTestcases; i++)
	{
		int start = -1, end = -1;
		if (checkSubArrayWithSum(vals[i], numVals[i], sum[i], start, end))
			cout << start + 1 << " " << end + 1 << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}
/*
int main() {
//	printHello();

	unsigned int numInput = 0, numarray[MAX_NUMS];
	cin >> numInput;

	for (unsigned int i=0; i<numInput; i++)
		cin >> numarray[i];

	cout << "numInput = " << numInput << endl;

	for (unsigned int i=0; i<numInput; i++)
	{
		unsigned int num = numarray[i];
		cout << "Checking for outer num = " << num << endl;
		for (unsigned int j = 0; j <= num; j++) {
			bool isJmpNum = isJumpingNumber(j);
//			cout << "Checking for inner num " << j << ", which is " << isJmpNum << endl;
			if(isJmpNum)
				cout << j << " ";
		}
		cout << endl;
	}

	getchar();
	getchar();

	return 0;
}*/