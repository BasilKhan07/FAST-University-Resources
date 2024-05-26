#include<iostream>
#include<list>


using namespace std;

class Graph{
    public:
        int V;
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

        void BFS(int s)
        {
            bool *visited = new bool[V];
            for(int i=0; i<V; i++)
            {
                visited[i] = false;
            }

            list<int> queue;
            visited[s] = true;
            queue.push_back(s);
            list<int>::iterator i;
            while(!queue.empty())
            {
                s = queue.front();
                cout << s << " ";
                queue.pop_front();

                for(i = adj[s].begin(); i!=adj[s].end(); i++)
                {
                    if(!visited[*i])
                    {
                        visited[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }
};

int main()
{
    Graph obj(10);
    obj.addEdge(0, 1);
    obj.addEdge(0, 2);
    obj.addEdge(1, 5);
    obj.addEdge(5, 0);
    obj.addEdge(1, 2);
    obj.addEdge(3, 6);
    obj.addEdge(6, 9);
    obj.addEdge(9, 1);
    obj.addEdge(1, 2);
    obj.addEdge(4, 5);
    obj.BFS(4);
}