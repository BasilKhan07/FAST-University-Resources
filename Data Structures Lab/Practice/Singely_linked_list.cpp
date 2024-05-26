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

        void InsertUsingpos(int val, int pos)
        {
            Node *n = new Node(val);
            Node *temp1 = head;
            Node *temp2 = temp1;
            int count = 1;
            if(pos==1)
            {
                n->next = head;
                head = n;
                return;
            }
            while(temp1!=NULL)
            {
                if(count == pos)
                {
                    n->next = temp1;
                    temp2->next = n;
                }
                temp2 = temp1;
                temp1 = temp1->next;
                count++;
            }
        }

        void InsertUsingval(int val, int key)
        {
            Node *n = new Node(val);
            Node *temp = head;
            while(temp!=NULL)
            {
                if(temp->data == key)
                {
                    n->next = temp->next;
                    temp->next = n;
                }
                temp = temp->next;
            }
        }

        void deletehead()
        {
            if(head == NULL)
            {
                return;
            }
            Node *todelete = head;
            head = head->next;
        }

        void deleteNode(int val)
        {
            if(head==NULL)
            {
                return;
            }
            if(head->data == val)
            {
                deletehead();
                return;
            }
            Node *temp = head;
            while(temp->next->data != val)
            {
                temp = temp->next;
            }
            Node *todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
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
};

int main()
{
    SingelyLinkedList obj(-1);
    obj.Display();
    obj.Insertatend(2);
    obj.Insertatend(3);
    obj.Insertatend(4);
    obj.Display();
    obj.Insertathead(0);
    obj.Insertathead(-1);
    obj.Insertathead(-2);
    obj.Display();
    obj.InsertUsingpos(8, 4);
    obj.Display();
    obj.InsertUsingval(9, 3);
    obj.Display();
    obj.deleteNode(-2);
    obj.deleteNode(4);
    obj.Display();
    obj.deletehead();
    obj.Display();
}