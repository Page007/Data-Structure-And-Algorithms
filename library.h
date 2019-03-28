#include<stdio.h>
#include<stdlib.h>
#define HASHVAL 10
struct Node 
{
    int data;
    struct Node* link;
};

// Functions for static sets.

int is_element_of(struct Node**, int);

int hashFunction(int);

struct Node** setup(struct Node**);

int is_empty(struct Node**);

int size(struct Node**);

void enumerate(struct Node**);

struct Node** build(int*, int);

struct Node** build1(int*, int);

// Functions for dynamic sets

struct Node** create(struct Node**);

struct Node** add(struct Node**, int);

struct Node** deleteNode(struct Node**, int);

struct Node** unionOfSets(struct Node**, struct Node**);

struct Node** deepCopy(struct Node**);

struct Node** intersectionOfSets(struct Node**, struct Node**);

struct Node** difference(struct Node**, struct Node**);

int is_subset(struct Node**, struct Node**);


// END OF ALL FUNCTIONS. 