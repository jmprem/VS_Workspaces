#ifndef __TREES_H_
#define __TREES_H_

struct BinTreeNode {
	int data;
	struct BinTreeNode *left;
	struct BinTreeNode *right;
};

//In-order traversal of a given binary tree using recursion
void bintree_inorder_traversal_using_recursion(struct BinTreeNode *root);

//Pre-order traversal of a given binary tree using recursion

void bintree_preorder_traversal_using_recursion(struct BinTreeNode *root);

//Post-order traversal of a given binary tree using recursion
void bintree_postorder_traversal_using_recursion(struct BinTreeNode *root);

//Level-order traversal

//Level-order traversal printing each level in a line

//In-order traversal of a given binary tree without recursion and using stack
void bintree_inorder_traversal_without_recursion(struct BinTreeNode *root);

//Pre-order traversal of a given binary tree without recursion and using stack
void bintree_preorder_traversal_without_recursion(struct BinTreeNode *root);

//Post-order traversal of a given binary tree without recursion and using 2 stacks
void bintree_postorder_traversal_without_recursion_with_2Stacks(struct BinTreeNode *root);

void bintree_inorder_traversal_without_recursion_without_stack(struct BinTreeNode *root);

#endif