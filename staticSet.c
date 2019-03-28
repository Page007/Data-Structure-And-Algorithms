#include "library.h"

int hashFunction(int value)
{
    return value % 10;  // return key for a given value
}

struct Node** setup(struct Node** hash) // Function for initializing a hash table
{
    hash = (struct Node**)malloc(sizeof(struct Node*)*HASHVAL);
    for(int i = 0; i < HASHVAL; i++)
        hash[i] = NULL;
    return hash;
}

int is_element_of(struct Node** hash, int val)  // Checking whether val is an element of hash in O(1) time.
{
    int key = hashFunction(val);
    if(!hash[key])
        return 0;   // Return false if the record of hash table has not been initialized.
    struct Node* current = hash[key];
    while(current)
    {
        if(current->data == val)
            return 1;   // Return true if value is found
        current= current->link;
    }
    return 0;   // Control reaches here if and only if the element was not found in the hash table.
}

int is_empty(struct Node** hash)
{
    for(int i = 0; i < HASHVAL; i++)
        if(hash[i])
            return 0;   // Check if every record of the hash table is empty or not.
    return 1; 
}

int size(struct Node** hash)
{
    int count = 0;  // Initialize the counter to zero.
    for(int i = 0; i < HASHVAL; i++)
    {
        if(!hash[i])
            continue;   // If the record is NULL, continue with the loop.
        struct Node* current = hash[i];
        while(current)
        {
            count++;
            current = current->link;
        }
        current = NULL;
    }
    return count;   // Return the count of elements in the hash table
}

void enumerate(struct Node** hash)
{
    if(is_empty(hash))  
    {
        printf("The set is empty\n");
        return;                         // Return if the hash table is empty.
    }
    for(int i = 0; i < HASHVAL; i++)
    {
        if(!hash[i])
            continue;
        struct Node* current = hash[i];
        while(current)
        {
            printf("%d ", current->data);
            current = current->link;
        }
    }
    printf("\n");
}

struct Node** build(int* a, int n)
{
    struct Node** hash;
    hash = setup(hash);
    for(int i = 0; i < n; i++)
    {
        if(a[i] == -1)
            continue;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->link = NULL; newNode->data = a[i];
        if(!hash[hashFunction(a[i])])
        {
            hash[i] = newNode;
            continue;
        }
        struct Node* current = hash[hashFunction(a[i])];
        while(current->link)
            current = current->link;
        current->link = newNode;
    }
    return hash;
}

struct Node** build1(int* a, int n) // Modifies the array for the removal of duplicates
{
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
    }
    return build(a, n);
}