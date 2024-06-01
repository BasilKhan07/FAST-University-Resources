#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Nodes{
	public:
		int data;
		Nodes *next;
		
		Nodes()
		{
			data = 0;
			next = NULL;
		}
		
		Nodes(int val)
		{
			data = val;
			next = NULL;
		}
};

class Edges{
	public:
		int source, destination;
};

class Graph{
	public:
		Nodes **head;
		int N;
		
		Graph()
		{
			head = NULL;
			N = 0;
		}
		
		Graph(Edges edge[], int NumberOfNodes, int NumberOfEdges)
		{
			head = new Nodes*[N];
			N = NumberOfNodes;
			for(int i=0; i<N; i++)
			{
				head[i] = NULL;
			}
			for(int i=0; i<NumberOfEdges; i++)
			{
				int source = edge[i].source;
				int destination = edge[i].destination;
				Nodes *n1 = AddEdge(head[source], destination);
				head[source] = n1;
//				Nodes *n2 = AddEdge(head[destination], source);
//				head[destination] = n2;
			}
		}
		
		Nodes* AddEdge(Nodes *headsource, int destination)
		{
			Nodes *n = new Nodes(destination);
			n->next = headsource;
			return n;
		}
		
		void BFS(int s)
		{
			bool *visited = new bool[N];
			for(int i=0; i<N; i++)
			{
				visited[i] = false;
			}
			list<int> queue;
			queue.push_back(s);
			visited[s] = true;
			while(!queue.empty())
			{
				s = queue.front();
				queue.pop_front();
				cout << s << " ";
				for(Nodes *temp = head[s]; temp!=NULL; temp = temp->next)
				{
					if(!visited[temp->data])
					{
						visited[temp->data] = true;
						queue.push_back(temp->data);
					}
				}
			}	
		}
		
		void DFS(int s)
		{
			bool *visited = new bool[N];
			for(int i=0; i<N; i++)
			{
				visited[i] = NULL;
			}
			stack<int> s1;
			s1.push(s);
			while(!s1.empty())
			{
				s = s1.top();
				s1.pop();
				if(!visited[s])
				{
					visited[s] = true;
					cout << s << " ";
					for(Nodes *temp = head[s]; temp!=NULL; temp = temp->next)
					{
						if(!visited[temp->data])
						{
							s1.push(temp->data);
						}
					}
				}
			}
		}
		
		bool CheckCycleBFS(int s)
		{
			int *visited = new int[N];
			for(int i=0; i<N; i++)
			{
				visited[i] = -1;
			}
			list<int> queue;
			queue.push_back(s);
			visited[s] = 0;
			while(!queue.empty())
			{
				s = queue.front();
				queue.pop_front();
				for(Nodes *temp = head[s]; temp!=NULL; temp = temp->next)
				{
					if(visited[temp->data] == -1)
					{
						visited[temp->data] = 0;
						queue.push_back(temp->data);
					}
					else if(visited[temp->data] == 0)
					{
						return true;
					}
				}
				visited[s] = 1;
			}
			return false;
		}
		
		bool CheckCycleDFS(int s)
		{
			int *visited = new int[N];
			for(int i=0; i<N; i++)
			{
				visited[i] = -1;
			}
			stack<int> s1;
			s1.push(s);
			visited[s] = 0;
			while(!s1.empty())
			{
				s = s1.top();
				s1.pop();
				if(visited[s]!=1)
				{
					visited[s] = 1;
					for(Nodes *temp = head[s]; temp!=NULL; temp = temp->next)
					{
						if(visited[temp->data] == -1)
						{
							s1.push(temp->data);
							visited[temp->data] = 0;
						}
						else if(visited[temp->data] == 0)
						{
							return true;
						}
					}
				}
			}
			return false;
		}
		
		~Graph()
		{
			for(int i=0; i<N; i++)
			{
				delete[] head[i];
			}
			delete head;
		}
};

void PrintList(Nodes *temp)
{
	while(temp!=NULL)
	{
		cout << " -> " << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Edges edge[7];
	int src, dest;
	for(int i=0; i<7; i++)
	{
		cin >> src >> dest;
		fflush(stdin);
		edge[i].source = src;
		edge[i].destination = dest;
	}
	Graph graph(edge, 6, 7);
	for(int i=0; i<6; i++)
	{
		cout << i;
		PrintList(graph.head[i]);
	}
	cout << endl << "BFS: " << endl;
	for(int i=0; i<6; i++)
	{
		graph.BFS(i);
		cout << endl;
	}
	cout << endl << "DFS: " << endl;
	for(int i=0; i<6; i++)
	{
		graph.BFS(i);
		cout << endl;
	}
	cout << endl << "Check cycle by DFS: " << endl;
	if(graph.CheckCycleBFS(0))
	{
		cout << "Cycle Detected." << endl;
	}
	else
	{
		cout << "Cycle Not Detected." << endl;
	}
	
	cout << endl << "Check cycle by BFS: " << endl;
	if(graph.CheckCycleBFS(0))
	{
		cout << "Cycle Detected." << endl;
	}
	else
	{
		cout << "Cycle Not Detected." << endl;
	}
}
