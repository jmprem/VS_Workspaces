#pragma once
#include<iostream>
#include<vector>

using namespace std;

bool isPalindromeIndexBased(string str, int low, int high);

void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart,
	int start, int n, string str);

void allPalPartitions(string str);
