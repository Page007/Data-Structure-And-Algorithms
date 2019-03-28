#include "utility.h"

struct Node* create()	//Returns a linked list with empty node.
{
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	return head;
}

struct Node* create_with_capacity(int n)	// Returns a linked list with capacity of 'n' nodes
{
	struct Node* head = (struct Node*)malloc(n*sizeof(struct Node));
	return head;
}

struct Node* add(struct Node* head, int x)	// Returns a set data structure with 'x' added to it.
{
	if(head == NULL)
	{
		struct Node* new = (struct Node*)malloc(sizeof(struct Node));
		head = new;
		head->link = NULL;
		head->data = x;
		return head;	// Insert head if linked list is empty.
	}
	
	struct Node* current = head;
	while(current != NULL)
	{
		if(current->data == x)
		{
			printf("The element already exists in the set\n");
			return head;	// Return the linked list as it is if 'key'already exists in set.
		}
		current = current->link;
	}
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->link = head;
	temp->data = x;
	head = temp;
	return head;
} 


struct Node* deleteNode(struct Node* head, int key)	 //Deletes a node from the linked list whose data is equal to 'key'
{
	struct Node* current = head, *prev = head;
	if(current->data == key)
	{
		head = current->link;
		current->link = NULL;
		free(current);
		return head;
	}
	current = current->link;
	while(current)
	{
		if(current->data == key)
		{
			prev->link = current->link;
			current->link = NULL;
			free(current);
			return head;
		}
		current = current->link;
		prev = prev->link;
	}
	printf("Element not found\n");
	return head;	// Return the linked list as it is if element not found
}
