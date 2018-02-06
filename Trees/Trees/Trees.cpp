#include "Stack.h"
#include "Trees.h"

#include <iostream>

using namespace std;

//In-order traversal of a given binary tree using recursion
void bintree_inorder_traversal_using_recursion(struct BinTreeNode *root) {
	if (root == NULL)
		return;

	bintree_inorder_traversal_using_recursion(root->left);
	cout << root->data << " ";
	bintree_inorder_traversal_using_recursion(root->right);
}

//Pre-order traversal of a given binary tree using recursion

void bintree_preorder_traversal_using_recursion(struct BinTreeNode *root) {
	if (root == NULL)
		return;

	cout << root->data << " ";
	bintree_preorder_traversal_using_recursion(root->left);
	bintree_preorder_traversal_using_recursion(root->right);
}

//Post-order traversal of a given binary tree using recursion
void bintree_postorder_traversal_using_recursion(struct BinTreeNode *root) {
	if (root == NULL)
		return;

	bintree_postorder_traversal_using_recursion(root->left);
	bintree_postorder_traversal_using_recursion(root->right);
	cout << root->data << " ";
}

//Level-order traversal

//Level-order traversal printing each level in a line

//In-order traversal of a given binary tree without recursion and using stack
void bintree_inorder_traversal_without_recursion(struct BinTreeNode *root) {

	Stack<struct BinTreeNode, int> s;
	bool done = false;
	struct BinTreeNode *cur = root;

	while (!done) {
		if (cur != NULL) {
			s.push(&cur);
			cur = cur->left;
		}
		else {
			struct BinTreeNode *poppedNode = NULL;
			if (!s.isEmpty()) {
				s.pop(&poppedNode);
				cout << poppedNode->data << " ";
				if (poppedNode->right != NULL)
					cur = poppedNode->right;
			}
			else
				done = true;
		}
	}
}

//Pre-order traversal without recursion
void bintree_preorder_traversal_without_recursion(struct BinTreeNode *root) {
	struct BinTreeNode *cur = root;
	Stack<struct BinTreeNode, int> S;
	bool done = false;
	
	if (cur == NULL)
		return;

	S.push(&cur);

	while (!done)
	{
		if (!S.isEmpty()) {
			struct BinTreeNode *poppedNode = NULL;
			S.pop(&poppedNode);
			cout << poppedNode->data << " ";
			if (poppedNode->right != NULL)
				S.push(&(poppedNode->right));
			if (poppedNode->left != NULL)
				S.push(&(poppedNode->left));
		}
		else
			done = true;
	}
}

//Post order traversal without recursion
void bintree_postorder_traversal_without_recursion_with_2Stacks(struct BinTreeNode *root) {
	struct BinTreeNode *cur = root;
	if (cur == NULL)
		return;
	Stack<struct BinTreeNode, int> S1, S2;

	S1.push(&cur);

	while (!S1.isEmpty()) {
		struct BinTreeNode *poppedNode = NULL;
		S1.pop(&poppedNode);
		S2.push(&poppedNode);
		if (poppedNode->left != NULL)
			S1.push(&(poppedNode->left));
		if (poppedNode->right != NULL)
			S1.push(&(poppedNode->right));
	}

	while (!S2.isEmpty()) {
		struct BinTreeNode *poppedNode = NULL;
		S2.pop(&poppedNode);
		cout << poppedNode->data << " ";
	}
}

//Inorder traversal without recursion and without stack
void bintree_inorder_traversal_without_recursion_without_stack(struct BinTreeNode *root) {
	if (root == NULL)
		return;

	struct BinTreeNode *cur = root, *pre = NULL;

	while (cur != NULL) {
		if (cur->left == NULL) {
			cout << cur->data << " ";
			cur = cur->right;
		}
		else {
			pre = cur->left;
			while (pre->right != NULL && pre->right != cur)
				pre = pre->right;

			if (pre->right == NULL) {
				pre->right = cur;
				cur = cur->left;
			}
			else {
				cout << cur->data << " ";
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
}

void bintree_postorder_traversal_without_recursion_2(struct BinTreeNode *root) {


}

//Mirror a Binary Tree

//Left View of a Binary Tree

//Right View of a Binary Tree

