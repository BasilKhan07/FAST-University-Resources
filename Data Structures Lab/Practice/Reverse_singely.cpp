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

class SingelyLinkedList{
    public:
        Node *head = new Node;

        SingelyLinkedList()
        {
            head = NULL;
        }
        SingelyLinkedList(int val)
        {
            head->data = val;
            head->next = NULL;
        }

        void Insertathead(int val)
        {
            Node *n = new Node(val);
            if(head==NULL)
            {
                head = n;
                return;
            }
            n->next = head;
            head = n;
        }

        void Insertatend(int val)
        {
            if(head==NULL)
            {
               Insertathead(val);
               return; 
            }
            Node *temp = head;
            Node *n = new Node(val);
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }

        void Display()
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << " NULL" << endl;
        }

        void NormalReverse()
        {
            Node *prevptr = NULL;
            Node *currrptr = head;
            Node *nextptr;
            while(currrptr!=NULL)
            {
                nextptr = currrptr->next;
                currrptr->next = prevptr;
                prevptr = currrptr;
                currrptr = nextptr;
            }
            head = prevptr;
        }
};

Node *Recursivereverse(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *newhead = Recursivereverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}



int main()
{
    SingelyLinkedList obj(0);
    SingelyLinkedList obj2;
    obj.Insertatend(1);
    obj.Insertatend(2);
    obj.Insertatend(3);
    obj.Insertatend(4);
    obj.Display();
    obj.NormalReverse();
    obj.Display();
    obj.head = Recursivereverse(obj.head);
    obj.Display();
}