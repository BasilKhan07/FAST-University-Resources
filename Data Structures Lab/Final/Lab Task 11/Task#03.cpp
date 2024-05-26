#include<iostream>
#define size 10

using namespace std;

class Node{
    public:
        int contact;
        int ID;

        Node()
        {
            ID = 0;
            contact = 0;
        }

        Node(int val1, int val2)
        {
            ID = val1;
            contact = val2;
        }
};

class HashTable{
    public:
        Node *arr[size];

        HashTable()
        {
            for(int i=0; i<size; i++)
            {
                arr[i] = NULL;
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
            if(arr[index] == NULL)
            {
                arr[index] = n;
            }
            else
            {
                for(int i=0; i<size; i++)
                {
                    int z = (index+i) % size;
                    if(arr[z]==NULL)
                    {
                        arr[z] = n;
                        return; 
                    }
                }
            }
        }

        void IsEmpty()
        {
            for(int i=0; i<size; i++)
            {
                if(arr[i]!=NULL)
                {
                    cout << "Contact Book not empty. " << endl;
                    return ;
                }
            }
            cout << "Contact Book empty. " << endl;
        }

        int ContactSize()
        {
            return size;
        }

        bool Search(int val)
        {
            int index = Hash_Func(val);
            if(arr[index]->ID==val)
            {
                cout << "Entered Record found at location: " << index << endl;
                cout << "Student ID: " << arr[index]->ID << endl;
                cout << "Contact Number: " << arr[index]->contact << endl;
                return true;
            }
            else
            {
                for(int i=0; i<size; i++)
                {
                    int z = (index+i) % size;
                    if(arr[z]->ID==val)
                    {
                            cout << "Entered Record found at location: " << index << endl;
                            cout << "Student ID: " << arr[index]->ID << endl;
                            cout << "Contact Number: " << arr[index]->contact << endl;
                            return true;
                    }
                }
            }
            return false;
        }

        void Delete(int val)
        {
            if(!Search(val))
            {
                cout << "No such contact found. " << endl;
                return;
            }
            else
            {
                int index = Hash_Func(val);
                if(arr[index]->ID==val)
                {
                    delete arr[index];
                    arr[index] = 0;
                    return;
                }
                else
                {
                    for(int i=0; i<size; i++)
                    {
                        int z = (index+i) % size;
                        if(arr[z]->ID==val)
                            {
                                delete arr[index];
                                arr[index] = 0;
                                return;
                            }
                    }
                }
            }
        }

        int Display()
        {
           for(int i=0; i<size; i++)
            {
                if(arr[i]==NULL)
                {
                	cout << i << " -> " << "NULL" << endl;
				}
				else
				{
					cout << i << " -> " << arr[i]->ID << " " << arr[i]->contact << endl;
				}
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