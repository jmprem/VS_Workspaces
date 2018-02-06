#pragma once
#include <vector>
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	vector<int> pos; // To store palindromic
					 // positions in str
	int id;

	// isLeaf is true if the node represents
	// end of a word
	bool isLeaf;
};

struct TrieNode *getNode(void);
bool isPalindromeStartIdxAndLength(string str, int i, int len);
void insert(struct TrieNode* root, string key, int id);
void search(struct TrieNode *root, string key,
	int id, vector<vector<int> > &result);
bool checkPalindromePair(vector <string> vect);
