#include<iostream>

using namespace std;

class prinClass;

class Perimeter{
    private:
    float length;
    float breadth;
    friend class printClass;
    public:
    void setData(float l, float b)
    {
        length = l;
        breadth = b;
    }
    float perimeter()
    {
        return 2 * (length+breadth);
    }
};

class printClass{
    public:
    void display(Perimeter p)
    {
        cout << "Length: " << p.length << endl;
        cout << "Breadth: " << p.breadth << endl;
        cout << "Perimeter: " << p.perimeter() << endl;
    }
};

int main()
{
    Perimeter Obj1;
    Obj1.setData(4,3);
    printClass Obj2;
    Obj2.display(Obj1); 
}

