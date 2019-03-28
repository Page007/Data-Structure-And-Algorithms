
#include "utility.h"


struct Node* getUnion(struct Node* head1, struct Node* head2)
{
	
	
	struct Node* result = NULL;

	struct Node* c1 = head1, *c2 = head2;
	
	while(c1)
	{
		result = add(result, c1->data);	// Copy a set into result.
		c1 = c1->link;
	}
	while(c2)
	{
		if(!is_element_of(result, c2->data))	// Check for presence of every element of c2 in result
			result = add(result, c2->data);
		c2 = c2->link;
	}
	return result;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2)	
{
	struct Node* result = NULL;
	struct Node* c1 = head1, *c2 = head2;
	if(!head1 || !head2)
		return NULL;	// Return if any of the sets are empty.
	while(c1)
	{
		if(is_element_of(c2, c1->data))
			result = add(result, c1->data);	// If data of c1 is also an element of c2, add that into the result.
		c1 = c1->link;
	}
	return result;
}

struct Node* difference(struct Node* head1, struct Node* head2)
{
	if(!getIntersection(head1, head2))
		return NULL;	// If both sets are disjoint, no difference is possible.
	struct Node* c1 = head1, *c2 = head2;
	struct Node* result = NULL;
	while(c1)
	{
		if(!is_element_of(c2, c1->data))	// If data of c1 is not an element of c2, then add it to the result.
			result = add(result, c1->data);
		c1 = c1->link;
	}
	return result;
}

int subset(struct Node* s, struct Node* t)
{
	// Finding whether 's' is a subset of 't' or not.
	if(s == NULL)
		return 1;	// An empty set is a subset of every set. Hence return 1 is 's' is empty.
	struct Node* sub = s;
	struct Node* sup = t;
	while(sub)
	{
		if(!is_element_of(sup, sub->data))	// Check if every element of sub is present in sup.
			return 0;
		sub = sub->link;
	}
	return 1;
}