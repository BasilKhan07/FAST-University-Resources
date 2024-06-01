#include<iostream>
#define MAX 100

using namespace std;

class Stack{
	private:
		int top;
		
	public:	
		char a[MAX];
		
		Stack()
		{
			top = -1;
		}
		
		bool push(char x)
		{
			if(top>=(MAX-1))
			{
				cout << "STACK OVERFLOW." << endl;
				return false;
			}
			else
			{
				a[++top] = x;
			}
		}
		
		char pop()
		{
			if(top<0)
			{
				cout << "STACK IS UNDERFLOW." << endl;
				return 0;
			}
			else
			{
				char x = a[top--];
				return x;
			}
		}
		
		char peek()
		{
			if(top<0)
			{
				cout << "STACK IS EMPTY." << endl;
			}
			else
			{
				char x = a[top];
				return x;
			}
		}
		
		bool isEmpty()
		{
			return (top<0);
		}
};

int precedence(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='-' || ch=='+')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(string str)
{
    Stack obj;
    string postfix;
    for(int i=0; i<str.length(); i++)
    {
        if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            postfix = postfix + str[i]; 
        }
        else if(str[i]=='(')
        {
            obj.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(!obj.isEmpty() && obj.peek() != '(')
            {
                postfix = postfix + obj.peek();
                obj.pop();
            }
            if(!obj.isEmpty())
            {
                obj.pop();
            }
        }
        else
        {
            while(!obj.isEmpty() && precedence(obj.peek()) >= precedence(str[i]))
            {
                postfix = postfix + obj.peek();
                obj.pop();
            }
            obj.push(str[i]);
        }
    }
    while(!obj.isEmpty())
    {
        postfix = postfix + obj.peek();
        obj.pop();
    }
    return postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << endl << infix << endl << endl;
    cout << "Postfix Expression: " << endl << InfixToPostfix(infix) << endl;
}
