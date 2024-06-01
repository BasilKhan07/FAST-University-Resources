#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }     

        node(){
            data = 0;
            next = NULL;
        }
};

class HT{           // Hashing Table class
    public:
        node* arr[10];
        
        HT(){
            for(int i=0; i<10; i++){
                arr[i] = NULL;
            }
        }

        int HashingFunction(int val){
            int index = 0;
            index = val%10;
            return index;
        }

        void insert(int val){
            int index = HashingFunction(val);
            if(arr[index]!=NULL){
                node* temp = arr[index];
                
                while(temp->next!=NULL){
                    temp = temp->next;
                }

                temp->next = new node(val);
            }
            else{
                arr[index] = new node(val);
            }
        }

        bool search(int val){
            int index = HashingFunction(val);
            if(arr[index]==NULL){
                return false;
            }
            
            if(arr[index]!=NULL){
                if(arr[index]->data==val){
                    return true;
                }
                else {
                    node* temp = arr[index];
                    while(temp!=NULL){
                        if(temp->data==val){
                            return true;
                        }
                        temp = temp->next;
                    }
                }
            }
            return false;
        }

        void update(int old, int newval){
            if(!search(old)){
                cout << endl << "The given data doesn't exist";
                return;
            }

            int index = HashingFunction(old);
            if(arr[index]->data==old){
                arr[index]->data = newval;
                return;
            }
            else{
                node* temp = arr[index];
                while(temp->data!=old){
                    temp = temp->next;
                }
                temp->data = newval;
            }
        }

        void deleteval(int val){
            if(!search(val)){
                cout << endl << "No such data exist";
                return;
            }

            int index = HashingFunction(val);
            if(arr[index]->data==val){
                node* todelete = arr[index];
                arr[index] = arr[index]->next;
                delete todelete;
                return;
            }

            node* temp = arr[index];
            while(temp->next->data!=val){
                temp = temp->next;
            }

            node* todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
        }

        void display(){
            cout << "START" << endl;
            for(int i=0; i<10; i++){
                if(arr[i]!=NULL){
                    node* temp = arr[i];
                    while(temp!=NULL){
                        cout << temp->data << " ";
                        temp = temp->next;
                    }
                }
                else{
                    cout << "_";
                }
                cout << endl;
            }
            cout << "END";
        }
};

int main(){
    HT hash;
    hash.insert(17);
    hash.insert(27);
    hash.insert(45);
    hash.insert(24);
    hash.insert(65);
    hash.insert(3);
    hash.insert(75);
    hash.display();
    hash.deleteval(65);
    cout << endl << "After deletion of 65 :" << endl;
    hash.display();
}