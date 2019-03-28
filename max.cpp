#include<vector>
#include<bits/stdc++.h>
using namespace std;

class graph
{
	int V;
	list<int> *adj;
	vector<int> indegree;
	vector<int> topoSort();
	
	public:
		graph(int V);
		void addEdge(int v, int w);
		int maxEdgeAdd();
};

graph::graph(int v)
{
	this->V = v;
	adj = new list<int>[v];
	for(int i =0 ;i<v;i++)
	{
		indegree.push_back(0);
	}
}

void graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	indegree[w]++;
}

vector<int> graph::topoSort()
{
	vector<int> topo;
	queue<int> q;
	for(int i = 0;i < V;i++)
	{
			if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		topo.push_back(t);
		for(list<int>::iterator j = adj[t].begin();j!= adj[t].end();j++)
		{
			indegree[*j]--;
			if(indegree[*j]==0)
			{
				q.push(*j);
			}
		}
	}
	return topo;
}

int graph::maxEdgeAdd()
{
	bool *visited = new bool[V];
	vector<int> topo = topoSort();	// returns the topological sorted order from the graph.
	int count = 0;
	for(int i=0;i < topo.size();i++)
	{
		int t = topo[i];
		for(list<int>:: iterator j = adj[t].begin(); j!= adj[t].end(); j++)
		{
			visited[*j] = true;
		}
		for(int j = i + 1;j < topo.size();j++)
		{
			if(!visited[topo[j]])
			{
				count++;
				cout<<t<<"-"<<topo[j]<<" ";
			}
			visited[topo[j]] =false;
		}
	}
	return count;
}

int main()
{
	graph g(6);
	g.addEdge(5,2);
	g.addEdge(5,0);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);
	int edges = g.maxEdgeAdd();
	cout << "Edges = " << edges << endl;
	return 0;
}