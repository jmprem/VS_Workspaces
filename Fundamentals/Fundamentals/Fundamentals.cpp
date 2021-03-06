// Fundamentals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <malloc.h>
#include <set>

using namespace std;

void hacker_fn() {
	vector<string> numName;
	numName.push_back("zero");
	numName.push_back("one");
	numName.push_back("two");
	numName.push_back("three");
	numName.push_back("four");
	numName.push_back("five");
	numName.push_back("six");
	numName.push_back("seven");
	numName.push_back("eight");
	numName.push_back("nine");

	int a, b;
	cin >> a;
	cin >> b;

	for (int i = a; i <= b; i++) {
		if (i > 9) {
			if (i % 2)
				cout << "odd" << endl;
			else
				cout << "even" << endl;
		}
		else {
			if (i > 0)
				cout << numName[i] << endl;
		}
	}

	getchar();
	getchar();
}

// Recursive Maximum of given vector of integers
/*
unsigned int findMaxRecursive(vector<unsigned int>& inputVector, unsigned int begin, unsigned int end) {
	if ((end-begin) <= 1)
		return (inputVector[begin] > inputVector[end]) ? inputVector[begin] : inputVector[end];

	unsigned int LNPB, LNPE, RNPB, RNPE, LMax, RMax;

	LNPB = begin;
	LNPE = (end - begin) / 2;
	RNPB = LNPE + 1;
	RNPE = end;

	LMax = findMaxRecursive(inputVector, LNPB, LNPE);
	RMax = findMaxRecursive(inputVector, RNPB, RNPE);

	return (LMax > RMax) ? LMax : RMax;
}

int main()
{
	vector<unsigned int> inputVector;
	inputVector.push_back(40);
	inputVector.push_back(20);
	inputVector.push_back(50);
	inputVector.push_back(60);
	inputVector.push_back(3);

	cout << "Max = " << findMaxRecursive(inputVector, 0, inputVector.size() - 1);

	getchar();
	return 0;
}
*/

//Hacker Rank: Reverse an array
/*void hr_reverseArr(unsigned short* inputArr, unsigned short size) {
	for (int i=size-1; i>=0; i--)
		cout << inputArr[i] << " ";
}

int main()
{
	unsigned short N, *Arr;
	scanf("%hu\n", &N);

	Arr = (unsigned short*)malloc(N * sizeof(unsigned short));
	for (unsigned short i=0; i<N; i++) {
		scanf("%hu", &(Arr[i]));
	}

	hr_reverseArr(Arr, N);

	free(Arr);
	return 0;
}
*/

//Hacker Rank: Variable Arrays
/*int main()
{
	unsigned int colArrLen, rowArrLen, rowPosVal;
	unsigned int queryLen, queryRow, queryCol;

	vector<vector<unsigned int>*> colArray;
	vector<unsigned int> queryResultArray;

	scanf("%u%u", &colArrLen, &queryLen);

	for (unsigned int i=0; i<colArrLen; i++) {
		vector<unsigned int>* rowArr = new vector<unsigned int>;
		scanf("%u ", &rowArrLen);
		for (unsigned int j=0; j<rowArrLen; j++) {
			scanf("%u", &rowPosVal);
			rowArr->push_back(rowPosVal);
		}
		colArray.push_back(rowArr);
	}
	for (unsigned int i=0; i<qaueryLen; i++) {
		scanf("%u%u", &queryRow, &queryCol);
		queryResultArray.push_back((*(colArray[queryRow]))[queryCol]);
	}

	for (unsigned int i=0; i<queryLen; i++)
		cout << queryResultArray[i] << endl;

	for (unsigned int j=0; j<colArrLen; j++)
		delete colArray[j];

	return 0;
}*/

