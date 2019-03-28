#include "library.h"

struct Node** create(struct Node** hash)
{
    hash = (struct Node**)malloc(HASHVAL*(sizeof(struct Node*)));
    for(int i = 0; i < HASHVAL; i++)
        hash[i] = NULL;
    return hash;
}

struct Node** add(struct Node** hash, int tData)
{
    if(is_element_of(hash, tData))
    {
        return hash;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->link = NULL;
    newNode->data = tData;
    struct Node* current = hash[hashFunction(tData)];
    if(!current)
    {
        hash[hashFunction(tData)] = newNode;
        return hash;
    }
    while(current->link)
        current = current->link;
    current->link = newNode;
    return hash;
}

struct Node** deleteNode(struct Node** hash, int tData)
{
    if(!is_element_of(hash, tData))
    {
        printf("The element %d was not present in the list\n", tData);
        return hash;
    }
    struct Node* current = hash[hashFunction(tData)];
    struct Node* prev = current;
    if(current->data == tData)
    {
        hash[hashFunction(tData)] = current->link;
        current->link = NULL;
        free(current);
        return hash;
    }
    current = current->link;
    while(current)
    {
        if(current->data == tData)
        {
            prev->link = current->link;
            current->link = NULL;
            free(current);
            return hash;
        }
        current = current->link;
        prev = prev->link;
    }
}

struct Node** unionOfSets(struct Node** hash1, struct Node** hash2)
{
    if(is_empty(hash1))
        return deepCopy(hash2);
    if(is_empty(hash2))
        return deepCopy(hash1);
    struct Node** hash3;
    hash3 = deepCopy(hash1);
    struct Node* current;
    for(int i = 0; i < HASHVAL; i++)
    {
        current = hash2[i];        
        while(current)
        {
            if(!is_element_of(hash1, current->data))
                hash3 = add(hash3, current->data);
            current = current->link;
        }
    }
    return hash3;
}

struct Node** deepCopy(struct Node** hash)
{
    struct Node** hash3 = create(hash3);
    for(int i = 0; i < HASHVAL; i++)
    {
        struct Node* current = hash[i];
        if(!current)
            continue;
        while(current)
        {
            hash3 = add(hash3, current->data);
            current = current->link;
        }
    }
    return hash3;
}

struct Node** intersectionOfSets(struct Node** hash1, struct Node** hash2)
{
    if(is_empty(hash1) || is_empty(hash2))
    {
        printf("The intersection is NULL\n");
        struct Node** nullHash;
        return create(nullHash);
    }
    struct Node** hash3;
    hash3 = create(hash3);
    struct Node* current;
    for(int i = 0; i < HASHVAL; i++)
    {
        current = hash2[i];        
        while(current)
        {
            if(is_element_of(hash1, current->data) && is_element_of(hash2, current->data))
                hash3 = add(hash3, current->data);
            current = current->link;
        }
    }
    return hash3;
}

struct Node** difference(struct Node** hash1, struct Node** hash2)
{
    // Finding the difference between hash1 and hash2 i.e. hash1 - hash2 = hash3
    if(is_empty(hash1))
    {
        printf("Error in subtraction\n");
        struct Node** nullHash; nullHash = create(nullHash);
        return nullHash;
    }
    struct Node** hash3= deepCopy(hash1);
    struct Node* current;
    for(int i = 0; i < HASHVAL; i++)
    {
        current = hash3[i];
        if(!current)
            continue;
        while(current)
        {
            if(is_element_of(hash2, current->data))
                deleteNode(hash3, current->data);
            current = current->link;
        }
    }
    return hash3;
}

int is_subset(struct Node** hash1, struct Node** hash2)
{
    // Checking whether hash1 is a subset of hash2 or not
    struct Node* current;
    if(is_empty(hash1))
        return 1;
    if(is_empty(hash2))
        return 0;
    for(int i = 0; i < HASHVAL; i++)
    {
        current = hash1[i];
        if(!current)
            continue;
        while(current)
        {
            if(!is_element_of(hash2, current->data))
                return 0;
            current = current->link;
        }
    }
    return 1;
}