#include<iostream>

using namespace std;

class Node{
    public:
        int data, cost;
        Node *next = NULL;
        
        Node()
        {
            data = 0;
            cost = 0;
            next = NULL;
        }

        Node(int val, int c)
        {
            data = val;
            cost = c;
            next = NULL;
        }
};

class Edges{
    public:
        int source, destination, weight;
};

class Graph{
    public:
        Node **head;
        int N;

        Graph()
        {
            head = NULL;
            N = 0;
        }

        Graph(Edges edge[], int NumberOfNodes, int NumberOfEdges)
        {
            head = new Node*[NumberOfNodes];
            N = NumberOfNodes;
            for(int i=0; i<N; i++)
            {
                head[i] = NULL;
            }

            for(int i=0; i<NumberOfEdges; i++)
            {
                int source = edge[i].source;
                int destination = edge[i].destination;
                int weight = edge[i].weight;

                Node *n1 = AddEdge(head[source], weight, destination);
                head[source] = n1;
                // Node *n2 = AddEdge(head[destination], weight, source);
                // head[destination] = n2;
            }

            
        }

        Node* AddEdge(Node *headsource, int weight, int dest)
        {
            Node *n = new Node(dest, weight);
            n->next = headsource;
            return n;
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

void PrintList(Node *temp)
{
    while(temp!=NULL)
    {
        cout << ", " << temp->data << ", " << temp->cost << " )";
        temp = temp->next;
    }
    cout << " -> NULL";
}

int main()
{
    Edges edge[7];
    int src, dest, w;
    for(int i=0; i<7; i++)
    {
        cin >> src >> dest >> w;
        fflush(stdin);
        edge[i].source = src;
        edge[i].destination = dest;
        edge[i].weight = w;
    }

    Graph graph(edge, 6, 7);
    for(int i=0; i<6; i++)
    {
        cout << "( " << i;
        PrintList(graph.head[i]);
        cout << endl;
    }
}