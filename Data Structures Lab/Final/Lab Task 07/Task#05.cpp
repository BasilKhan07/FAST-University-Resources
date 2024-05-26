#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int val)
		{
			data = val;
			next = NULL;
		}
};

class Queue{
	public:
		Node *front;
		Node *rear;
		
		Queue()
		{
			front = NULL;
			rear = NULL;
		}
		
		void Enqueu(int val)
		{
			Node *n = new Node(val);
			if(front==NULL)
			{
				rear = n;
				front = n;
				return;
			}
			
			rear->next = n;
			rear = n;
		}
		int Dequeu()
		{
			if(front == NULL)
			{
				cout << "QUEUE IS EMPTY!" << endl;
				return -1;
			}
			Node *del = front;
			int x = front->data;
			front = front->next;
			delete del;
			return x;
		}
};

int main()
{
	Queue obj;
	obj.Enqueu(0);
	obj.Enqueu(1);
	cout << obj.Dequeu() << endl;
	cout << obj.Dequeu() << endl;
	obj.Dequeu();
}