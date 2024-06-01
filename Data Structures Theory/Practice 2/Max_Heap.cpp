#include<iostream>
#define INT_MAX 2147483647

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MaxHeap{
    public:
        int *arr;
        int capacity;
        int heap_size;
    
        MaxHeap(int cap)
        {
            capacity = cap;
            heap_size = 0;
            arr = new int[cap];
        }

        void LinearSearch(int val)
        {
            for(int i=0; i<heap_size; i++)
            {
                if(arr[i] == val)
                {
                    cout << "Value Found." << endl;
                    return;
                }
            }
            cout << "Value Not Found." << endl; 
        }

        void PrintArray()
        {
            for(int i=0; i<heap_size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        int Parent(int i) // For accessing Parent node of particular indice
        {
            return (i-1)/2;
        }

        int left(int i) // for accessing left node of particular indice
        {
            return (2*i+1);
        }

        int right(int i) // for accessing right node of particular indice
        {
            return (2*i+2);
        }

        int getMax()
        {
            return arr[0];
        }

        void InsertKey(int val)
        {
            if(heap_size == capacity)
            {
                cout << "Heap Overflow." << endl;
                return;
            }
            heap_size++;
            int i = heap_size-1;
            arr[i] = val;
            while(i!=0 && arr[Parent(i)]<arr[i])
            {
                swap(arr[i], arr[Parent(i)]);
                i = Parent(i);
            }
        }

        int ExtractMax()
        {
            if(heap_size <= 0)
            {
                return -1;
            }
            if(heap_size == 1)
            {
                heap_size--;
                return arr[0];
            }
            int root = arr[0];
            arr[0] = arr[heap_size-1];
            heap_size--;
            MaxHeapify(0);
            return root;
        }

        void MaxHeapify(int i)
        {
            int l = left(i);
            int r = right(i);
            int largest = i;
            if(l<heap_size && arr[l]>arr[i])
            {
                largest = l;
            }
            if(r<heap_size && arr[r]>arr[largest])
            {
                largest = r;
            }
            if(largest!=i)
            {
                swap(arr[largest], arr[i]);
                MaxHeapify(largest);
            }
        }

        void DeleteKey(int i)
        {
            DecreaseKey(i, INT_MAX);
            ExtractMax();
        }

        void DecreaseKey(int i, int new_val)
        {
            arr[i] = new_val;
            while(i!=0 && arr[Parent(i)] < arr[i])
            {
                swap(arr[Parent(i)], arr[i]);
                i = Parent(i);
            }
        }
};

int main()
{
    int s;
    cout << "Enter size of Min Heap: ";
    cin >> s;
    MaxHeap obj(s);
    cout << "Min Heap Created." << endl;
    int choice, val;
    do
    {
        cout << "Enter Choice: " << endl;
        cout << "1. Insert key." << endl;
        cout << "2. Search Key." << endl;
        cout << "3. Delete Key." << endl;
        cout << "4. Get Max." << endl;
        cout << "5. Extract Max."  << endl;
        cout << "6. Traverse Max Heap." << endl;
        cout << "7. Clear screen." << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                cout << "Insert Operation: " << endl;
                cout << "Enter value to insert in heap: ";
                cin >> val;
                obj.InsertKey(val);
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "Search Operation: " << endl;
                cout << "Enter value to search: ";
                cin >> val;
                break;
            }
            case 3:
            {
                cout << "Delete Operation: " << endl;
                cout << "Enter value to delete: ";
                cin >> val;
                obj.DeleteKey(val);
                break;
            }
            case 4:
            {
                cout << "Get Min value: ";
                cout << obj.getMax() << endl;
                break;
            }
            case 5:
            {
                cout << "Extract Min value: ";
                cout << obj.ExtractMax() << endl;
                break;
            }
            case 6:
            {
                cout << "Print Heap: " << endl;
                obj.PrintArray();
                break;
            }
            case 7:
            {
                system("cls");
                break;
            }
            default:
            {
                cout << "Enter valid choice!" << endl;
                break;
            }
        }
    }
    while(choice!=0);
}