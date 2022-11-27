/*
 * Problem Statement :-
 * 	Implement depth first search algorithm and Breadth First Search algorithm, Use an
 * 	undirected graph and develop a recursive algorithm for searching all the vertices
 * 	of a graph or tree data structure
*/

#include<bits/stdc++.h>
#include<iomanip>
using namespace std;


class Node
{
	private:
		int vertex;
		Node* next;
	public:
		Node()
		{
			vertex = -1;
			next = NULL;
		}
		Node(int v)
		{
			vertex = v;
			next = NULL;
		}
		friend class Graph;
		~Node() {}
};

class Graph
{
	private:
		int vertices, edges;
		Node** adjlist;
	public:
		Graph()
		{
			vertices = 1;
			edges = 0;
			adjlist = new Node*[vertices];
			for(int i=0; i<vertices; i++)
			{
				adjlist[i] = NULL;
			}
		}
		Graph(int v, int e)
		{
			vertices = v;
			edges = e;
			adjlist = new Node*[vertices];
			for(int i=0; i<vertices; i++)
			{
				adjlist[i] = NULL;
			}
		}
		void acceptUndirectedGraph();
		void displayAdjList();
		void dfsTraversal(int);
		void dfsHelper(int, bool[]);
		void bfsTraversal(int);
		~Graph()
		{
		}
};

void Graph::acceptUndirectedGraph()
{
	int source,destination;
	for(int i=0; i<edges; i++)
	{
		cout<<"\n\t Enter "<<i+1<<" edge"<<endl;
		cout<<"\n\t Enter source vertex : ";
		cin>>source;
		cout<<"\n\t Enter destination vertex : ";
		cin>>destination;
		if(adjlist[source] == NULL)
		{
			adjlist[source] = new Node(destination);
		}
		else
		{
			Node* temp = adjlist[source];
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new Node(destination);
		}

		if(adjlist[destination] == NULL)
		{
			adjlist[destination] = new Node(source);
		}
		else
		{
			Node* temp = adjlist[destination];
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new Node(source);
		}
	}
}

void Graph::dfsHelper(int start, bool visited[])
{
	visited[start] = true;
	cout<<start<<" ";
	for(Node* itr=adjlist[start]; itr!=NULL; itr=itr->next)
	{
		if(!visited[itr->vertex])
		{
			dfsHelper(itr->vertex, visited);
		}
	}
}

void Graph::dfsTraversal(int start)
{
	bool visited[vertices] = {false};
	dfsHelper(start, visited);
}

void Graph::bfsTraversal(int start)
{
	queue<int> q;
	bool visited[vertices] = {false};
	visited[start] = true;
	q.push(start);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		cout<<temp<<" ";
		for(Node* itr=adjlist[temp]; itr!=NULL; itr=itr->next)
		{
			if(!visited[itr->vertex])
			{
				visited[itr->vertex] = true;
				q.push(itr->vertex);
			}
		}
	}
}

void Graph::displayAdjList()
{
	cout<<"\n\t Adjacency List : \n"<<endl;
	for(int i=0; i<vertices; i++)
	{
		cout<<"\t "<<i<<"==> ";
		for(Node* itr = adjlist[i]; itr!=NULL; itr = itr->next)
		{
			cout<<itr->vertex<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int vertices,edges,choice,start;
	cout<<"\n\t Enter number of vertices in graph : ";
	cin>>vertices;
	cout<<"\n\t Enter number of edges in graph : ";
	cin>>edges;
	Graph g1(vertices, edges);
	g1.acceptUndirectedGraph();
	while(true)
	{
		cout<<"\n\t ===Menu=== \n\t\t 1. DFS Traversal \n\t\t 2. BFS Traversal \n\t\t 3. Display Adjacency list \n\t\t 4. Exit"<<endl;
		cout<<"\n\t Enter choice : ";
		cin>>choice;
		if(choice == 1)
		{
			cout<<"\n\t Enter starting vertex number for traversal : ";
			cin>>start;
			cout<<"\n\t DFS Traversal : ";
			g1.dfsTraversal(start);
			cout<<endl;
		}
		else if(choice == 2)
		{
			cout<<"\n\t Enter vertex number for traversal : ";
			cin>>start;
			cout<<"\n\t BFS Traversal : ";
			g1.bfsTraversal(start);
			cout<<endl;
		}
		else if(choice == 3)
		{
			g1.displayAdjList();
		}
		else if(choice == 4)
		{
			cout<<"\n\n\t\tThank You !!!.."<<endl;
			break;
		}
		else
		{
			cout<<"\n\t Invalid choice..!!"<<endl;
		}
	}
}
