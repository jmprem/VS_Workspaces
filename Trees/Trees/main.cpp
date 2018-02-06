#include <iostream>

#include "Stack.h"
#include "Trees.h"

using namespace std;

int main(int argc, char *argv[])
{
	struct BinTreeNode *n1 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n1->left = NULL;
	n1->right = NULL;
	struct BinTreeNode *n2 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n2->left = NULL;
	n2->right = NULL;
	struct BinTreeNode *n3 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n3->left = NULL;
	n3->right = NULL;
	struct BinTreeNode *n4 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n4->left = NULL;
	n4->right = NULL;
	struct BinTreeNode *n5 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n5->left = NULL;
	n5->right = NULL;
	struct BinTreeNode *n6 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n6->left = NULL;
	n6->right = NULL;
	struct BinTreeNode *n7 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n7->left = NULL;
	n7->right = NULL;
	struct BinTreeNode *n8 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n8->left = NULL;
	n8->right = NULL;
	struct BinTreeNode *n9 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n9->left = NULL;
	n9->right = NULL;

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;
	n8->data = 8;
	n9->data = 9;

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n5->left = n6;
	n3->left = n7;
	n7->left = n9;
	n7->right = n8;

	cout << "Inorder Traversal using Recursion" << endl;
	bintree_inorder_traversal_using_recursion(n1);
	cout << endl;

	cout << "Preorder traversal using recursion" << endl;
	bintree_preorder_traversal_using_recursion(n1);
	cout << endl;

	cout << "Postorder traversal using recursion" << endl;
	bintree_postorder_traversal_using_recursion(n1);
	cout << endl;

	cout << "Inorder traversal without recursion" << endl;
	bintree_inorder_traversal_without_recursion(n1);
	cout << endl;

	cout << "Preorder traversal without recursion" << endl;
	bintree_preorder_traversal_without_recursion(n1);
	cout << endl;

	cout << "Inorder traversal without recursion without stack" << endl;
	bintree_inorder_traversal_without_recursion_without_stack(n1);
	cout << endl;

	cout << "Postorder traversal without recursion with 2 stacks" << endl;
	bintree_postorder_traversal_without_recursion_with_2Stacks(n1);
	cout << endl;

	getchar();


	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
	free(n7);
	free(n8);
	free(n9);

	return 0;
}