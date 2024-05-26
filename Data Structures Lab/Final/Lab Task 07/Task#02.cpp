#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
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
		Node *top = new Node;
	
		LinkedList()
		{
			top = NULL;
		} 
		
		LinkedList(int val)
		{
			top->data = val;
			top->next = NULL;
		} 
		
		void pushdata(int val)
		{
			Node *temp = new Node;
			temp->data = val;
			temp->next = top;
			top = temp;
		}
		
		void Display()
		{
			Node *temp = top;
			while(temp!=NULL)
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
		}	
};

bool reverse(Node* temp)
{
	if(temp==NULL)
	{
		return false;
	}		
	reverse(temp->next);
	cout << temp->data << endl;
}

int main()
{
	LinkedList obj;
	obj.pushdata(1);
	obj.pushdata(2);
	obj.pushdata(3);
	obj.pushdata(4);
	obj.pushdata(5);
	obj.Display();
	cout << "REVERSE: " << endl;
	reverse(obj.top);
}
