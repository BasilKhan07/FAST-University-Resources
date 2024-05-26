#include<iostream>

using namespace std;

class Numbers{
	private:
		int size;
		int *ptr;
	
	public:
		Numbers(int x, int y)
		{
			cout << "Constructor Called: " << endl;
			ptr = new int;
			*ptr = x;
			size = y;
		}
		Numbers(const Numbers &o)
		{
			cout << endl << "Copy Constructor Called!! " << endl;
			ptr = new int(*o.ptr);
			size = o.size;
			
		}
		~Numbers()
		{
			cout << "Destructor Called." << endl;
			delete ptr;
		}
		void Display()
		{
			cout << "Pointer Variable: " << *ptr << endl;
			cout << "Size: " << size << endl;
		}
		void Modify(int x, int y)
		{
			*ptr = x;
			size = y;
		}
};

int main()
{
	Numbers Obj1(5,6);
	cout << "Value in Object 1: " << endl;
	Obj1.Display();
	Numbers Obj2=Obj1;
	cout << endl << "Value in Object 2: " << endl;
	Obj2.Display();
	Obj1.Modify(7,9);
	cout << endl << "After Modyfying Object 1: " << endl;
	Obj1.Display();
	cout << endl << "Values in Object 2: " << endl;
	Obj2.Display();
	cout << endl;
}
