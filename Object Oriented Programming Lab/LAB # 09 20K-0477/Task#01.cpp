#include<iostream>

using namespace std;

class TASK1{
    private:
    int x;
    public:
    void setData(int x)
    {
        this->x = x;
    }
    void operator ++()
    {
        x = x * 4;
    }
    void operator ++(int )
    {
        x = x / 4;
    }
    void display()
    {
        cout << "Value of x: " << x << endl;
    }
};

int main()
{
    TASK1 Obj1, Obj2;
    Obj1.setData(4);
    cout << "Prefix: " << endl;
    ++Obj1;
    Obj1.display();
    Obj2.setData(4);
    cout << "Postfix: " << endl;
    Obj2++;
    Obj2.display();
}