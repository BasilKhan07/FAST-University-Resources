#include<iostream>
#define size 10

using namespace std;

class Node{
    public:
        int data;

        Node()
        {
            data = 0;
        }

        Node(int val)
        {
            data = val;
        }
};

class DoubleHashing{
    public:
        Node *arr[size];

        DoubleHashing()
        {
            for(int i=0; i<size; i++)
            {
                arr[i] = NULL;
            }
        }

        void Insertdata(int val)
        {
            Node *n = new Node(val);
            int index1 = ((2*val)+3) % size;
            int index2 = ((3*val)+1) % size;
            if(arr[index1] == NULL)
            {
                arr[index1] = n;
            }
            else
            {
                for(int i=0; i<size; i++)
                {
                    int z = (index1+index2*i) % size;
                    if(arr[z]==NULL)
                    {
                        arr[z] = n;
                        return; 
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
					cout << i << " -> " << arr[i]->data << endl;
				}
            }
		}
};


int main()
{
    DoubleHashing obj;
    obj.Insertdata(3);
    obj.Insertdata(2);
    obj.Insertdata(9);
    obj.Insertdata(6);
    obj.Insertdata(11);
    obj.Insertdata(13);
    obj.Insertdata(7);
    obj.Insertdata(12);
    obj.Display();
}