#include<iostream>
#define size 7

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *chain[size];

        Node()
        {
            next = NULL;
            for(int i=0; i<size; i++)
            {
                chain[i] = NULL;
            }
        }
        
        Node(int val)
        {
            data = val;
            next = NULL;
        }

        void insert(int val)
        {
            Node *n = new Node(val);
            int key = val % size;
            if(chain[key]==NULL)
            {
                chain[key]=n;
            }
            else
            {
                Node *temp = chain[key];
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                temp->next = n;
            }
        }

        void Search(int val)
        {
            int key = val % size;
            Node *temp = chain[key];
            while(temp!=NULL)
            {
                if(temp->data==val)
                {
                    cout << "Value found." << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Value not found." << endl;
        }

        void Delete(int val)
        {
            int key = val % size;
            Node *temp = chain[key];
            if(temp!=NULL)
            {
                if(temp->data==val)
                {
                    Node *del = temp;
                    temp = temp->next;
                    delete del;
                    cout << "Element deleted." << endl;
                    return;
                }
                else
                {
                    while(temp->next!=NULL)
                    {
                        if(temp->next->data==val)
                        {
                            Node *del = temp->next;
                            temp->next = temp->next->next;
                            delete del;
                            cout << "Element deleted." << endl;
                            return;
                        }
                        temp = temp->next;
                    }
                }
            }
            cout << "Element doesnt exist." << endl;
        }

        void Display()
        {
            for(int i=0; i<size; i++)
            {
                Node *temp = chain[i];
                cout << i << " -> ";
                while(temp!=NULL)
                {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }
        }
};


int main()
{
    Node obj;
    obj.insert(7);
    obj.insert(0);
    obj.insert(3);
    obj.insert(10);
    obj.insert(4);
    obj.insert(5);
    obj.Display();
    obj.Search(6);
    obj.Delete(3);
    obj.Display();
}