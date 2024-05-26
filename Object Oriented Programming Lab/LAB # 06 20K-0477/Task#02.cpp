#include<iostream>

using namespace std;

class STATIC{
	private:
		static int num;
		
	public:
		static void func1()
		{
			cout << "Number: " << num;
			num++;
		}
};

int STATIC::num=10;

int main()
{
	cout << "Method 1:" << endl;
	STATIC::func1();
	cout << endl;
	cout << "Method 2:" << endl;
	STATIC s;
	s.func1();
}
