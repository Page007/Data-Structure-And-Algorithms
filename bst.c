#include "lib.h"
struct Node* insert(struct Node* root, int tData)
{
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = tData;
	new->left = NULL;
	new->right = NULL;
	if(root == NULL)
	{
		root = new;
		return root;
	}
	
	struct Node* current = root, *parent = root;
	while(current)
	{
		parent = current;
		if(current->data < tData)
			current = current->right;
		else
			current = current->left;
	}
	if(parent->data > tData)
		parent->left = new;
	else
		parent->right = new;
	return root;
}

void inOrder(struct Node* root)
{
	if(root)
	{
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

int main()
{
	struct Node* root = NULL;
	root = insert(root, 8);
	root = insert(root, 7);
	root = insert(root, 9);
	root = insert(root, 3);
	root = insert(root, 15);
	root = insert(root, 4);
	inOrder(root);
	struct Node* r1 = NULL;
	r1 = insert(r1, 8);
	r1 = insert(r1, 7);
	r1 = insert(r1, 9);
	r1 = insert(r1, 3);
	r1 = insert(r1, 15);
	r1 = insert(r1, 4);
	inOrder(r1);
	if(exactIdentical(root, r1))
		printf("Trees are exactly identical\n");
	else
		printf("Trees are not identical\n");
	struct Node* r2 = NULL;
	r2 = insert(r2, 8);
	r2 = insert(r2, 7);	
	
	if(structIdentical(r2, r1))
		printf("Trees are exactly identical\n");
	else
		printf("Trees are not identical\n");
	struct Node* r3 = NULL;
	r3 = insert(r3, 10);
	r3 = insert(r3, 20);
	r3 = insert(r3, 5);
	r3 = insert(r3, 16);
	r3 = insert(r3, 4);
	printf("Before mirror image : ");
	inOrder(r3);
	printf("After mirror Image : ");
	mirrorImage(r3);
	inOrder(r3);	
	if(checkBST(r3))
		printf("Input is a BST\n");
	else
		printf("The input is not a BST\n");
	printf("Number of trees in the BST is %d\n", countTrees(3));
	
	struct Node* newTree = NULL;
	newTree = insert(newTree, 10);
	newTree = insert(newTree, 20);
	newTree = insert(newTree, 5);
	newTree = insert(newTree, 45);
	newTree = insert(newTree, 33);
	newTree = insert(newTree, 8);
	newTree = insert(newTree, 89);

	creativePrint(newTree);
	return(0); 	
}