#include<iostream>

using namespace std;
int flag;

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
		Node *head = new Node;
		
		LinkedList()
		{
			head = NULL;
		}
		
		LinkedList(int val)
		{
			head->data = val;
			head->next = NULL;
		}
		
		void appendnode(int val)
		{
			Node *n = new Node(val);
			if(head==NULL)
			{
				head = n;
				return;
			}
			Node *temp = head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
		}
		
		void SepratingNodes()
		{
			LinkedList odd;
			LinkedList even;
			Node *temp = head;
			while(temp!=NULL)
			{
				if(temp->data % 2 == 0)
				{
					even.appendnode(temp->data);
				}
				if(temp->data % 2 != 0)
				{
					odd.appendnode(temp->data);
				}
				temp = temp->next;
			}
			if(even.head==NULL)
			{
				return;
			}
			if(odd.head==NULL)
			{
				return;
			}
			Node *temp1 = even.head;
			Node *temp2 = odd.head;
			while(temp1->next!=NULL)
			{
				temp1 = temp1->next;
			}
			temp1->next = temp2;
			head = even.head;
		}
		void display()
		{
			Node *temp = head;
			while(temp!=NULL)
			{
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "NULL";
			cout << endl;
		}
};

int main()
{
	LinkedList obj1(17);
	obj1.appendnode(15);
	obj1.appendnode(8);
	obj1.appendnode(12);
	obj1.appendnode(10);
	obj1.appendnode(5);
	obj1.appendnode(4);
	obj1.appendnode(1);
	obj1.appendnode(7);
	obj1.appendnode(6);
	cout << "Given Linked List: " << endl;
	obj1.display();
	//LinkedList Obj1;
	obj1.SepratingNodes();
	cout << "Required Linked List: " << endl;
	obj1.display();
	cout << endl;
	LinkedList obj2(8);
	obj2.appendnode(12);
	obj2.appendnode(10);
	obj2.appendnode(5);
	obj2.appendnode(4);
	obj2.appendnode(1);
	obj2.appendnode(6);
	cout << "Given Linked List: " << endl;
	obj2.display();
	obj2.SepratingNodes();
	cout << "Required Linked List: " << endl;
	obj2.display();
	cout << endl;
	LinkedList obj3(8);
	obj3.appendnode(12);
	obj3.appendnode(10);
	cout << "Given Linked List: (If all numbers are even then do not change the list)." << endl;
	obj3.display();
	obj3.SepratingNodes();
	cout << "Required Linked List: " << endl;
	obj3.display();
	cout << endl;
	LinkedList obj4(1);
	obj4.appendnode(3);
	obj4.appendnode(5);
	obj4.appendnode(7);
	cout << "Given Linked List: (If all numbers are odd then do not change the list)." << endl;
	obj4.display();
	obj4.SepratingNodes();
	cout << "Required Linked List: " << endl;
	obj4.display();
	cout << endl;
}
