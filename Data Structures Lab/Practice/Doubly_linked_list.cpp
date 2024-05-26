#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node()
        {
            next = NULL;
            prev = NULL;
        }

        Node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinkedList{
    public:
        Node *head = new Node;

        DoublyLinkedList()
        {
            head = NULL;
        }

        DoublyLinkedList(int val)
        {
            head->data = val;
            head->next = NULL;
            head->prev = NULL;
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
            head->prev = n;
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
            n->prev = temp;
        }

        void InsertUsingpos(int val, int pos)
        {
            Node *n = new Node(val);
            Node *temp1 = head;
            Node *temp2 = temp1;
            int count = 1;
            if(pos==1)
            {
                n->next = head;
                head->prev = n;
                head = n;
                return;
            }
            while(temp1!=NULL)
            {
                if(count == pos)
                {
                    n->next = temp1;
                    temp1->prev = n;
                    temp2->next = n;
                    n->prev = temp2;
                    return;
                }
                temp2 = temp1;
                temp1 = temp1->next;
                count++;
            }
        }
        
        void Display()
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << " NULL" << endl;
        }
};

int main()
{
    DoublyLinkedList obj;
    obj.Insertatend(1);
    obj.Insertatend(2);
    obj.Insertatend(3);
    obj.Insertatend(4);
    obj.Display();
    obj.Insertathead(-1);
    obj.Insertathead(-2);
    obj.Display();
    obj.InsertUsingpos(5, 2);
    obj.Display();
    obj.InsertUsingpos(9, 1);
    obj.Display();
}