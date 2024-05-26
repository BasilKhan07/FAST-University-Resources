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

        Node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

class CircularLinkedList{
    public:
        Node *head = new Node;

        CircularLinkedList()
        {
            head = NULL;
        }
        CircularLinkedList(int val)
        {
            head->data = val;
            head->next = head;
            head->prev = head;
        }

        void preappendnode(int val)
        {
            Node *n = new Node(val);
            if(head!=NULL)
            {
                n->prev = head->prev;
                n->prev->next = n;
                head->prev = n;
                n->next = head;
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
            while(temp->next!=head)
            { 
                temp = temp->next;
            }
            temp->next->prev = n;
            n->next = temp->next;
            temp->next = n;
            n->prev = temp;

        }

        void insertnodeafter(int posval, int val)
        {
            Node *n = new Node(val);
            Node *temp = head;
            while(temp->data!=posval)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            n->next->prev = n;
            temp->next = n;
            n->prev = temp;
        }

        void deleteathead()
        {
            Node *del = head;
            Node *temp = head;
            head = temp->next;
            temp->prev->next = head;
            head->prev = temp->prev;
            temp->prev = head;
        }

        void deletenode(int pos)
        {
            if(pos==1)
            {
                deleteathead();
                return;
            }
            Node *temp = head;
            int count=1;
            while(temp->next!=head && count!=pos)
            {
                temp = temp->next;
                count++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

        void Display()
        {
            Node *temp = head;
            cout << " <-> ";
            do
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            } while (temp!=head);
            cout << endl; 
        }
};

int main()
{
    CircularLinkedList obj(1);
    cout << "Inserting Nodes at end of list: " << endl;
    obj.appendnode(2);
    obj.appendnode(3);
    obj.appendnode(4);
    obj.appendnode(5);
    obj.appendnode(6);
    obj.Display();
    cout << endl << "Inserting Nodes at begining of list: " << endl;
    obj.preappendnode(0);
    obj.preappendnode(-1);
    obj.Display();
    cout << endl << "Inserting Nodes at any given point of list: " << endl;
    obj.insertnodeafter(4, 10);
    obj.Display();
    cout << endl << "Deleting Nodes at any given point of list: " << endl;
    obj.deletenode(1);
    obj.Display();
    cout << endl << "Printing All Nodes of list: " << endl;
    obj.Display();
}