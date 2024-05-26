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

class DoubleLinkedList{
    public:
        Node *head = new Node;
        Node *tail = new Node;

        DoubleLinkedList()
        {
            head = NULL;
            tail = NULL;
        }
        DoubleLinkedList(int val)
        {
            head->data = val;
            tail = head;
        }
        void preappendnode(int val)
        {
            Node *n = new Node(val);
            n->next = head;
            if(head!=NULL)
            {
                head->prev = n;
            }
            if(n->next==NULL)
            {
                tail = n;
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
            tail = n;
        }

        void insertnodeafter(int posval, int val)
        {
            Node *temp = head;
            Node *n = new Node(val);
            while(temp->data!=posval)
            {
                temp = temp->next;
            }
            if(temp==tail)
            {
                appendnode(val);
                return;
            }
            n->next = temp->next;
            n->prev = temp;
            temp->next->prev = n;
            temp->next = n;
        }
        
        void deleteathead()
        {
            Node *del = head;
            head = head->next;
            head->prev = NULL;
            delete del;
        }

        void deletteattail()
        {
            Node *temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            Node *del = temp;
            tail = temp->prev;
            tail->next = NULL;
            delete temp;
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
            while(temp!=NULL && count!=pos)
            {
                temp = temp->next; 
                count++;
            }
            if(temp==tail)
            {
                deletteattail();
                return;
            }
            temp->prev->next = temp->next;
            if(temp->next!=NULL)
            {
                temp->next->prev = temp->prev;
            }
            delete temp;
        }

        void merge(DoubleLinkedList L, DoubleLinkedList M)
        {
            Node *temp1 = L.tail;
            Node *temp2 = M.head;
            temp1->next = temp2;
            temp2->prev = temp1;
            this->head = L.head;
            this->tail = M.tail;
        }

        void Display()
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            cout << "Head: " << head->data << endl;
            cout << "Tail: " << tail->data << endl; 
        }
};


int main()
{
    DoubleLinkedList obj1(1);
    obj1.appendnode(2);
    obj1.appendnode(3);
    obj1.appendnode(4);
    obj1.appendnode(5);
    cout << "First Doubly Linked List ( L ): " << endl;
    obj1.Display();
    DoubleLinkedList obj2(6);
    obj2.appendnode(7);
    obj2.appendnode(8);
    obj2.appendnode(9);
    obj2.appendnode(10);
    cout << endl << "Second Doubly Linked List ( M ): " << endl;
    obj2.Display();
    DoubleLinkedList obj3;
    cout << endl << "Third Doubly Linked List After Concatenating L and M: " << endl; 
    obj3.merge(obj1, obj2);
    obj3.Display();
}