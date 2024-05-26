#include<iostream>
#define INT_MIN (-2147483647 - 1)
#define INT_MAX 2147483647

using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;

		Node()
        {
			left = NULL;
			right = NULL;
			data = 0;
		}

		Node(int val){
			left = NULL;
			right = NULL;
			data = val;
		}
		int isBST(Node* Node)
		{
			return(isBSTUtil(Node, INT_MIN, INT_MAX));
		}
		int isBSTUtil(Node* Node, int min, int max)
		{
			if(Node==NULL)
			   return 1;
			if (Node->data < min || Node->data > max)
			return 0;
			
			return 
			isBSTUtil(Node->left, min, Node->data-1) && isBSTUtil(Node->right, Node->data+1, max);
		}
	
};
int main(){
	Node obj;
	Node *root = new Node(40);
    root->left = new Node(9);
    root->right = new Node(11);
    root->left->left = new Node(1);
    root->left->right = new Node(30);
     
    if(obj.isBST(root)){
    	cout << "Is BST" << endl;
        cout << "10 Marks Assigned";
	}
    else{
    	cout << "Not a BST" << endl;
        cout << "0 Marks Assigned";
	}
}