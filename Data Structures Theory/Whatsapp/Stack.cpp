#include<iostream>

using namespace std;

class Stack{
    public:
        int size;
        int *arr;
        int top;

        Stack()
        {
            size = 0;
            arr = NULL;
            top = -1;
        }

        Stack(int val)
        {
            size = val;
            arr = new int[size];
            top = -1;
        }

        void push(int val)
        {
            if(top == size-1)
            {   
                cout << "STACK OVERFLOW." << endl;
                return;
            }
            top++;
            arr[top] = val;
        }

        int Top()
        {
            if(top == -1)
            {
                cout << "STACK IS EMPTY." << endl;
                return -1;
            }
            return arr[top];
        }

        int pop()
        {
            if(top == -1)
            {
                cout << "STACK IS EMPTY." << endl;
                return -1;
            }
            int x = arr[top];
            top--;
            return x;
        }
};

int main()
{
    Stack obj(5);
    obj.pop();
    obj.Top();
    obj.push(3);
    obj.push(3);
    obj.push(3);
    obj.push(3);
    obj.push(3);
    obj.push(3);
    cout << obj.Top();
}