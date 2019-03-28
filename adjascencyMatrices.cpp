#include<iostream>
#include<stdlib.h>
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
class Queue
{
public:
	Node* front, *rear;
	Queue(){front = rear = NULL;}
	bool isEmpty()
	{
		if(front == NULL)
			return true;
		return false;
	}
	void push(int tData)
	{
		Node* newN = new Node(tData);
		if(isEmpty())
		{
			front = rear = newN;
			return;
		}
		rear->link = newN;
		rear = rear->link;
	}
	void pop()
	{
		if(isEmpty())
			return;
		front = front->link;
	}
	int f()
	{
		if(isEmpty())
			return(0);
		return front->data;
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
};
int** create(int n)
{
	// recieve the number of nodes in the function
	int** a = new int*[n];
	for(int i = 0; i < n; i++)
		a[i] = new int[n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = 0;
	return a;
}
void addEdge(int** a, int i, int j)
{
	if(a[i][j])
	{
		cout << "Edge already exists" << endl; return;
	}
	a[i][j] = a[j][i] = 1;
}
void printDisconnected(int** a, int n)
{
	bool flag = true;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j])
			{
				flag = false;
				break;
			}
		}
		if(flag)
			cout << i << " ";
	}
}
void bfs(int** a, int n)
{
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;
	Queue* q = new Queue();
	cout << "Enter the element that you want to start with" << endl;
	int start;
	cin >> start;
	q->push(start);
	visited[start] = true;
	while(!q->isEmpty())
	{
		int x = q->f();
		cout << x << " ";
		q->pop();
		for(int i = 0; i < n; i++)
		{
			if(a[x][i] && !visited[i])
			{
				q->push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
	delete visited;
	printDisconnected(a, n);
}
void dfs(int** a, int n)
{
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;
	Stack* s = new Stack();
	cout << "Enter the element that you want to start with" << endl;
	int start; cin >> start;
	s->push(start);
	visited[start] = true;
	while(!s->isEmpty())
	{
		int x = s->t();
		cout << x << " ";
		s->pop();
		for(int i = 0; i < n; i++)
		{
			if(a[x][i] && !visited[i]) // If there is an  edge and not visited ith node,
									   // then control enters here.
			{
				s->push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
	delete visited;
	printDisconnected(a, n);
}
int main(int argc, char** argv)
{
	int n = atoi(argv[1]);
	int** graph = create(n);
	int** a = graph;
	addEdge(a, 5, 0);addEdge(a, 4, 0);addEdge(a, 4, 1);addEdge(a, 3, 1); addEdge(a, 2, 3);addEdge(a, 5, 2);	bfs(graph, n); 			// Performing the Breadth First Search
	dfs(graph, n); 			// Performing the Depth First Search
}