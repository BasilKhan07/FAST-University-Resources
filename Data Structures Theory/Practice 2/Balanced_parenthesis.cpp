#include<iostream>
#define n 100

using namespace std;

class Stack{
    private:
        int top;
        char *a;

    public:
        Stack()
        {
            a = new char[n];
            top = -1;
        }

        void push(char val)
        {
            if(top>=n-1)
            {
                cout << "STACK OVERFLOW." << endl;
                return;
            }
            top++;
            a[top] = val;
        }

        char pop()
        {
            if(top<0)
            {
                cout << "STACK UNDERFLOW." << endl;
                return 0;
            }
            top--;
        }

        char peek()
        {
            if(top<0)
            {
                cout << "STACK UNDERFLOW." << endl;
                return 0;
            }
            return a[top];
        }

        bool IsEmpty()
        {
            return (top<0);
        }
};

bool IsValid(string s)
{
    Stack obj;
    bool ans = true;
    int len = s.size();
    for(int i=0; i<len; i++)
    {
        if(s[i]=='{' || s[i]=='(' || s[i]=='[')
        {
            obj.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(!obj.IsEmpty() && obj.peek()==')')
            {
                obj.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if(s[i]==']')
        {
            if(!obj.IsEmpty() && obj.peek()=='[')
            {
                obj.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if(s[i]=='}')
        {
            if(!obj.IsEmpty() && obj.peek()=='{')
            {
                obj.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if(!obj.IsEmpty())
    {
        return false;
    }
    return ans;
}

int main()
{
    string s = "{()}";
    if(IsValid(s))
    {
        cout << "Valid String" << endl;
    }
    else
    {
        cout << "Invalid String" << endl;
    }
}