#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << endl << "Adjacency list of vertex: " << v << endl << "head";
        for(auto x : adj[v])
        {
            cout << "->" << x << endl;
        } 
    }
}


int main()
{
    int V = 4;
    vector<int> *adj;
    adj = new vector<int>[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    printGraph(adj, V);
    return 0;  
}
