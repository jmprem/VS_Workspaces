// BitOperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

//Change the bit#"p" of the value "n" to the bit val "b"
int ChangeBit(int n, int p, int b) {
	int mask = 0x1 << p;

	return ((n & ~mask) | (b << p));
}

//n=42, l=2, r=5 should output 2.
//Check 'l'th bit to 'r'th bit
//Binary of 42 is 00101010
int CountSetBitsNaive(unsigned int n, int lPos, int rPos) {
	int countSetBits = 0;
	int i = lPos;
	while (i <= rPos) {
		if (n & (0x1 << (i - 1)))
			countSetBits++;

		i++;
	}

	return countSetBits;
}

int CountSetBitsBrianz(unsigned int n) {
	int countSetBits = 0;
	while (n) {
		n &= (n - 1);
		countSetBits++;
	}
	return countSetBits;
}

unsigned int BitSetARange(unsigned int n, int lPos, int rPos) {
	// 1 based index and lPos <= rPos
	//return (n | ((((0x1<<rPos )-1)^((0x1<<(lPos-1))-1))));

	// 0 based index and lPos >= rPos
	return (n | ((((((unsigned int)0x1) << lPos)-1) ^ ((((unsigned int)0x1) << rPos)-1))));
}

void PrintBits(unsigned int n) {
	stack<bool> s;
	cout << s.size() << endl;
	int bitCount = sizeof(n) * CHAR_BIT;
	for (int i = 0; i < bitCount; i++) {
		s.push(n % 2);
		n /= 2;
	}

	for (int i = 1; i < bitCount+1; i++) {
		cout << s.top();
		s.pop();

		if (i%CHAR_BIT == 0)
			cout << " ";
	}

	cout << endl;
}

void Print1sComplement(unsigned int n) {
	int bitCount = sizeof(n) * CHAR_BIT;
	PrintBits(n);

	//Method#1
	for (int i = 0; i < bitCount; i++) {
		n ^= ((unsigned int)0x1 << i);
	}

	//Method#2:
	//Note that log returns a double
/*	int shiftOffset = floor(log2(n)) + 1;
	unsigned int bitMask = (0x1 << shiftOffset)-1;
	n ^= bitMask;*/

	PrintBits(n);
}

bool AreAllBitsSet(unsigned int n) {
	bool retVal = false;

	if (n == 0)
		retVal = false;

	retVal = (n&(n+1)) ? true : false;

	return retVal;
}

bool IsEachOther1sComplement(unsigned int a, unsigned int b) {
	unsigned int xorVal = a^b;

	//Method#1
	bool retVal = ((sizeof(unsigned int) * CHAR_BIT) == CountSetBitsBrianz(xorVal)) ? true : false;

	//Method#2
	//bool retVal = AreAllBitsSet(xorVal);

	return retVal;
}

unsigned int Xor1toN(unsigned int n) {
	unsigned int retVal=0;
	switch (n % 4) {
	case 0:
		retVal = n;
		break;

	case 1:
		retVal = 1;
		break;

	case 2:
		retVal = n + 1;
		break;

	default: //case 3
		retVal = 0;
		break;
	}

	return retVal;
}

void CheckOverflowUnderflow() {
	short signedN = -32768;
	cout << sizeof(short)*CHAR_BIT << " " << signedN << endl;
}

unsigned int AddNumIndirect(unsigned int x, unsigned int y) {

	unsigned int carry = 0;
	
	while (y != 0) {
		carry = x & y;
		x ^= y;
		y = carry << 1;
	}

	return x;
}


unsigned int AddNumIndirectRecursive(unsigned int x, unsigned int y) {

	if (y == 0)
		return x;

	AddNumIndirectRecursive(x^y, (x&y)<<1);
}

int parity(unsigned int x) {
	unsigned int y;
	y = x ^ (x >> 1);
	y = y ^ (y >> 2);
	y = y ^ (y >> 4);
	y = y ^ (y >> 8);
	y = y ^ (y >> 16);
	return y & 1;
}

void swapNybbles(wchar_t input) {
	cout << sizeof(input);
}

//Following definitions of my_sizeof and my_offset works in gcc tool chain. Checked compiling through cygwin.
//But it doesn't work in MS Visual Studio
//#define my_sizeof(T)	((char*)(((typeof(T)*) 0) + 1) - (char*)((typeof(T)*) 0))
//#define my_offset(T,E)    (size_t)(&(((typeof(T)*)(0))->E))

int main()
{
	int i;
	char c;
	short s;
	//cout << "Size of short = " << my_sizeof(s) << endl;
//	cout << "Size of short = " << my_sizeof(short) << endl;

//	cout << ChangeBit(7,3,1);
//	cout << CountSetBitsNaive(42, 1, 7);
//	cout << CountSetBitsBrianz(42);
	//Input: 170, Expected Output = 190
//1 based index and lPos <= rPos
//	cout << BitSetARange(170, 2, 6);
	//Input: 170, Expected Output = 190
	//0 based index and lPos >= rPos
//	cout << BitSetARange(170, 5, 1);
//	PrintBits(170);
//	Print1sComplement(255);
//	Print1sComplement(5);
//	Print1sComplement(26);
	//cout << IsEachOther1sComplement((unsigned int)0xFFFFFFFF,(unsigned int)1);
//	CheckOverflowUnderflow();
//	cout << AddNumIndirectRecursive(20, 5);
	cout << "Parity of 3 is: " << parity(3) << endl;
	cout << "Parity of 1 is: " << parity(1) << endl;
	cout << "Parity of 4 is: " << parity(4) << endl;
	cout << "Parity of 0 is: " << parity(0) << endl;
	cout << "Parity of 7 is: " << parity(7) << endl;
	cout << "Parity of 15 is: " << parity(15) << endl;

	getchar();
    return 0;
}

