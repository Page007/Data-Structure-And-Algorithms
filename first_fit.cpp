#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX_SPACE 10000
struct Node{
    int startAdd;
    Node* link;
    int length;
};
Node* freeL, *alloc;
void initialize(){
    freeL = new Node;
    freeL->startAdd = 0;
    freeL->link = NULL;
    freeL->length = MAX_SPACE;
    alloc = NULL;
}
// malloc function call should return a starting address to the allocated space.
int mallocFF(int length){
    Node* current = freeL;
    bool flag = false;
    while(current){
        if(current->length >= length){
            // Serve the request;
            flag = true;
            break;
        }
        current = current->link;
    }
    if(!flag)
        return -1;
    // Current now has freeL list pointer that needs to be pointed to.
    Node* newNode = new Node;
    newNode->length = length; newNode->link = NULL; newNode->startAdd = current->startAdd;
    current->startAdd += length;
    current->length -= length;
    if(current->length == 0){
        // Code to remove current from the linked list.
    }
    // Append the newNode to the alloc list.
    current = alloc;
    if(current == NULL)
        alloc = newNode;
    else{
        while(current->link != NULL)
            current = current->link;
        current->link = newNode;
    }
    return newNode->startAdd;
}
void printA(){
    Node* head = alloc;
    while(head){
        cout << " ( "<< head->startAdd << " " << head->length << " ) " << endl;
        head = head->link;
    }
}
void printF(){
    Node* head = freeL;
    while(head){
        cout << " ( " <<  head->startAdd << " " << head->length <<  " ) -> ";
        head = head->link;
    }
    cout << "END" << endl;
}
void myFree(int start_add){
    Node* current = alloc; bool flag = false; Node* parent = current;
    // Check whether the block with this starting address is actually allocated or not
    while(current){
        if(current->startAdd == start_add){
            flag = true; break;
        }
        parent = current;
        current = current->link;
    }
    if(!flag){ cout << "Unable to free" << endl; return;}
    // If the control lands here, it means that the address can be freed.
    // Delete the node from the alloc list.
    if(alloc == current){
        alloc = current->link;
    }else{
        parent->link = current->link;
    }
    current->link = NULL;
    Node* iter = freeL; parent = iter;
    while(iter && current->startAdd + current->length != iter->startAdd){
        parent = iter;
        iter = iter->link;
    }
    if(iter != NULL){
        iter->startAdd = current->startAdd;
        iter->length += current->length;
    }
    else{
        // Insert the node in the correct part of the list according to the 
        // starting address.
        iter = freeL;
        parent = iter;
        if(freeL->startAdd > current->startAdd){
            current->link = freeL; freeL = current; return;
        }
        while(iter && current->startAdd > iter->startAdd){
            parent = iter;
            iter = iter->link;
        }
        if(!iter)
            parent->link = current;
        else
        {
            current->link = iter;
            parent->link = current; return;
        }
    }
}
int main(){
    initialize();
    int a1 = mallocFF(4000);   // Receive the addresses as integers.
    int a2 = mallocFF(3300);
    int a4 = mallocFF(200);
    int a3 = mallocFF(1500);
    myFree(a1); 
    myFree(a2);
    myFree(a3);
    a1 = mallocFF(150); 
    cout << "Printing Alloc List : " << endl;
    printA();
    cout << "Printing freeL List : " << endl;
    printF();
    return(0);
}