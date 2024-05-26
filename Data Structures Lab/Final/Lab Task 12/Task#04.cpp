#include<iostream>
#include<list>

using namespace std;

class Graph {
    public:
    int V;
    bool *visited;
    list<int> *adj;

    Graph(int val)
    {
        V = val;
        adj = new list<int>[V];
    }
 
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void DFS(int v)
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                DFS(*i);
            }
        }
    }
};
 
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(0);
}