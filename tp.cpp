#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* insert(struct Node* root, int tData)
{
	struct Node* newNode = new Node;
	newNode->data = tData;
	newNode->left = NULL;
	newNode->right = NULL;
	if(root == NULL)
	{
		root = newNode;
		return root;
	}
	
	Node* current = root, *parent = root;
	while(current)
	{
		parent = current;
		if(current->data < tData)
			current = current->right;
		else
			current = current->left;
	}
	if(parent->data > tData)
		parent->left = newNode;
	else
		parent->right = newNode;
	return root;
}
void inOrder(Node* root)
{
    if(root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int max(Node* t1, Node* t2)
{
    if(t1->data > t2->data)
        return t1->data;
    else
        return t2->data;
}
int maxHeight(Node* root)
{
    if(!root)
        return(0);
    else
        return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}
bool checkBST(Node* root)
{
	if(root == NULL)
		return true;
	else if(!root->left || !root->right)
		return false;
	else if(root->data < root->left->data || root->data > root->right->data)
		return false;
	else
		return true;
	return checkBST(root->left) && checkBST(root->right);	
}
void mirror(Node* root)
{
	if(root == NULL)
		return;
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	mirror(root->left);
	mirror(root->right);
}
int sumLeaf(Node* root)
{
	if(!root)
		return 0;
	int s = 0;
	if(root->left == NULL && root->right == NULL)
		return s + root->data;
	s += sumLeaf(root->left);
	s += sumLeaf(root->right);
	return s;	
}
int countTreeNodes(Node* root)
{
	int c = 0;
	if(root)
	{
		c += 1;
		c += countTreeNodes(root->left);
		c += countTreeNodes(root->right);
		return c;
	}
	return(0);
}
int* convert(Node* root, int* arr)
{
	if(!root)
		return arr;
	arr = convert(root->left, arr);
	*arr = root->data;
	arr += 1;
	arr = convert(root->right, arr); 
}
int* convertToArray(Node* root)
{
	int* arr = new int[countTreeNodes(root)];
	convert(root, arr);
	return arr;
}
void arrayToBST (int *arr, Node* root, int *index_ptr) 
{  
    if (root == NULL) 
      return; 
    arrayToBST (arr, root->left, index_ptr); 
    root->data = arr[*index_ptr]; 
    (*index_ptr)++;
    arrayToBST (arr, root->right, index_ptr); 
} 
bool checkInOrder(Node* root, int* arr)
{
	if(!root)
		return true;
	bool c;
	c = checkInOrder(root->left, arr);
	if(*arr != root->data)
		return false;
	arr += 1;
	c = checkInOrder(root->right, arr);
	return c;
}
int sumT(Node* root)
{
	if(!root)
		return 0;
	if(!root->left && !root->right)
	{
		int old = root->data;
		root->data = 0;
		return old;
	}
	root->data = sumT(root->left) + sumT(root->right) + root->data;
	return root->data;
}
int countTreeNodes(int n)
{
	if(!n)
		return 1;
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		s += countTreeNodes(i)*countTreeNodes(n - i + 1);
	}
	return s;
}
void printPaths(Node* root, int n, int* arr)
{
	if(root == NULL)
		return;
	
}
int doSomething(Node* root)
{
	if(!root)
		return 0;
	int val = 0;
	if(!root->left && !root->right)
		val = 1;
	else
		val = val + doSomething(root->left) + doSomething(root->right);
	return val;
}
int main()
{
    Node* tree1 = NULL;
    tree1 = insert(tree1, 20);
    tree1 = insert(tree1, 13);
    tree1 = insert(tree1, 28);
    tree1 = insert(tree1, 17);
    tree1 = insert(tree1, 67);
    tree1 = insert(tree1, 9);
	tree1 = insert(tree1, 25);
	//int* arr = convertToArray(tree1);
	//if(checkInOrder(tree1, arr))
	//	cout << "True" << endl;
	//else
	//{
	//	cout << "False" << endl;
	//}
	//int s = sumT(tree1);
	//inOrder(tree1);
	//topView(tree1);
	//cout << maxHeight(tree1) << endl;
	//levelOrder(tree1, maxHeight(tree1));
	int n = doSomething(tree1);
	cout << n << endl;
	delete tree1;
	return(0);
}