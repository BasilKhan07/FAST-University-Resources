#include<iostream>
#define size 7

using namespace std;

class Node{
    public:
        int contact;
        int ID;
        Node *next;

        Node()
        {
            ID = 0;
            contact = 0;
            next = NULL;
        }
        
        Node(int val1, int val2)
        {
            ID = val1;
            contact = val2;
            next = NULL;
        }
};

class HashTable{
    public:
        Node *chain[size];

        HashTable()
        {
            for(int i=0; i<size; i++)
            {
                chain[i] = NULL;
            }
        }
        
        int Hash_Func(int val)
        {
            return val % size;
        }

        void Insertdata(int val1, int val2)
        {
            Node *n = new Node(val1, val2);
            int index = Hash_Func(val1);
            if(chain[index]==NULL)
            {
                chain[index] = n;
            }
            else
            {
                Node *temp = chain[index];
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                temp->next = n;
            }
        }

        int ContactSize()
        {
            return size;
        }

        void IsEmpty()
        {
            for(int i=0; i<size; i++)
            {
                if(chain[i]!=NULL)
                {
                    cout << "Contact Book not empty. " << endl;
                    return ;
                }
            }
            cout << "Contact Book empty. " << endl;
        }

        void Search(int val)
        {
            int index = val % size;
            Node *temp = chain[index];
            while(temp!=NULL)
            {
                if(temp->ID==val)
                {
                    cout << "Entered Record found at location: " << index << endl;
                    cout << "Student ID: " << chain[index]->ID << endl;
                    cout << "Contact Number: " << chain[index]->contact << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Value not found." << endl;
        }

        void Delete(int val)
        {
            int index = val % size;
            if(chain[index]!=NULL)
            {
                if(chain[index]->ID==val)
                {
                    cout << "Entered Record found at location: " << index << endl;
                    cout << "Student ID: " << chain[index]->ID << endl;
                    cout << "Contact Number: " << chain[index]->contact << endl;
                    delete chain[index];
                    chain[index] = NULL;
                    cout << "Element deleted." << endl;
                    return;
                }
                else
                {
                    Node *temp = chain[index];
                    while(temp->next!=NULL)
                    {
                        if(temp->next->ID==val)
                        {
                            cout << "Entered Record found at location: " << index << endl;
                            cout << "Student ID: " << chain[index]->ID << endl;
                            cout << "Contact Number: " << chain[index]->contact << endl;
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
                cout << i << " : ";
                while(temp!=NULL)
                {
                    cout << " | "  << temp->ID << " " << temp->contact << " | " << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }
        }
};


int main()
{
    HashTable obj;
    cout << "Before entering record: " << endl;
    cout << "Whether book is empty or not: ";
    obj.IsEmpty();
    cout << endl;
    cout << "Contact Book Size: ";
    cout << obj.ContactSize() << endl;
    cout << endl;
    cout << "Inserting record: " << endl;
    obj.Insertdata(200477, 0335126);
    obj.Insertdata(245477, 32478126);
    obj.Insertdata(206748, 485126);
    obj.Insertdata(200877, 7875126);
    obj.Insertdata(1, 7875126);
    obj.Display();
    cout << endl;
    cout << "Whether book is empty or not: ";
    obj.IsEmpty();
    cout << endl;
    cout << "Searching a record: " << endl;
    obj.Search(200477);
    cout << endl;
    cout << "Deleting record: " << endl;
    obj.Delete(206748);
    cout << endl;
    cout << "After deleting record: " << endl;
    obj.Display();
}