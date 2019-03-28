#include "utility.h"

int is_element_of(struct Node* head, int x)		// Returns true if 'x' is an element of the set
{
	struct Node* current = head;
	while(current)
	{
		if(current->data == x)
			return 1;				// Return true if 'x' is an element of the set
		current = current->link;
	}
	return 0;						// Control reaches here only if 'x' is not an element of the set.
}

int is_empty(struct Node* head)		// Returns true if the set is empty
{
	if(head == NULL)
		return 1;					// If head is NULL, return true, else return false
	return 0;
}

int cardinality(struct Node* head)	// Returns the number of elements in the set.
{
	struct Node* current = head;
	if(current == NULL)
		return 0;			// Return 0 on empty set.
	int count = 0;
	while(current)
	{
		count += 1;
		current = current->link;
	}
	return count;
}


void enumerate(struct Node* head) 	// Prints the set in an arbitrary order
{
	struct Node* current = head;
	if(!head)
	{
		printf("List is empty\n");
		return;
	}
	while(current)
	{
		printf("%d ", current->data);
		current = current->link;
	}	
	printf("\n");
}

struct Node* build(int* a, int n)	// Returns linked list data structure using an array as input.
{
	struct Node* current; struct Node* temp;struct Node* head;
	for(int i = 0; i < n; i++)
	{
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = a[i]; temp->link = NULL;
		if(!i)
		{
			current = temp;
			head = current;
			continue;
		}
		current->link = temp;
		current = current->link;
	}
	return head;
}


struct Node* build1(int* a, int n)	// Returns set data structure using an array as input.
{
	struct Node* current; struct Node* temp;struct Node* head = NULL;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == -1)
			continue;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j] == -1)
				continue;
			if(a[i] == a[j])
				a[j] = -1;
		}
		current = (struct Node*)malloc(sizeof(struct Node));
		current->data = a[i]; current->link = NULL;
		if(head == NULL)
		{
			head = current; continue;
		}
		current->link = head;
		head = current;
	}
	return head;
}
