#include<bits/stdc++.h>
#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;

// perNode and DFS constitute the topological sort functions->

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

void perNode(int** a, int s, bool* visited, int n, Stack* res)
{
	if(visited[s])
		return;
	visited[s] = true;
	res->push(s);
	for(int i = 0; i < n; i++)
		if(a[s][i])
			perNode(a, i, visited, n, res);
}
void topologicalSort(int** a, int n)
{
	bool* visited = new bool[n];
	Stack* res = new Stack();
	for(int i = 0; i < n; i++)
		visited[i] = false;
	for(int i = 0; i < n; i++)
		perNode(a, i, visited, n, res);
	while(!res->isEmpty())
	{
		cout << res->t() << " ";
		res->pop();
	}
}
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
void addEdge(int** a, int i, int j, int n)
{
	if(i > n || j > n)
	{
		cout << "Invalid Edge choice" << endl; return;
	}
	if(a[i][j])
	{
		cout << "Edge already exists" << endl; return;
	}
	a[i][j] = 1;
}
void initializeVisited(bool* visited, int n)
{
	for(int i = 0; i < n; i++)
		visited[i] = false;
}
bool isAllVisited(bool* v, int n)
{
	for(int i = n - 1; i; i--)
		if(!v[i])
			return false;
	return true;
}
void explore(int** a, int s, bool* visited, int n, bool* count)
{	
	if(visited[s])
		return;
	visited[s] = true;
	if(isAllVisited(visited, n))
	{
		*count = true;
		return;
	}
	for(int i = 0; i < n; i++)
		if(a[s][i])
			explore(a, i, visited, n, count);
}
int mother(int** a, int n)	// If all the elements are visited in the topological sort, then that element is the mother->
{
	bool flag = false;
	// Initially check for disconnected graphs.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j])
			{
				flag = true; break;
			}
	if(!flag)
	{
		cout << "The graph contains a disconnection" << endl; return -1;
	}

	bool* visited = new bool[n];
	bool* count = new bool; *count = false;
	for(int i = 0; i < n; i++)
	{
		initializeVisited(visited, n);
		explore(a, i, visited, n, count);
		if(*count == true)
			return i;
	}
	return -1;
}

// Finding if there is a path between any two given nodes in a digraph-> And if there is, return the length of the 
// path->

bool findP(int** a, int n, int source, int target, Stack* s, bool* visited)
{
	if(visited[source])
		return false;
	if(source == target)
		return true;
	visited[source] = true;
	for(int i = 0; i < n; i++)
	{
		if(a[source][i])
		{
			if(findP(a, n, i, target, s, visited))
			{
				s->push(i); return true;
			}
		}
	}
	return false;
}

void path(int** a, int n, int source, int target)
{
	bool* visited = new bool[n];
	initializeVisited(visited, n);
	Stack* s = new Stack();
	bool x = findP(a, n, source, target, s, visited);
	if(x)
	{
		cout << "There is a path : " << source << " "; int count = 0;
		while(!s->isEmpty())
		{
			cout << s->t() << " "; s->pop(); count ++ ;
		}
		cout << "The number of elements in the path are : " << count << endl;
		return;
	}
	cout << "There is no path" << endl;
}

bool findC(int** a, int n, int source, bool* visited, Stack* s, vector<int>& v)
{
	if(visited[source] && std::find(v.begin(), v.end(), source) != v.end())
		return true;
	visited[source] = true;
	for(int i = 0; i < n; i++)
	{
		if(a[source][i])
		{
			if(findC(a, n, i, visited, s, v))
			{
				v.push_back(i);
				s->push(i);
				return true;
			}
		}
	}
	return false;
}
void cycle(int** a, int n)
{
	bool* visited = new bool[n];
	bool x;
	Stack* s = new Stack();
	std::vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		initializeVisited(visited, n);
		if(x = findC(a, n, i, visited, s, v))
		{
			cout << "There is a cycle : ";
			while(!s->isEmpty())
			{
				cout << s->t() << " "; s->pop();
			}
			cout << endl; return;
		}
	}
	cout << "There is no cycle" << endl; delete visited, v; 
}


bool biGraphUtility(int** a, int n, int source, bool* colour, bool* visited, bool prev)
{
	if(visited[source] && colour[source] == prev)
		return false;
	if(!visited[source])
	{
		visited[source] = true;
		colour[source] = !prev;
		prev = !prev;
	}
	for(int i = 0; i < n; i++)
		if(a[source][i])
			if(!biGraphUtility(a, n, i, colour, visited, colour[source]))
				return false;
	return true;
}

void biGraph(int** a, int n)
{
	
	bool* visited = new bool[n];
	initializeVisited(visited, n);
	for(int i = 0; i < n; i++)
		if(a[i][i])
		{
			cout << "There is a self loop, so not Bipartite" << endl;
			return;
		}
	bool* colour = new bool[n]; initializeVisited(colour, n);
	if(biGraphUtility(a, n, 0, colour, visited, false))
	{
		cout << "The graph is a Bipartite Graph" << endl; return;
	}
	cout << "The graph is not a Bipartite Graph" << endl;
	delete colour;
}





//Function for finding MOM in V^2 time. (Kosaraju's strongly connected Algorithm)

void DFS(int** a, int n, bool* visited, int source)
{
	if(visited[source])
		return;
	visited[source] = true;
	for(int i = 0; i < n; i++)
		if(a[source][i])
			DFS(a, n, visited, i);	
}

int mom(int** a, int n)
{
	bool* visited = new bool[n];
	initializeVisited(visited, n);
	int last = 0; int v;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			v = i; DFS(a, n, visited, i);
		}
	}
	initializeVisited(visited, n);
	DFS(a, n, visited, v);
	for(int i = 0; i < n; i++)
		if(!visited[i])
			return -1;
	return v;
}

bool u(int** a, int n, int source, bool* visited, bool* stack)
{
	if(stack[source] == false)
	{
		visited[source] = true; stack[source] = true; // Maintain the recursion stack.
		for(int i = 0; i < n; i++)
			if(a[source][i])
			{
				if((!visited[i] && u(a, n, i, visited, stack)) || stack[i])
					return true;
			}
	}
	stack[source] = false;
	return false;
}

void isCycle(int** a, int n)
{
	bool* visited = new bool[n](); bool* stack = new bool[n]();
	//initializeVisited(visited, n); initializeVisited(stack, n);
	for(int i = 0; i < n; i++)
		if(u(a, n, i, visited, stack))
		{
		 	cout << "There is a cycle in the graph" << endl;
		 	return;
		}	
	cout << "There is no cycle in the graph" << endl;
	return;
}



int main(int argc, char** argv)	
{
	int n = atoi(argv[1]);
	int** a = create(atoi(argv[1]));	
	
	//topologicalSort(a, n);
	//addEdge(a, 7, 6, n);addEdge(a, 7, 5, n);addEdge(a, 6, 4, n);addEdge(a, 6, 3,n);addEdge(a, 5, 2, n);
	//addEdge(a, 5, 1, n);addEdge(a, 4, 0, n);
	//int MOM = mother(a, n);
	//cout << MOM << " ";
	
	//addEdge(a, 0, 1, n); addEdge(a, 1, 2, n);addEdge(a, 2, 0, n);
	//cycle(a, n);
	//path(a, n, 1, 2);
	//biGraph(a, n);
	addEdge(a, 0, 1, n); addEdge(a, 0, 2,n); addEdge(a, 2, 3, n); addEdge(a, 2, 4, n); addEdge(a, 4, 1, n);
	isCycle(a, n);
	return(0);
}