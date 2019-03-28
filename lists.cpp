#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node* link;
    Node(int tData)
    {
        data = tData;
        link = NULL;
    }
};
class Stack
{
public:
    Node* top;
    Stack(){top = NULL;}
    bool isEmpty()
    {
        if(top == NULL)
            return true;
        return false;
    }
    void push(int tData)
    {
        Node* newN = new Node(tData);
        if(isEmpty())
        {
            top = newN; return;
        }
        newN->link = top;
        top = newN; 
    }
    void pop()
    {
        if(isEmpty())
            return;
        Node* temp = top;
        top = top->link;
        temp->link = NULL;
        delete temp;
    }
    int t()
    {
        if(isEmpty())
            return(0);
        return top->data;
    }
    int size()
    {
        Node* temp = top;
        int s = 0;
        while(temp)
        {
            s++; temp = temp->link;
        }
        return s;
    }
};
class Graph
{
public:
    int n; vector<int>* adj; bool dir; 
    Graph(int n, bool flag)
    {
        this->n = n;
        adj = new vector<int>[n];
        dir = flag;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        if(dir)
            return;
        adj[v].push_back(u);
    }
    void u(int v, bool* visited, Stack* s)
    {
        visited[v] = true;
        vector<int>::iterator i;
        for(i = adj[v].begin(); i!= adj[v].end(); i++)
            if(!visited[*i])
                u(*i, visited, s);
        s->push(v);
    }
    Stack* topo()
    {
        Stack* s=  new Stack();
        bool* visited = new bool[n];
        for(int i = 0; i < n; i++)
            visited[i] = false;
        for(int i = 0; i < n; i++)
            if(!visited[i])
                u(i, visited, s);
        delete visited;
        return s;
    }
    bool undirUtility(int v, bool* visited, int parent)
    {
        visited[v] = true;
        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
                if(undirUtility(*i, visited, v))
                    return true;
            else if(*i != parent)
                return true;
        }
        return false;
    }
    bool undirCyclic()
    {
        bool* visited = new bool[n];
        for(int i = 0; i < n; i++)
            visited[i] = false;
        for(int i = 0; i < n; i++)
            if(!visited[i])
                if(undirUtility(i, visited, -1))
                    return true;
        return false;
    }
};
int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    Graph g(6, false);   // Initiate a directed graph.
    g.addEdge(5, 2); 
    g.addEdge(5, 0);g.addEdge(2, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);
    /*
    if(g.undirCyclic())
        cout << "There is a cycle in this undirected graph" << endl;
    else
        cout << "There is not a cycle in this undirected graph" << endl;
    */
    Stack* s = g.topo();
    return(0);
}