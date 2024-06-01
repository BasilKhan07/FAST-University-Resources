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
            heap_size = cap;
            capacity = cap;
            arr = new int[cap];
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

        void getArray()
        {
            cout << "Enter " << capacity << " no. of elements in heap: " << endl;
            for(int i=0; i<capacity; i++)
            {
                cin >> arr[i];
            }
        }

        void HeapSort()
        {
            int *temp = new int[capacity];
            for(int i=0; i<capacity; i++)
            {
                temp[i] = ExtractMin();
                cout << temp[i] << " ";
            }
        }
};

int main()
{
    int s;
    cout << "Enter capacity Of heap: ";
    cin >> s;
    MinHeap obj(s);
    obj.getArray();
    cout << "Unsorted Array: " << endl;
    obj.PrintArray();
    for(int i=s/2-1; i>=0; i--)
    {
        obj.MinHeapify(i);
    }

    cout << "Heap Sort: " << endl;
    obj.HeapSort();
}