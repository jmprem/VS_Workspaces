#include "Tries.h"

void add_contact(struct ContactsList &contactsList, string &contact)
{
	string::iterator it;
	struct TrieNode *curTrieNode = contactsList.contacts;
	for (it = contact.begin(); it != contact.end(); it++) {
		int charIdx = *it - UNICODE_a;
		if (curTrieNode->alphabets[charIdx] == NULL) {
			curTrieNode->alphabets[charIdx] = (struct TrieNode *)malloc(sizeof(struct TrieNode));
			curTrieNode->alphabets[charIdx]->count = 1;
			for (int i = 0; i < MAX_ALPHABET_SIZE; i++)
				curTrieNode->alphabets[charIdx]->alphabets[i] = NULL;
		}
		else
			curTrieNode->alphabets[charIdx]->count++;

		curTrieNode = curTrieNode->alphabets[charIdx];
	}
}

int find_partial(struct ContactsList &contactsList, string &partial) {
	string::iterator it;
	struct TrieNode *curTrieNode = contactsList.contacts;
	int count = 0;
	for (it = partial.begin(); it != partial.end(); it++) {
		int charIdx = *it - UNICODE_a;
		if (curTrieNode->alphabets[charIdx] == NULL) {
			count = 0;
			break;
		}
		else {
			count = curTrieNode->alphabets[charIdx]->count;
			curTrieNode = curTrieNode->alphabets[charIdx];
		}
	}

	return count;
}
