#include<stack>
#include<bits/stdc++.h>
#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;

// perNode and DFS constitute the topological sort functions.

void perNode(int** a, int s, bool* visited, int n, stack<int>& res)
{
	if(visited[s])
		return;
	visited[s] = true;
	res.push(s);
	for(int i = 0; i < n; i++)
		if(a[s][i])
			perNode(a, i, visited, n, res);
}
void topologicalSort(int** a, int n)
{
	bool* visited = new bool[n];
	stack<int> res;
	for(int i = 0; i < n; i++)
		visited[i] = false;
	for(int i = 0; i < n; i++)
		perNode(a, i, visited, n, res);
	while(!res.empty())
	{
		cout << res.top() << " ";
		res.pop();
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
void addEdge(int** a, int i, int j)
{
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
int mother(int** a, int n)	// If all the elements are visited in the topological sort, then that element is the mother.
{
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

// Finding if there is a path between any two given nodes in a digraph. And if there is, return the length of the 
// path.

bool findP(int** a, int n, int source, int target, stack<int>& s, bool* visited)
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
				s.push(i); return true;
			}
		}
	}
	return false;
}

void path(int** a, int n, int source, int target)
{
	bool* visited = new bool[n];
	initializeVisited(visited, n);
	stack<int> s;
	bool x = findP(a, n, source, target, s, visited);
	if(x)
	{
		cout << "There is a path : " << source << " "; int count = 0;
		while(!s.empty())
		{
			cout << s.top() << " "; s.pop(); count ++ ;
		}
		cout << "The number of elements in the path are : " << count << endl;
		return;
	}
	cout << "There is no path" << endl;
}

bool findC(int** a, int n, int source, bool* visited, stack<int>& s, vector<int>& v)
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
				s.push(i);
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
	stack<int> s;
	std::vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		initializeVisited(visited, n);
		if(x = findC(a, n, i, visited, s, v))
		{
			cout << "There is a cycle : ";
			while(!s.empty())
			{
				cout << s.top() << " "; s.pop();
			}
			cout << endl; return;
		}
	}
	cout << "There is no cycle" << endl;
}

int main(int argc, char** argv)	
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = atoi(argv[1]);
	int** a = create(atoi(argv[1]));
	
	/*
	topologicalSort(a, n);
	addEdge(a, 7, 6);addEdge(a, 7, 5);addEdge(a, 6, 4);addEdge(a, 6, 3);addEdge(a, 5, 2);addEdge(a, 5, 1);addEdge(a, 4, 0);
	addEdge(a, 0, 1);addEdge(a, 0, 2);addEdge(a, 1, 3);addEdge(a, 1, 4);addEdge(a, 5, 2);addEdge(a, 4, 6);addEdge(a, 6, 0);
	addEdge(a, 5, 6);
	int mom = mother(a, n);
	cout << mom << " ";
	*/
	addEdge(a, 1, 0); addEdge(a, 1, 2); addEdge(a, 1, 4); addEdge(a, 2, 4);
	addEdge(a, 2, 3); addEdge(a, 4, 5);
	cycle(a, n);
	path(a, n, 1, 3);
	return(0);
}