#include<iostream>
#define n 4

using namespace std;

class Stack{
    private:
        int top;
        int *a;

    public:
        Stack()
        {
            a = new int[n];
            top = -1;
        }

        void push(int val)
        {
            if(top==n-1)
            {
                cout << "STACK OVERFLOW." << endl;
                return;
            }
            top++;
            a[top] = val;
        }

        void pop()
        {
            if(top==-1)
            {
                cout << "STACK UNDERFLOW." << endl;
                return;
            }
            top--;
        }

        int peek()
        {
            if(top==-1)
            {
                cout << "STACK UNDERFLOW." << endl;
                return -1;
            }
            return a[top];
        }

        bool IsEmpty()
        {
            return (top<0);
        }
        int ele[n];
        void reverse()
        {
            static int i=0;
            if(IsEmpty())
            {
                i = i - n;
                return;
            }
            ele[i] = peek();
            i++;
            pop();
            reverse();
            push(ele[i]);
            i++;
        }
};
int main()
{
    Stack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    cout << obj.peek();
    obj.reverse();
    cout << obj.peek();
    obj.pop();
    cout << obj.peek();
}