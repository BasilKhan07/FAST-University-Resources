//template<class type> class class_name{};
#include<iostream>
using namespace std;
//template <class X>class array
class array
{
	private:
		struct block{
			int size;
			int *arr_pointer;
		};
		block *s;
		public:
			array(int size){
				s = new block;
				s->size = size;
				s-> arr_pointer=new int[s->size];
			}
			void addelement(int index, int data){
				if(index>=0&&index<=s->size-1)
				s->arr_pointer[index]=data;
				else
				cout<<"\n  index is not valid";
			}
			void viewElement(int index, int &data){
				if(index>=0&&index<=s->size-1)
				data=s->arr_pointer[index];
				else
				cout<<"index is not valid";
			}
			void viewList(){
				int i;
				for(i=0; i<s->size;i++)
				cout<<" "<<s->arr_pointer[i];
			}
};
int main(){
	int data;
	array obj(3);
	obj.addelement(0,23);
	obj.addelement(1,22);
	obj.addelement(2,11);
	obj.viewElement(0,data);
	cout<<"value is: "<<data;
	//obj.viewList();
}
