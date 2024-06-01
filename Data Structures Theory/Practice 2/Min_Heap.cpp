#include<iostream>
#define INT_MIN (-2147483647 - 1)

using namespace std;

void Swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap{
    public:
        int *arr;
        int capacity; // total heap capacity
        int heap_size; // Number of element in that heap capacity present

        MinHeap(int cap)
        {
            heap_size = 0;
            capacity = cap;
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

        int getMin()
        {
            return arr[0];
        }

        void InsertKey(int val)
        {
            if(heap_size == capacity)
            {
                cout << "Heap Overflow. " << endl;
                return;
            }
            heap_size++;
            int i = heap_size-1;
            arr[i] = val;
            while(i!=0 && arr[Parent(i)] > arr[i])
            {
                Swap(arr[i], arr[Parent(i)]);
                i = Parent(i);
            }
        }

        int ExtractMin()
        {
            if(heap_size<=0)
            {
                return INT_MIN;
            }
            if(heap_size==1)
            {
                heap_size--;
                return arr[0];
            }
            int root = arr[0];
            arr[0] = arr[heap_size-1];
            heap_size--;
            MinHeapify(0);
            return root;
        }

        int MinHeapify(int i)
        {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if(l<heap_size && arr[l] < arr[i])
            {
                smallest = l;
            }
            if(r<heap_size && arr[r] < arr[smallest])
            {
                smallest = r;
            }
            if(smallest!=i)
            {
                Swap(arr[i], arr[smallest]);
                MinHeapify(smallest);
            }
        }

        void DeleteKey(int i)
        {
            DecreaseKey(i, INT_MIN);
            ExtractMin();
        }

        void DecreaseKey(int i, int new_val)
        {
            arr[i] = new_val;
            while(i!=0 && arr[Parent(i)] > arr[i])
            {
                Swap(arr[Parent(i)], arr[i]);
                i = Parent(i);
            }
        }
};

int main()
{
    int s;
    cout << "Enter size of Min Heap: ";
    cin >> s;
    MinHeap obj(s);
    cout << "Min Heap Created." << endl;
    int choice, val;
    do
    {
        cout << "Enter Choice: " << endl;
        cout << "1. Insert key." << endl;
        cout << "2. Search Key." << endl;
        cout << "3. Delete Key." << endl;
        cout << "4. Get Min." << endl;
        cout << "5. Extract Min."  << endl;
        cout << "6. Traverse Min Heap." << endl;
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
                cout << obj.getMin() << endl;
                break;
            }
            case 5:
            {
                cout << "Extract Min value: ";
                cout << obj.ExtractMin() << endl;
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