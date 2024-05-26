#include<iostream>

using namespace std;

class Bank{
    public:
    virtual void DisplayInterest()=0;
};

class HMB : public Bank{
    protected:
    int interestRate = 4;
    public:
    void DisplayInterest(){
        cout << "Interest rate of HMB: " << interestRate << endl; 
    }
};

class HBL : public Bank{
    protected:
    int interestRate = 2;
    public:
    void DisplayInterest(){
        cout << "Interest rate of HBL: " << interestRate << endl;
    }
};

class MCB : public Bank{
    protected:
    int interestRate = 3;
    public:
    void DisplayInterest(){
        cout << "Interest rate of MCB: " << interestRate << endl;
    }
};

int main()
{
    HMB Obj1;
    HBL Obj2;
    MCB Obj3;
    Obj1.DisplayInterest();
    Obj2.DisplayInterest();
    Obj3.DisplayInterest();
}