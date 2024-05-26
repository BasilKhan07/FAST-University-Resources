#include<iostream>
#define size 10

using namespace std;

class HashTable{
    public:
        int arr[size];

        HashTable()
        {
            for(int i=0; i<size; i++)
            {
                arr[i] = 0;
            }
        }

        int Hash_Func(int val)
        {
            return val % size;
        }

        void Insertdata(int val)
        {
            int index = Hash_Func(val);
            arr[index] = val;
        }

        int Display()
        {
           for(int i=0; i<size; i++)
            {
                if(arr[i]==0)
                {
                	cout << i << " : " << "NULL" << endl;
				}
				else
				{
					cout << i << " : " << arr[i]<< endl;
				}
            }
		}
};


int main()
{
    HashTable obj;
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