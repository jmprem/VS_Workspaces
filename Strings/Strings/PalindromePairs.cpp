// C++ program to check if there is a pair that
// of above method using Trie
#include "PalindromePairs.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Returns new Trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isLeaf = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// Utility function to check if a string is a
// palindrome
bool isPalindromeStartIdxAndLength(string str, int i, int len)
{
	// compare each character from starting
	// with its corresponding character from last
	while (i < len)
	{
		if (str[i] != str[len])
			return false;
		i++, len--;
	}

	return true;
}

// If not present, inserts reverse of key into Trie. If 
// the key is prefix of a Trie node, just mark leaf node
void insert(struct TrieNode* root, string key, int id)
{
	struct TrieNode *pCrawl = root;

	// Start traversing word from the last
	for (int level = key.length() - 1; level >= 0; level--)
	{
		// If it is not available in Trie, then
		// store it
		int index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		// If current word is palindrome till this
		// level, store index of current word.
		if (isPalindromeStartIdxAndLength(key, 0, level))
			(pCrawl->pos).push_back(id);

		pCrawl = pCrawl->children[index];
	}
	pCrawl->id = id;
	pCrawl->pos.push_back(id);

	// mark last node as leaf
	pCrawl->isLeaf = true;
}

// Returns true if key presents in Trie, else false
void search(struct TrieNode *root, string key,
	int id, vector<vector<int> > &result)
{
	struct TrieNode *pCrawl = root;
	for (unsigned int level = 0; level < key.length(); level++)
	{
		int index = CHAR_TO_INDEX(key[level]);

		// If it is present also check upto which index
		// it is palindrome
		if (pCrawl->id >= 0 && pCrawl->id != id &&
			isPalindromeStartIdxAndLength(key, level, key.size() - 1))
			result.push_back({ id, pCrawl->id });

		// If not present then return
		if (!pCrawl->children[index])
			return;

		pCrawl = pCrawl->children[index];
	}

	for (int i : pCrawl->pos)
	{
		if (i == id)
			continue;
		result.push_back({ id, i });
	}
}

// Function to check if a palindrome pair exists
bool checkPalindromePair(vector <string> vect)
{
	// Construct trie
	struct TrieNode *root = getNode();
	for (unsigned int i = 0; i < vect.size(); i++)
		insert(root, vect[i], i);

	// Search for different keys
	vector<vector<int> > result;
	for (unsigned int i = 0; i<vect.size(); i++)
	{
		search(root, vect[i], i, result);
		if (result.size() > 0)
			return true;
	}

	return false;
}