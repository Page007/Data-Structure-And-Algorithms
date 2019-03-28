#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* link;
};
Node* createNode(int tData)
{
    Node* newN = new Node;
    newN->data = tData;
    newN->link = NULL;
    return newN;
}
Node* insert(Node* head, int tData)
{
    Node* newN = createNode(tData);
    if(!head)
        return newN;
    Node* current = head;
    while(current)
        current = current->link;
    current = newN;
    return head;
}
void print(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->link;
    }
    cout << endl;
}
int countNodes(Node* head)
{
    int c = 0;
    while(head)
    {
        c += 1;
        head = head->link;
    }
    return c;
}
Node* minimumList(Node* head1, Node* head2)
{
    if(countNodes(head1) < countNodes(head2))
        return head1;
    else
        return head2;
}
Node* addLists(Node* list1, Node* list2)
{
    Node* list3 = NULL; Node* newN; 
    while(list1 && list2)
    {
        newN = createNode(list1->data + list2->data);
        newN->link = list3;
        list3 = newN;
        list1 = list1->link;
        list2 = list2->link;
    }
    if(list1 == NULL)
    {
        while(list2)
        {
            newN = createNode(list2->data);
            newN->link = list3;
            list3 = newN;
            list2 = list2->link;
        }
    }
    if(list2 == NULL)
    {
        while(list1)
        {
            newN = createNode(list1->data);
            newN->link = list3;
            list3 = newN;
            list1 = list1->link;
        }
    }
    return list3;
}
int main()
{
    Node* l1 = NULL, *l2 = NULL;
    l1 = insert(l1, 10);l1 = insert(l1, 12);l1 = insert(l1, 9);l1 = insert(l1, 5);l1 = insert(l1, 3);
    l2 = insert(l2, 23);l2 = insert(l2, 56);l2 = insert(l2, 12);l2 = insert(l2, 77);l2 = insert(l2, 1);
    l2 = insert(l2, );
}