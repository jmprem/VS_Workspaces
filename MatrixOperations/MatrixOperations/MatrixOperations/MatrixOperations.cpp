// MatrixOperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define R	4
#define C	4

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void print_matrix(int matrix[][C]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void transpose_matrix(int matrix[][C]) {
	for (int i = 1; i < R; i++)
		for (int j = 0; j <= i; j++)
			swap(matrix[i][j], matrix[j][i]);
}


int main()
{
//	int matrix[R][C] = { 1,2,3,4,5,6,7,8,9 };
	int matrix[R][C] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	print_matrix(matrix);
	transpose_matrix(matrix);
	print_matrix(matrix);
	getchar();
	return 0;
}

