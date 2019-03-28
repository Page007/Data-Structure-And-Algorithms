#include "utility.h"

int main()
{
	int b[5] = {1, 2, 3, 4, 34};
	struct Node* s1 = build(b, 5);
	
	//verify(is_element_of(s1, 1));
	
	//verify(is_empty(s1));
	
	int arr[2] = {1, 1};
	struct Node* newS = build1(arr, 2);
	enumerate(newS);
	//printf("Cardinality = %d\n", cardinality(s1));
	
	// Static Functions till here
	
	//struct Node* s2 = create();
	
	//printf("Cardinality = %d\n", cardinality(s2));
	struct Node* s3 = NULL;
	//s3 = add(s3, 22);
	s3 = add(s3, 4);
	s3 = add(s3, 1);
	//s3 = add(s3, 25);
	s3 = add(s3, 3);
	//enumerate(s1);
	//enumerate(s3);
	struct Node* s4 = NULL;
	// Finding the union
	
	//s4 = getUnion(s1, s3);
	//enumerate(s4);
	
	// Finding the intersection
	
	/*
	if(getIntersection(s1, s3))
		enumerate(getIntersection(s1, s3));
	else
		printf("The intersection of the lists is NULL set\n");
	
	if(!difference(s1, s3))
		printf("Difference of the sets is a NULL set\n");
	else
		enumerate(difference(s1, s3));
	*/
	struct Node* u1 = NULL;
	u1 = add(u1,1);u1 = add(u1,2);u1 = add(u1,3);u1 = add(u1,4);u1 = add(u1,5);
	struct Node* u2 = NULL; u2 = add(u2, 22);

	if(!subset(u2, u1))
		printf("u2 is not a subset of u1\n");
	else
		printf("u2 is a subset of u1\n");
		
	return(0);
}
void verify(int p)
{
	if(p)
		printf("Yes\n");
	else
		printf("No\n");
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;
	else
		return n2;
}
