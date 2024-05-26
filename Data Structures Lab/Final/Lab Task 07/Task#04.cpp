#include<iostream>
#define n 4

using namespace std;

class Queue{
	public:
		int front , rear;
		int *array;
		
		Queue()
		{
			array = new int[n];
			front = -1;
			rear = -1;
		}
		
		void Enqueue(int val)
		{
			if(rear == n-1)
			{
				cout << "QUEUE OVERFLOW!!" << endl;
				return ;
			}
			rear++;
			array[rear] = val;
			if(front == -1)
			{
				front++;
			}
		}
		
		int Dequeue()
		{
			if(front==-1 || front > rear)
			{
				cout << "QUEUE IS EMPTY!!" << endl;
				return 0;
			}
			int x = array[front++];
			return x;
		}	
};

int main()
{
	Queue obj;
	cout << "QUEUE size is 4." << endl;
	obj.Enqueue(0);
	obj.Enqueue(1);
	obj.Enqueue(2);
	obj.Enqueue(3);
	obj.Enqueue(4);
	cout << obj.Dequeue() << endl;
	cout << obj.Dequeue() << endl;
	cout << obj.Dequeue() << endl;
	cout << obj.Dequeue() << endl;
	cout << obj.Dequeue() << endl;
}