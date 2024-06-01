//Graph Implementation without STL by Sir Sarosh Jawed
#include<iostream>
#include<queue>
#include<stack>

using namespace std;


class Node{
	public:
	Node *adj;
	int data;
	Node(){
		adj=NULL;
	} 

	Node(int d){
		data=d;
		adj=NULL;
	}
};


class Graph{
	public:
		Node **head;    //using double pointer as 1 array will be used for vertex names and other for the list of adjacent nodes
		int vertices;   //number of vertices
//	    int edges = 0;
		Graph(){
			head=NULL;
			int size=0;
            
		}
		
		Graph(int V,int arr[]){
			head = new Node* [V];  //allocating memory for vertices 
			vertices=V;  
			Node *n;
			for(int i=0;i<V;i++) {
			    n=new Node(arr[i]); //storing all the vertices sent from main
			    head[i]=n;
			}
		}
		
		void addedge(int from,int to){   //function to add edges
		Node* n =new Node (to);   
//		    edges= edges + 1;
		if(head[from]->adj!=NULL){      //if there are already adjacent nodes so we will traverse and place the adjancent 
			Node *temp =head[from];     //node in next available space
			while(temp->adj!=NULL){ 
				temp=temp->adj;
			}
			temp->adj=n;
		}
		else{
			head[from]->adj = n;        //if no adjacent nodes so directly make adjacent node
		}
		
		Node *s= new Node(from);        //made a connection from->to now will make from to->from as undirected graph 
		if(head[to]!=NULL){
			Node *temp =head[to];
			while(temp->adj!=NULL){
				temp=temp->adj;
			}
			temp->adj=s;
		}
		else{
			head[from]->adj = s;
		}
    
	}
		
		void printadjlist(){                             //Prints the adjacent list
			for(int i= 0; i<vertices ;i++){                    
				cout<<head[i]->data<<"-->";              //Prints the current vertex
				
				if(head[i]->adj!=NULL){                  //Prints the adjacent vertex to current vertex
					Node *temp = head[i]->adj;
					while(temp!=NULL){
						cout<<temp->data<<" --> ";
						temp = temp->adj;
					}
				}
				cout<<"NULL"<<endl;
			}
//			cout<<endl<<"total edges= "<<edges<<endl;
		}
		
	void BFS(int s){//s = starting vertex
	    int visited[vertices];   //keeps the record of visited nodes
	    for(int i=0;i<vertices;i++){
	    	visited[i] = 0;      //0 means that the vertex is not visited
		}
		visited[s] = 1;          //as we have visited s so we assign 1 at visited vertex
		queue <int> q;
		q.push(s);              //pushing the visited node in queue so that it can be explored later.works as exploration queue
		
		while(!q.empty()){     
			s = q.front();   //store the element to be explored in s
			q.pop();         // and then pop it from list as it will be explored
			cout<<s<<" ";    // print the visited element
			for(Node* temp = head[s] ; temp!=NULL ; temp=temp->adj){  //will enque all the nodes connected to s
				if(visited[temp->data]!=1){                           //works if temp is not visited yet;
					q.push(temp->data);                               //pushes the vertex in q 
					visited[temp->data]=1;                            //marks visited data 1
				}
			}
		}
	}
	
	void DFS(int s){
		int *visited = new int[vertices];
		for(int i=0;i<vertices;i++){
			visited[i]=0;
		}
	    stack<int> s1;
	    
		s1.push(s);

		while(!s1.empty()){
			s=s1.top();
			s1.pop();
			if(visited[s]!=1){
				visited[s]=1;
				cout<<s<<" ";
				for(Node *temp=head[s];temp!=NULL;temp=temp->adj){
					if(visited[temp->data]!=1){
						s1.push(temp->data);
					}
				}
			}
		}
	}	

	bool CycleDetection(int s){//s = starting vertex
	    int visited[vertices];   //keeps the record of visited nodes
	    bool cycle=false;
	    for(int i=0;i<vertices;i++){
	    	visited[i] = -1;      //-1 means that the vertex is not visited
		}
		queue <int> q;
		q.push(s);              //pushing the visited node in queue so that it can be explored later.works as exploration queue
		visited[s] = 0;          //as we have visited s so we assign 0 at visited vertex		
		while(!q.empty()){     
			s = q.front();   //store the element to be explored in s
			q.pop();         // and then pop it from list as it will be explored
			visited[s]=1;    //1 means The node has been explored now
			
			for(Node *temp = head[s]->adj ; temp!=NULL ; temp=temp->adj){  //will enque all the nodes connected to s
            
			if(visited[temp->data]==-1){    //If the node is not visited 
				q.push(temp->data);             
				visited[temp->data]=0;      //mark the node 0 after visit
			}   
		    
		    else if(visited[temp->data]==0){  //if the node has been visited but not explored so cycle exists
		    cycle = true;
			break;	
			}
			
			}
			
			}
			
			return cycle;
		}
};


int main(){
	int V=5;
	int source[V]={0,1,2,3,4};
	
	
	Graph g(V,source);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,4);
	g.addedge(1,3);
	g.addedge(3,4);
//	g.addedge(2,4);
//	g.addedge(3,4);
//	g.addedge(4,5);		
//	g.addedge(4,6);

//	g.addedge(0,1);
//	g.addedge(1,2);  //trianle has cycle
//	g.addedge(2,0);
	
	
	
	g.printadjlist();
	cout<<"BFS: ";
	g.BFS(0);      //Starting node = 0 
	cout<<endl<<"DFS: ";
	g.DFS(0);
	cout<<endl;
	if (g.CycleDetection(0)) {
		cout<<endl<<"Cycle Exists!! ";
	}
	else{
		cout<<endl<<"No cycle! ";
	}
}
