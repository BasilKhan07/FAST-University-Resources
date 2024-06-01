#include<iostream>
#include<list>
#define SPACE 5

using namespace std;

class Node{
	public:	
		int data;
		Node *left;
		Node *right;
		
		Node()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
		
		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
};

class BST{
	public:
		Node *root;
		
		BST()
		{
			root = NULL;
		}
		
		void InsertNode(int val)
		{
			Node *n = new Node(val);
			if(root == NULL)
			{
				root = n;
				return;
			}
			else
			{
				Node *temp = root;
				while(temp!=NULL)
				{
					if(val == temp->data)
					{
						cout << "Value already Exist. " << endl;
						return;
					}
					else if(val < temp->data && temp->left == NULL)
					{
						temp->left = n;
						break;
					}
					else if(val < temp->data)
					{
						temp = temp->left;
					}
					else if(val > temp->data && temp->right == NULL)
					{
						temp->right = n;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
			}
		}
		
		void Print2D(Node *r, int space)
		{
			if(r == NULL)
			{
				return;
			}
			space = space + SPACE;
			Print2D(r->right, space);
			cout << endl;
			for(int i=0; i<space; i++)
			{
				cout << " ";
			}
			cout << r->data << endl;
			Print2D(r->left, space);
		}
		
		void PreOrder(Node *r)
		{
			if(r == NULL)
			{
				return;
			}
			cout << r->data << " ";
			PreOrder(r->left);
			PreOrder(r->right);
		}
		
		void InOrder(Node *r)
		{
			if(r == NULL)
			{
				return;
			}
			InOrder(r->left);
			cout << r->data << " ";
			InOrder(r->right);
		}
		
		void PostOrder(Node *r)
		{
			if(r == NULL)
			{
				return;
			}
			PostOrder(r->left);
			PostOrder(r->right);
			cout << r->data << " ";
		}
		
		int Height(Node *r)
		{
			if(r==NULL)
			{
				return -1;
			}
			int Lheight = Height(r->left);
			int Rheight = Height(r->right);
			
			if(Lheight>Rheight)
			{
				return Lheight+1;
			}
			else
			{
				return Rheight+1;
			}
		}
		
		Node* MinValueNode(Node *r)
		{
			Node *temp = r;
			while(temp->left!=NULL)
			{
				temp = temp->left;
			}
			return temp;
		}
		
		Node *MaxValueNode(Node *r)
		{
			Node *temp = r;
			while(temp->right!=NULL)
			{
				temp = temp->right;
			}
			return temp;
		}
		
		Node* DeleteNode(Node *r, int val)
		{
			if(r==NULL)
			{
				return NULL;
			}
			else if(val < r->data)
			{
				r->left = DeleteNode(r->left, val);
			}
			else if(val  > r->data)
			{
				r->right = DeleteNode(r->right, val);
			}
			else
			{
				if(r->left == NULL)
				{
					Node *temp = r->right;
					delete r;
					return temp;
				}
				else if(r->right == NULL)
				{
					Node *temp = r->left;
					delete r;
					return temp;
				}
				else
				{
					Node *temp = MaxValueNode(r->left);
					r->data = temp->data;
					r->left = DeleteNode(r->left, temp->data);
				}
			}
			return r;
		}
		
		void PrintGivenLevel(Node *r, int i)
		{
			if(r == NULL)
			{
				return;
			}
			else if(i == 0)
			{
				cout << r->data << " ";
			}
			else
			{
				PrintGivenLevel(r->left, i-1);
				PrintGivenLevel(r->right, i-1);
			}
		}
		
		void PrintLevelOrderBFS(Node *r)
		{
			int h = Height(r);
			for(int i=0; i<= h; i++)
			{
				PrintGivenLevel(r, i);
			}
		}
		
		void BFSusingQueue(Node *r)
		{
			list<Node *> queue;
			queue.push_back(r);
			while(!queue.empty())
			{
				Node *popped = queue.front();
				cout << popped->data << " ";
				queue.pop_front();
				if(popped->left!=NULL)
				{
					queue.push_back(popped->left);	
				}
				if(popped->right!=NULL)
				{
					queue.push_back(popped->right);
				}
			}
		}
};

int main()
{
	BST obj;
	obj.InsertNode(7);
	obj.InsertNode(5);
	obj.InsertNode(9);
	obj.InsertNode(3);
	obj.InsertNode(6);
	obj.InsertNode(8);
	obj.InsertNode(10);
	obj.InsertNode(1);
	obj.Print2D(obj.root, 6);
	cout << endl;
	obj.PreOrder(obj.root);
	cout << endl;
	obj.InOrder(obj.root);
	cout << endl;
	obj.PostOrder(obj.root);
	cout << endl;
	cout << obj.Height(obj.root);
	cout << endl;
	Node *n = obj.MinValueNode(obj.root);
	cout << n->data;
	cout << endl;
	n = obj.MaxValueNode(obj.root);
	cout << n->data;
	cout << endl;
//	obj.DeleteNode(obj.root, 7);
//	obj.Print2D(obj.root, 5);
	obj.PrintLevelOrderBFS(obj.root);
	cout << endl;
	obj.BFSusingQueue(obj.root);
}
