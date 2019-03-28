#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
int exactIdentical(struct Node*, struct Node*);
int structIdentical(struct Node* root1, struct Node* root2);
void mirrorImage(struct Node*);
int checkBST(struct Node*);
int countTrees(int t);	
void creativePrint(struct Node*);