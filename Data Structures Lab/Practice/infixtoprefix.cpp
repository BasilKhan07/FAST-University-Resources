#include<iostream>
#include<algorithm>
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

int Precedence(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '/' || c == '*')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtoprefix(string str)
{
    Stack obj;
    string prefix;
    reverse(str.begin(), str.end());
    for(int i=0; i<str.length(); i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            prefix = prefix + str[i];
        }
        else if(str[i]==')')
        {
            obj.push(str[i]);
        }
        else if(str[i]=='(')
        {
            while(!obj.IsEmpty() && obj.peek()!=')')
            {
                prefix = prefix + obj.peek();
                obj.pop();
            }
            if(!obj.IsEmpty())
            {
                obj.pop();
            }
        }
        else
        {
            while(!obj.IsEmpty() && Precedence(obj.peek()) >= Precedence(str[i]))
            {
                prefix = prefix + obj.peek();
                obj.pop();
            }
            obj.push(str[i]);
        }
    }
    while(!obj.IsEmpty())
    {
        prefix = prefix + obj.peek();
        obj.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Infix Expression: " << endl << infix << endl << endl;
    cout << "Postfix Expression: " << endl << infixtoprefix(infix) << endl;
}