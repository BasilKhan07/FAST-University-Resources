#include <iostream>
using namespace std;

class HT{
    public:
        int *arr;
        int size;

    HT(int s){
        size = s;
        for(int i=0;i<size;i++){
            arr[i]=0;
        }
    }

    int HashingFunction(int val){
        return val%size;                   // lets consider table size is 9 
    }

    int getIndex_toInsert(int val)
    {      
        int index = HashingFunction(val);        // lets consider table size is 9 
        if(arr[index] == 0 || arr[index]==-1){              // so it's only capable of storing max of 9 values
            return index;
        }

        int i=1;
        while(arr[index]!=0 && arr[index]!=-1){
            index = (val+i)%size;          // LINEAR PROBING
            if(i==size){
                return -1;
            }
            i++;
        }
        return index;
    }


    void insert(int val){
        int index = getIndex_toInsert(val);
        if(index==-1){
            cout << endl << "Table already full";
            return;
        }

        arr[index] = val;
    }

    void deleteval(int val){

        if(!search(val)){
            cout << endl << "No such data to delete";
            return;
        }
         
        int index = HashingFunction(val);
        if(arr[index]==val){
            arr[index]=-1;
            cout << endl << "Deleted";
            return;
        }

        int i=1;
        while(arr[index]!=0 && i!=size) //if index has 0  
        {                               //it means the val we
            index = (val+i)%size;       //are searching should 
            if(arr[index]==val){       //be before this index
                arr[index]=-1;         //otherwise doesn't exist
                cout << endl << "Deleted";
                return;
            }

        }
        cout << endl << "No such data to delete";
    }

    bool search(int val){
        int index = HashingFunction(val);

        if(arr[index]==val){
            return true;
        }

        int i=1;
        while(arr[index]!=0 && i!=9)
        {
            index = (val+i) % size;
            if(arr[index]==val){
                return true;
            }

            i++;
        }
        return false;
    }

    void display(){
        cout << endl << "CURRENT TABLE" << endl;
        for(int i=0; i<size; i++){
            cout << arr[i] << endl;
        }
    }
};

int main(){
    HT table(9);
    table.insert(78);
    table.insert(56);
    table.insert(21);
    table.insert(17);
    table.insert(26);
    table.insert(35);
    table.display();
    table.deleteval(26);
    if(table.search(35)){
        cout << endl << "35 exist";
    }else
    cout << endl << "35 doesn't exist";
    table.display();
    table.insert(18);
    table.display();
}