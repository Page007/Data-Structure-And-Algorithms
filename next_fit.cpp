#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX_SPACE 10000
struct Node{
    int startAdd;
    Node* link;
    int length;
};
Node* freeL, *alloc, *nextPtr;  // Points to the next Node to be checked
void initialize(){
    freeL = new Node;
    freeL->startAdd = 0;
    freeL->link = NULL;
    freeL->length = MAX_SPACE;
    alloc = NULL;
    nextPtr = freeL;
}
// malloc function call should return a starting address to the allocated space.
int mallocNF(int length){
    // Check whether space is available or not
    Node* current = nextPtr; bool flag = false;
    while(current){
        if(current->length > length){
            flag = true;
            break;
        }
        current = current->link;
    }
    Node* temp = freeL;
    if(!flag){
        while(temp != nextPtr){
            if(temp->length > length){
                flag = true; break;
            }
            temp = temp->link;
        }
    }
    if(!flag)
        return -1;
    if(!current)
        current = temp;
    else
        temp = NULL;    // Remove unwanted pointers.
    Node* newN = new Node;
    newN->length = length; newN->link = NULL; newN->startAdd = current->startAdd;
    current->startAdd += length;
    current->length -= length;
    /* nextPtr = current; */
    if(current->link == NULL)
        nextPtr = freeL;
    else
        nextPtr = current->link;
    Node* stray = alloc;
    if(alloc == NULL){
        alloc = newN;
        return alloc->startAdd;
    }
    while(stray->link)
        stray = stray->link;
    stray->link = newN;
    return newN->startAdd;
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
    int a1 = mallocNF(4000);   // Receive the addresses as integers.
    int a2 = mallocNF(2000);
    int a3 = mallocNF(3000); /*cout << "( " << a1 << " " << a2 << " " << a3 << " )" << endl; */
    myFree(a1); 
    a1 = mallocNF(50);
/*     cout << nextPtr->startAdd << endl; */
    myFree(a2);myFree(a3);
    mallocNF(2000);
    cout << "Printing Alloc List : " << endl;
    printA();
    cout << "Printing freeL List : " << endl;
    printF();
    return(0);
}