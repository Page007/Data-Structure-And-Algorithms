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
int mallocBF(int length){
    int min = __INT_MAX__; Node* minPointer = freeL;
    Node* current = freeL; bool flag = false;
    // Check whether space is available or not
    while(current){
        if(current->length > length){
            flag = true;
            break;
        }
        current = current->link;
    }
    if(flag == false)
        return -1;
    current = freeL;
    while(current){
        if(current->length < min && current->startAdd + current->length < 10000){   // Ensure to avoid overflow
            min = current->length;
            minPointer = current;
        }
        current = current->link;
    }  
    Node* newN = new Node;
    newN->length = length;
    newN->link = NULL;
    newN->startAdd = minPointer->startAdd;
    minPointer->length -= length;
    minPointer->startAdd += length;
    // Insert the Node in the end of the alloc list.
    if(alloc == NULL){
        alloc = newN;
        return alloc->startAdd;
    }
    current = alloc;
    while(current->link)
        current = current->link;
    current->link = newN;
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
    int a1 = mallocBF(5000);   // Receive the addresses as integers.
    int a2 = mallocBF(2000);
    int a3 = mallocBF(2500); /*cout << "( " << a1 << " " << a2 << " " << a3 << " )" << endl; */
    myFree(a1); 
    a1 = mallocBF(800);
    myFree(a2);   myFree(a3); a2 = mallocBF(2000);
    cout << "Printing Alloc List : " << endl;
    printA();
    cout << "Printing freeL List : " << endl;
    printF();
    return(0);
}