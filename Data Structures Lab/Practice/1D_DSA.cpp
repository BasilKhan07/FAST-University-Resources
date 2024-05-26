#include <iostream>
#include <stdio.h>

using namespace std;

class ArrayException{
    public:
        virtual void response()=0;
};

class ArraySizeExcaption: public ArrayException{
    public:
        int size;
        
        ArraySizeExcaption(int s): size(s){}

        void response()
        {
            cout << "Error: Array size is negative." << endl;
        }
};

class ArrayOutOfBoundException: public ArrayException{
    public:
        int index;
        int size; 

        ArrayOutOfBoundException(int i, int s): index(i), size(s){}

        void response()
        {
            cout << "Error: Index " << index << " is out of bound." << endl;
        }
};

class SafeArray{
    protected:
        int *arr;
        int size;
    public:
        SafeArray(int s=10): size(s)
        {
            if(size<0)
            {
                throw ArraySizeExcaption(size);
            }
            arr = new int[size];
            for(int i=0; i<size; i++)
            {
                arr[i] = 0;
            }
        }
        void set(int index, int value)
        {
            rangecheck(index);
            arr[index] = value;
        }
        int get(int index)
        {
            rangecheck(index);
            return arr[index];
        }
    protected:
        void rangecheck(int index)
        {
            try
            {
                if((index<0))
                {
                    throw ArraySizeExcaption(size);
                }
            }
            catch(ArraySizeExcaption &e)
            {
                throw;
            }
            try
            {
                if(index>=size)
                {
                    throw ArrayOutOfBoundException(index, size);
                }
            }
            catch(ArrayOutOfBoundException &e)
            {
                throw;
            }
        }
};

int main()
{
    SafeArray *myarray;
    myarray = new SafeArray(5);
    for(int i=-2; i<7; i++)
    {
        try
        {
            myarray->set(i,i);
        }
        catch(ArraySizeExcaption &e)
        {
            e.response();
        }
        catch(ArrayOutOfBoundException &e)
        {
            e.response();
        }
    }
}