#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        
        Node()
        {
            data = 0;
            next = NULL;
            prev = NULL;
        }
        Node(int d)
        {
            data = d;
            next = NULL;
            prev = NULL;
        }
};

class DoubleLinkedList{
    public:
        Node *head = new Node;

        DoubleLinkedList()
        {
            head = NULL;
        }
        DoubleLinkedList(int val)
        {
            head->data = val;
        }
        void preappendnode(int val)
        {
            Node *n = new Node(val);
            n->next = head;
            if(head!=NULL)
            {
                head->prev = n;
            }
            head = n;
        }
        void appendnode(int val)
        {
            if(head==NULL)
            {
                preappendnode(val);
                return;
            }
            Node *n = new Node(val);
            Node *temp = head;
            while(temp->next!=NULL)
            { 
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }

        void insertnodeafter(int posval, int val)
        {
            Node *temp = head;
            Node *n = new Node(val);
            while(temp->data!=posval)
            {
                temp = temp->next;
            }
            temp->next = n;
            temp->next->prev = n;
            n->prev = temp;
            n->next = temp->next;
        }
        void Display()
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl; 
        }
};

int main()
{
    DoubleLinkedList obj(1);
    cout << "Inserting Nodes at end of list: " << endl;
    obj.appendnode(2);
    obj.appendnode(3);
    obj.appendnode(4);
    obj.appendnode(5);
    obj.appendnode(6);
    obj.appendnode(7);
    obj.Display();
    cout << endl << "Inserting Nodes at begining of list: " << endl;
    obj.preappendnode(0);
    obj.preappendnode(-1);
    obj.Display();
    cout << endl << "Inserting Nodes at any given point of list: " << endl;
    obj.insertnodeafter(4, 10);
    obj.Display();
}