#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node()
        {
            data = 0;
            next = NULL;
        }
        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

class LinkedList{
    public:
        Node* head;

        LinkedList()
        {
            head = NULL;
        }

        void insert(int val)
        {
            Node *n = new Node(val);
            if(head == NULL)
            {
                head = n;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }

		bool search(int val)
        {
			if(head == NULL)
            {
				return false;
			}
			Node* temp = head;
			while(temp != NULL)
            {
				if(temp->data == val)
                {
					return true;
				}
				temp = temp->next;
			}
			return false;
		}

		void PrintEdges()
        {
			if(head == NULL)
            {
				cout << " -> NULL";
				return;
			}
			Node* temp = head;
			while(temp != NULL){
				cout << " -> " << temp->data;
				temp = temp->next;
			}
		}
};

class Graph{
	public:
		int size;
		LinkedList *adj;
		
		Graph(int n){
			size = n;
			adj = new LinkedList[n];
		}
		
		void addEdge(int u, int v)
        {	
			if(!adj[u].search(v))
            {
				adj[u].insert(v);
			}
			if(!adj[v].search(u))
            {
				adj[v].insert(u);
			}	
		}
		
		void PrintGraph(){
			for(int i=0; i<size; i++)
            {
				cout << endl << "Adjacency list of vertex " << i << endl << "Head ";
				adj[i].PrintEdges();
			}
		}
};


int main(){
	Graph G(4);
	G.addEdge(0,1);
	G.addEdge(1,2);
	G.addEdge(2,3);
	G.PrintGraph();
}