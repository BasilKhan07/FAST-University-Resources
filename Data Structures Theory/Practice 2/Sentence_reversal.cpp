#include<iostream>
#define n 10

using namespace std;
class Stack{
    private:
        int top;
        string *a;

    public:
        Stack()
        {
            a = new string[n];
            top = -1;
        }

        void push(string str)
        {
            if(top==n-1)
            {
                cout << "STACK OVERFLOW." << endl;
                return;
            }
            top++;
            a[top] = str;
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

        string peek()
        {
            if(top==-1)
            {
                return "STACK UNDERFLOW.";
            }
            return a[top];
        }

        bool IsEmpty()
        {
            return (top<0);
        }
};

int main()
{
    Stack obj;
    string str = "My name is Basil.";
    for(int i=0; i<str.length(); i++)
    {
        string word = "";
        while(str[i]!=' ' && i<str.length())
        {
            word = word + str[i];
            i++;
        }
        obj.push(word);
    }
    while(!obj.IsEmpty())
    {
        cout << obj.peek() << endl;
        obj.pop();
    }
}