#include "library.h"
int main()
{
    // Call build1 for the static set building.
    int a[5] = {1, 4, 4, 4, 4}; 
    struct Node** hash = build1(a, 5);
    enumerate(hash);
    /*
    if(is_element_of(hash, 23))
        printf("23 is an element of hash\n");
    else
        printf("23 is not an element of hash\n");
    if(is_empty(hash))
        printf("hash is empty\n");
    else
        printf("hash is not empty\n");
    printf("Declaring the second hash\n");
    struct Node** hash1;
    hash1 = setup(hash1);
    if(is_empty(hash1))
        printf("The second hash is empty\n");
    else
        printf("The second hash is not empty\n");
    int s = size(hash1);
    printf("The size of the hash is %d\n", s);
    */
    /*
    struct Node** dynamicSet;
    dynamicSet = create(dynamicSet);
    dynamicSet = add(dynamicSet, 10); 
    printf("1st element inserted\n");
    dynamicSet = add(dynamicSet, 20);
    dynamicSet = add(dynamicSet, 30);
    //enumerate(dynamicSet);
    dynamicSet = add(dynamicSet, 10);
    dynamicSet = add(dynamicSet, 23);
    dynamicSet = deleteNode(dynamicSet, 23);
    enumerate(dynamicSet);
    */
    // Deploying Special Ops : 
    struct Node** dSet;
    dSet = create(dSet);
    //dSet = add(dSet, 11);
    //dSet = add(dSet, 12);
    dSet = add(dSet, 30);
    dSet = add(dSet, 4);
    dSet = add(dSet, 33);
    //enumerate(dSet);
    struct Node** dSet1;
    dSet1 = create(dSet1);
    dSet1 = add(dSet1, 20);
    dSet1 = add(dSet1, 30);
    dSet1 = add(dSet1, 10);
    dSet1 = add(dSet1, 4);
    dSet1 = add(dSet1, 33);
    struct Node** dSet2;
    dSet2 = difference(dSet1, dSet);
    enumerate(dSet);
    printf("\n");
    enumerate(dSet1);
    printf("\n");
    enumerate(dSet2);
    //printf("\n");
    printf("Checking whether set 1 is a subset of set 2 or not\n");
    if(is_subset(dSet, dSet1))
        printf("dSet is a subset of dSet1\n");
    else
        printf("dSet is not a subset of dSet1\n");
    return(0);
}