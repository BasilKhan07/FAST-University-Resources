#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node()
        {
            data = 0;
        }

        Node(int val)
        {
            data = val;
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
        }

        void preappendnode(int val)
        {
            Node *n = new Node(val);
            if(head == NULL)
            {
                n->next = n;
                head = n;
                return;
            }
            Node *temp = head;
            while(temp->next!=head)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
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
            temp->next = n;
            n->next = head;
        }

        void insertnodeafter(int posval, int val)
        {
            Node *temp = head;
            Node *n = new Node(val);
            while(temp->data!=posval)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }

        void deleteathead()
        {
            Node *temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            Node *del = head;
            temp->next = head->next;
            head = head->next;
            delete del;
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
            while(count!=pos-1)
            {
                temp = temp->next;
                count++;
            }
            Node *del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }

        void Display()
        {
            Node *temp = head;
            cout << " -> ";
            do
            {
                cout << temp->data << " -> ";
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
    obj.deletenode(9);
    obj.Display();
    cout << endl << "Printing All Nodes of list: " << endl;
    obj.Display();
}