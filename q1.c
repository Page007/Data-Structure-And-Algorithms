// Given  2 trees, check whether they are strucurally equal.
#include "lib.h"

int exactIdentical(struct Node* root1, struct Node* root2)
{
	if(!root1 && !root2)
		return 1; // return true if both are empty
	if(root1 && root2)
		return (root1->data == root2->data) && exactIdentical(root1->left, root2->left) && exactIdentical(root1->right, root2->right);
	return(0);	// If the control lands here, it means that the trees are unequal
}

int structIdentical(struct Node* root1, struct Node* root2)
{
	if(!root1 && !root2)
		return 1; // return true if both are empty
	if(root1 && root2)
		return structIdentical(root1->left, root2->left) && structIdentical(root1->right, root2->right);
	return(0);	// If the control lands here, it means that the trees are unequal
}

void mirrorImage(struct Node* root)
{
	if(root == NULL)
		return;
	struct Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	mirrorImage(root->left);
	mirrorImage(root->right);
}

// Checking whether a binary tree is a BST or not

int checkBST(struct Node* root)
{
	if(!root)
		return 1;
	else if(((!root->left) || (root->data > root->left->data)) && ((!root->right) || (root->data < root->right->data)))	
		return checkBST(root->left) && checkBST(root->right);
	else
		return 0;
}

int countTrees(int t)
{
	if(t == 1)
		return 1;
	else
		return 3*countTrees(t - 1) - 1;	
}

void creativePrint(struct Node* root)
{
	if(root)
	{
		printf("\t");
		creativePrint(root->right);
		printf("%d\n", root->data);
		creativePrint(root->left);
		printf("\t");
	}
}