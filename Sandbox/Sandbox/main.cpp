#include "Utils.h"

#include <iostream>
#include <vector>

using namespace std;

extern void printHello();
extern bool isJumpingNumber(unsigned int num);
extern bool checkSubArrayWithSum(int arr[], int arrSize, int sum, int &start, int &end);

#define MAX_SIZE    100

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*void rotate_by_one(vector<int> &a, int n, int d) {
int size = n;//a.size();

if (size <= 1)
return;

int temp = a[0];
for (int i = 0; i < size - 1; i++)
a[i] = a[i + 1];
a[size-1] = temp;
}

vector<int> array_left_rotation(vector<int> a, int n, int d) {
for (int i = 0; i < d; i++)
rotate_by_one(a, n, d);

return a;
}*/

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

vector<int> array_left_rotation(vector<int> a, int n, int d) {
	int setCount = gcd(n, d);

	for (int i = 0; i<setCount; i++) {
		int j = i;
		int temp = a[j];
		while (1) {
			int k = j + d;
			if (k >= n)
				k = k - n;
			if (k == i)
				break;
			a[j] = a[k];
			j = k;
		}
		a[j] = temp;
	}

	return a;
}

int main() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	vector<int> output = array_left_rotation(a, n, k);
	for (int i = 0; i < n; i++)
		cout << output[i] << " ";
	cout << endl;
	getchar();
	getchar();
	return 0;
}


/*int main() {
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
}*/
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