#include <iostream>
#include <string>
//#include "Palindrome.h"
#include "PalindromePairs.h"
//#include "PatternMatching.h"

using namespace std;

int main() {

	//string str = "madai";
	//cout << "Printing all palindromic partitions of string: " << str << endl;
	//allPalPartitions(str);
	

//	vector <string> vect = { "geekf", "geeks", "or", "keeg", "abc", "bc" };
	vector <string> vect = { "geekf", "geeks", "keeg" };
	checkPalindromePair(vect) ? cout << "Yes" :	cout << "No";

	//char *txt = "gks??";
	//char *pat = "gks12";
	//match_TxtNormal_PatWithRegExp(txt, pat) ? cout << "Matches" : cout << "Doesn't Match";

	getchar();

	return 0;
}