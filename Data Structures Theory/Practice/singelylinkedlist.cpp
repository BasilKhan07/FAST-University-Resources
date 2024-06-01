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

        void insertathead(int val)
        {
            Node *n = new Node(val);
            n->next = head;
            head = n;
        }
        void insertatend(int val)
        {
            Node *n= new Node(val);
            if(head==NULL)
            {
                head = n;
                return;
            }
            Node *temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }

        void insertnodeafter(int val, int pos)
        {
            Node *n=new Node(val);
            Node *curr = head;
            Node *prev = NULL;
            while(curr->data != pos)
            {
                //prev = curr;
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }

        void deletehead()
        {
            Node *n = new Node;
            n = head;
            head = head->next;
            delete n;
        }

        void deletetail()
        {
            Node *n = new Node;
            Node *pre = new Node;
            n = head;
            while(n->next!=NULL)
            {
                pre = n;
                n = n->next;
            }
            pre->next=NULL;
            delete n;
        }

        void deletenode(int val)
        {
            Node *pre = new Node;
            Node *curr = new Node;
            curr = head;
            while (curr->data!=val)
            {
                pre = curr;
                curr = curr->next;
            }
            pre->next=curr->next;
            delete curr;
            
        }

        Node* reverse( )
        {
            Node *pre = NULL;
            Node *curr = head;
            Node *nextptr;
            while(curr!=NULL)
            {
                nextptr = curr->next;
                curr->next = pre;
                pre = curr;
                curr = nextptr;
            } 
            return pre;
        }

        bool search(int val)
        {
            Node *n = new Node;
            n = head;
            while(n!=NULL)
            {
                if(n->data==val)
                {
                    return true;
                }
                else
                {
                    n = n->next;
                }
            }
            return false;
        }

        void Display()
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                cout << temp->data << " -> ";
                temp=temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main()
{
    LinkedList L1(1);
    L1.insertatend(2);
    L1.insertatend(3);
    L1.insertatend(5);
    L1.insertatend(6);
    L1.Display();
    L1.insertathead(0);
    L1.Display();
    L1.insertnodeafter(4, 3);
    L1.Display();
    L1.deletehead();
    L1.Display();
    L1.deletetail();
    L1.Display();
    L1.deletenode(3);
    L1.Display();
    cout << L1.search(12) << endl;
    LinkedList L2;
    L2.head = L1.reverse();
    L2.Display();
}
