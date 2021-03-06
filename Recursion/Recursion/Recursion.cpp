// Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int sumIterative(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0)
			sum += arr[i];
	}
	return sum;
}

int sumRecursive(int arr[], int size) {
	if (size == 1)
		return arr[0];

	int sum = 0;
	if (arr[size - 1] >= 0)
		sum = arr[size - 1] + sumRecursive(arr, size - 1);
	else
		sum = sumRecursive(arr, size - 1);

	return sum;
}

bool oddParityIterative(char arr[], int size) {
	int oddCount = 0, evenCount = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == 1)
			oddCount++;
		else
			evenCount++;
	}
	return oddCount > evenCount ? true : false;
}

//Not Working
bool oddParityRecursive(char arr[], int size) {
	if (size == 1)
		return arr[0] == 1 ? true : false;

	bool oddParity = oddParityRecursive(arr, size - 1);
	//Assuming 1/0 in the array with a warning this should go through. Otherwise explicitly do XOR with 1/0 based on 
	//return value from the recursive call
	return arr[size - 1] ^ oddParity;
}

int findFreqRecursive(int arr[], int size, int target) {
	if (size == 1) {
		if (arr[0] == target)
			return 1;
		else
			return 0;
	}

	int freq = findFreqRecursive(arr, size - 1, target);
	if (arr[size - 1] == target)
		return freq + 1;
	else
		return freq;
}

int main()
{
	int arr[] = { 0, 2, -3, -4, 5, 6 };
	cout << sumIterative(arr, 6) << endl;
	cout << sumRecursive(arr, 6) << endl;

	char parityArray[] = { 0, 1, 1, 0, 1, 0, 1, 0};
	cout << oddParityIterative(parityArray, 8) << endl;
	cout << oddParityRecursive(parityArray, 8) << endl;

	int arrFreq[] = { 1, -1, 1, -1, 2, 3, -1, 4, 5, 5, 5, 5 };
	cout << findFreqRecursive(arrFreq, 12, -1) << endl;
	getchar();
    return 0;
}

