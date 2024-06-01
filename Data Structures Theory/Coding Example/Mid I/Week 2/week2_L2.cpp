#include<iostream>
using namespace std;
class ArrayException{
	public:
		virtual void response()=0;
	
};

class ArraySizeException: public ArrayException{
	public: int size;
	ArraySizeException(int s): size(s){
		
	}
	void response(){
		cout<<"Error: the array size is negative"<<endl;
		
	}
};
class ArrayOutofBoundsException: public ArrayException{
	public:
	int index;
	int size;
	public:
	ArrayOutofBoundsException(int i, int s) : index(i), size(s){
}	
void response(){
	}
};
class safeArray{
	protected: 
	int *data;
	int size;
	public:
		safeArray(int s=10):size(s){
			if (size<=0) throw ArraySizeException(size);
			data==new int[s];
			//if(data==0) throw bad_allocation execption raised by C++ automatically
			for(int i=0; i<size;i++){
				data[i]=0;
				//cout<<"hello";
			}
		}void set(int index, int value){
			rangecheck(index);
			data[index]=value;
		}
		int get(int index){
			rangecheck(index);
			return data[index];
		}
protected:
	void rangecheck(int index){
		try{
			if((index<0)|| (index>=size)){
				throw ArrayOutofBoundsException(index, size);
			}
		}
			catch (ArrayOutofBoundsException &e){
				cout<<"Caught"<<endl; 
				throw;
			}
		}
		
};
int main(){
	safeArray *myarray;
	myarray=new safeArray(15);
	try{
		
		myarray->set(3,10);
	myarray->get(-1);
	}
	catch (ArrayOutofBoundsException &e){
		cout<<"index"<<e.index<<"is out of range"<<endl;
	}
for(int i=-2;i<=15;i++){
	try{ myarray->set(i,i);
	if(i==7){
		new safeArray(-10);
	}
	
	}
	catch( ArrayOutofBoundsException &e){
		cout<<"index"<<e.index<<"is out of range"<<endl;
	}
	catch( ArrayException &e){
		e.response();
	}
}

}
	