/*
//Hacker Rank: Handling Static Members
class Person {
protected:
	string name;
	unsigned int age;
	Person(unsigned int age) : age(age) {};

public:
	virtual void getData() = 0;
	virtual void putData() = 0;
};

class Professor : public Person {
public:
	Professor() : Person(0) { 
		cur_id++;
		prof_id = cur_id;
	};
	void getData() {
		char profname[100]; //Again a magic number.
		scanf("%s %u %u", profname, &age, &publications);
		name.assign(profname);
	};
	void putData() {
		cout << name.c_str() << " " << age << " " << publications << " " << prof_id << endl;
	};
private:
	static unsigned int cur_id;
	unsigned int prof_id;
	unsigned int publications;
};

//All Static data is initialized to zero when the first object is created, if no other
//initialization is present. We can't put it in the class definition but it can be initialized
//outside the class as below if required.
unsigned int Professor::cur_id = 0;

class Student : public Person {
public:
	Student() : Person(0) { 
		cur_id++;
		stud_id = cur_id;
	};
	void getData() {
		char studname[100]; //Again a magic number.
		scanf("%s %u", studname, &age);
		for (int i = 0; i < 6; i++)
			scanf("%u", &marks[i]);
		name.assign(studname);
	};
	void putData() {
		unsigned int totalMarks = 0;
		cout << name.c_str() << " " << age << " ";
		for (int i = 0; i < 6; i++)
			totalMarks += marks[i];
		cout << totalMarks << " " << stud_id << endl;
	};

private:
	static unsigned int cur_id;
	unsigned int stud_id;
	unsigned int marks[6]; //Instead of magic number have preprocessor #defines
};

unsigned int Student::cur_id = 0;

int main()
{
	vector<Professor*> profs;
	vector<Student*> studs;
	unsigned int objCount = 0;
	unsigned short objType = 0;
	scanf("%u", &objCount);
	for (unsigned int i = 0; i < objCount; i++) {
		scanf("%hu", &objType);
		if (objType == 1) { //Prof
			Professor *p = new Professor;
			p->getData();
			profs.push_back(p);
		}
		else if (objType == 2) { //Stud
			Student *s = new Student;
			s->getData();
			studs.push_back(s);
		}
		else
			cout << "Invalid Object Type" << endl;
	}

	for (unsigned int i = 0; i < profs.size(); i++)
		profs[i]->putData();
	for (unsigned int i = 0; i < studs.size(); i++)
		studs[i]->putData();

	//cleanup
	for (unsigned int i = 0; i < profs.size(); i++)
		delete profs[i];
	for (unsigned int i = 0; i < studs.size(); i++)
		delete studs[i];

	getchar();
	getchar();

	return 0;
}*/


//Hacker Rank: Sets
/*int main()
{
	set<int> s;
	unsigned int queryCount = 0;
	int queryType = 0;
	scanf("%u", &queryCount);
	int val = 0;
	set<int>::iterator it;
	for (unsigned int i = 0; i < queryCount; i++) {
		scanf("%d%d", &queryType, &val);
		switch (queryType) {
		case 1://Insert
			s.insert(val);
			break;

		case 2://Delete
			s.erase(val);
			break;

		case 3://Find
			it = s.find(val);
			if (it != s.end())
				cout << "Yes";
			else
				cout << "No";
			break;

		default:
			cout << "Invalid Query Type";
		}
	}
	return 0;
}*/

//Merge Sort
//Not Working
/*
vector<int> sortedV;

void Merge(vector<int>& v, unsigned int LNPB, unsigned int LNPE, unsigned int RNPB, unsigned int RNPE) {
	unsigned int lpos = LNPB, rpos = RNPB;

	while (lpos <= LNPE && rpos <= RNPE) {
		if (v[lpos] <= v[rpos]) {
			sortedV.push_back(v[lpos]);
			lpos++;
		}
		else {
			sortedV.push_back(v[rpos]);
			rpos++;
		}
	}

	if (lpos > LNPE) {
		while (rpos <= RNPE) {
			sortedV.push_back(v[rpos]);
			rpos++;
		}
	}
	else {
		while (lpos <= LNPE) {
			sortedV.push_back(v[lpos]);
			lpos++;
		}
	}
}

void Sort(vector<int>& v, unsigned int begin, unsigned int end) {
	cout << "call: begin#" << begin << " end#" << end << endl;
	getchar();
	if (begin < end) {
		unsigned int mid = (end - begin) / 2;

		unsigned int LNPB, LNPE, RNPB, RNPE;

		LNPB = begin;
		LNPE = (end - begin) / 2;
		RNPB = LNPE + 1;
		RNPE = end;

		Sort(v, begin, mid);
		Sort(v, mid+1, end);
		Merge(v, LNPB, LNPE, RNPB, RNPE);
	}
}
*/

void merge_helper(unsigned int left[], unsigned int leftSize, unsigned int right[], unsigned int rightSize, unsigned int src[], unsigned int srcSize) {
	unsigned int leftCntr = 0, rightCntr = 0, srcCntr = 0;
	while (leftCntr < leftSize && rightCntr < rightSize) {
		if (left[leftCntr] <= right[rightCntr]) {
			src[srcCntr] = left[leftCntr];
			srcCntr++;
			leftCntr++;
		}
		else {
			src[srcCntr] = right[rightCntr];
			srcCntr++;
			rightCntr++;
		}
	}

	while (leftCntr < leftSize) {
		src[srcCntr] = left[leftCntr];
		srcCntr++;
		leftCntr++;
	}

	while (rightCntr < rightSize) {
		src[srcCntr] = right[rightCntr];
		srcCntr++;
		rightCntr++;
	}
}

