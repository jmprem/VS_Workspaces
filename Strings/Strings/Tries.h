#pragma once
#include <string>
using namespace std;

#define MAX_ALPHABET_SIZE   26
#define UNICODE_a           97

struct TrieNode {
	struct TrieNode *alphabets[MAX_ALPHABET_SIZE];//'a' to 'z
	int count;//Stores the actual number of times this node is repeated in the contact list
};

struct ContactsList {
	struct TrieNode *contacts;
};

void add_contact(struct ContactsList &contactsList, string &contact);
int find_partial(struct ContactsList &contactsList, string &partial);
