#include<iostream>
#define MAX 10

using namespace std;

class Stack{
	private:
		int top;
		
	public:	
		int a[MAX];
		
		Stack()
		{
			top = -1;
		}
		
		bool push(int x)
		{
			if(top>=(MAX-1))
			{
				cout << "STACK OVERFLOW." << endl;
				return false;
			}
			else
			{
				a[++top] = x;
				cout << x << " pushed into Stack." << endl;
			}
		}
		
		int pop()
		{
			if(top<0)
			{
				cout << "STACK IS UNDERFLOW." << endl;
				return 0;
			}
			else
			{
				int x = a[top--];
				return x;
			}
		}
		
		int peek()
		{
			if(top<0)
			{
				cout << "STACK IS EMPTY." << endl;
			}
			else
			{
				int x = a[top];
				return x;
			}
		}
		
		bool isEmpty()
		{
			return (top<0);
		}
};

int main()
{
	Stack obj;
	int num[MAX];
	cout << "Enter ten integers: " << endl;
	for(int i=0; i<=MAX; i++)
	{
		cin >> num[i];
		obj.push(num[i]);
	}	
	for(int i=MAX; i>0; i--)
	{
		cout << obj.pop() << endl;
	}
	if(obj.isEmpty()==1)
	{
		cout << "STACK IS EMPTY" << endl;
	}	
}
