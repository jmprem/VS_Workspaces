#include "Utils.h"
#include <iostream>

void printHello() {
	std::cout << "Hello World!";
}

bool isJumpingNumber(unsigned int num) {
	unsigned int digit1 = 0, digit2 = 0;

	while (num >= 10) {
		digit1 = num % 10;
		digit2 = (num / 10) % 10;
		int diff = digit1 - digit2;
		if (diff != 1 && diff != -1)
			return false;

		num = num / 10;
	}

	return true;
}

bool checkSubArrayWithSum(int arr[], int arrSize, int sum, int &start, int &end)
{
	int i = 1, curSum = arr[0];
	start = 0;
	end = 0;

	for(i=1; i<=arrSize; i++)
	{
		while ((curSum > sum) && (start < i-1))
		{
			curSum -= arr[start];
			start++;
		}

		if (curSum == sum)
		{
			end = i - 1;
			return true;
		}

		if(i<arrSize)
			curSum += arr[i];
	}

	if (curSum == sum)
	{
		end = i - 1;
		return true;
	}

	start = -1;
	end = -1;
	return false;
}
