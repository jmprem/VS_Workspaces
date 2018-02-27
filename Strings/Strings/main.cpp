#include <iostream>
#include <string>
//#include "Palindrome.h"
//#include "PalindromePairs.h"
//#include "PatternMatching.h"
#include "Tries.h"

using namespace std;
/*
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
}*/

int main() {
	struct ContactsList contactsList;
	contactsList.contacts = (struct TrieNode *)malloc(sizeof(struct TrieNode));
	for (int i = 0; i < MAX_ALPHABET_SIZE; i++)
		contactsList.contacts->alphabets[i] = NULL;

	int n;
	cin >> n;
	for (int a0 = 0; a0 < n; a0++) {
		string op;
		string contact;
		cin >> op >> contact;
		if (op == "add")
			add_contact(contactsList, contact);
		else if (op == "find")
			cout << find_partial(contactsList, contact) << endl;
		else
			cout << "Invalid Op" << endl;
	}

	getchar();

	return 0;
}