void merge_sort(unsigned int src[], unsigned int srcSize) {
	if (srcSize == 1)
		return;

	unsigned int splitIndex = (unsigned int)floor((srcSize - 1) / 2);
	unsigned int leftSize = splitIndex + 1;
	unsigned int rightSize = srcSize - leftSize;
	
	merge_sort(src, leftSize);
	merge_sort(src + splitIndex + 1, rightSize);
	merge_helper(src, leftSize, src + splitIndex + 1, rightSize, src, srcSize);
}

/*
int main() {

	vector<int> testV;
	testV.push_back(3);
	testV.push_back(1);
	testV.push_back(10);
	testV.push_back(0);
	Sort(testV, 0, testV.size() - 1);
	for (int sortedElement : sortedV) {
		cout << "sortedElement" << endl;
	}

	unsigned int src[9] = { 4, 3, 5, 1, 8, 0, 6, 7, 2 };
	merge_sort(src, 9);
	for (int i = 0; i < 9; i++)
		cout << src[i] << " ";
	cout << endl;

	getchar();
	getchar();



	return 0;
}
*/

//Find unset bits after 1st MSB
//Ex: Input 17 (10001), Output: 3
//Formula:
//Find a which is the MSB and b which is the next set bit.
//Unset bits = a - b -1
//Initialize a & b to -1
int FindUnsetBits(unsigned int input) {
	int a = -1, b = -1;
	int bitCount = sizeof(unsigned int) * 8;
	unsigned int checkBit = 0;

	switch (sizeof(unsigned int)) {
	case 4://32 bit System
		checkBit = 0x80000000;
		break;

	case 8://64 bit System
		checkBit = 0x8000000000000000;
		break;

	default:
		cout << "Unknown System";
		return -1;
	}

	int i = bitCount-1;
	for (; i >= 0; i--) {
		if (input & (0x1 << i)) {
			a = i;
			i--;
			break;
		}
	}
	for (; i >= 0; i--) {
		if (input & (0x1 << i)) {
			b = i;
			break;
		}
	}

	return (a - b - 1);
}

int countunsetbits(int n) {
	int unsetbits = 0;
	for (int x = 1; x <= n; x <<= 1) {
		if ((n&x) == 0)
			unsetbits++;
	}
	return unsetbits;
}

//Brian Kernighan's Algorithm
int countsetbits(int n) {
	int count = 0;

	while (n) {
		n &= (n - 1);
		count++;
	}

	return count;
}

unsigned int raise_to_power(unsigned int x, unsigned int y) {
	unsigned int result = 0;

	if (y > 1)
		result = x * raise_to_power(x, y - 1);
	else
		result = x;

	return result;
}

unsigned int my_atoi(char *src) {
	unsigned int i = 0, result = 0;

	while (*(src + i) != '\0') {
		result = (result * 10) + (*(src + i) - '0');
		i++;
	}

	return result;
}

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int quick_sort_partition(int arr[], int low, int high) {
	int i = low - 1;
	int pi = arr[high];
	
	for (int j = i + 1; j < high; j++) {
		if (arr[j] <= pi) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], pi);

	return i+1;
}

void quick_sort(int arr[], int l, int r) {
	if (l < r) {
		int pi = quick_sort_partition(arr, l, r);

		quick_sort(arr, l, pi - 1);
		quick_sort(arr, pi + 1, r);
	}
}

bool string_match_with_wild_characters(char *first, char *second) {
	//If we reach at the end of both strings we are done
	if (*first == '\0' && *second == '\0')
		return true;

	//Make sure that the characters after '*' are present in the second string
	//This function assumes that the first string will not contain two consecutive '*'
	if (*first == '*' && *(first + 1) != '\0' && *second == '\0')
		return false;

	//If the first string contains '?' or the characters in both strings match, continue with next characters
	if (*first == '?' || *first == *second)
		return string_match_with_wild_characters(first + 1, second + 1);

	//If there is a '*' then there are 2 possibilities:
	//1. We consider current character of second string
	//2. We ignore current character of second string
	if (*first == '*')
		return string_match_with_wild_characters(first + 1, second) || string_match_with_wild_characters(first, second + 1);

	return false;
}


int main() {
	int unsetBitCount = countunsetbits(16);//FindUnsetBits(1);
	if (unsetBitCount >= 0)
		cout << "Unset Bit Count after MSB = " << unsetBitCount << endl;
	else
		cout << "Unknown" << endl;

	int setBitCount = countsetbits(16);
	cout << "Set Bit count = " << setBitCount << endl;

	cout << "AtoI of 120 = " << my_atoi("120") << endl;

	int arr[] = { 10,80,30,90,40,50,70 };
	quick_sort(arr, 0, 6);
	for (int k = 0; k <= 6; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}