#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data; 
	struct Node* link;
};

// Functions for the dynamic set.

struct Node* create();
struct Node* create_with_capacity(int n);
struct Node* add(struct Node* head, int x);
void removeElement(struct Node* head, int x);

// Functions for static set

int is_element_of(struct Node* head ,int x);

int is_empty(struct Node* head);

int cardinality(struct Node* head);

void enumerate(struct Node* head);

struct Node* build(int* a, int n);

struct Node* deleteNode(struct Node *head_ref, int key);

struct Node* build1(int*, int);
// Functions of main
void verify(int);

// Operation functions

struct Node* getUnion(struct Node*, struct Node*);

struct Node* getIntersection(struct Node* , struct Node* );

int min(int, int);

struct Node* difference(struct Node*, struct Node*);

int subset(struct Node* s, struct Node* t);