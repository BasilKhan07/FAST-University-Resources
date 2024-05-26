#include<iostream>

using namespace std;

class CounterType{
	private:
		int Count;
		
	public:
		void countInc(void){
			Count++;
		}
		void countDec(void){
			Count--;
		}
		int getCount(void){
			if(Count<0)
			{
				return 0;
			}
			else
			{
				return Count;
			}
		}
};

int main()
{
	CounterType ctr;
	long num;
	int count, x;
	cout << "Number to Count: ";
	cin >> num;
	cout << endl;
    while(num!=0)
	{
    	x=num%10;
    	num=num/10;
    	if(x==1)
		{
    		ctr.countInc();
		}
		else if(x==0)
		{
			ctr.countDec();
		}
		else
		{
			continue;
		}
	}
	cout << "Count : "<< ctr.getCount();
	}
