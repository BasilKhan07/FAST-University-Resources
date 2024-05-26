#include<iostream>

using namespace std;

class Shape{
    private:
    float length;
    public:
    void setData(float l)
    {
        length = l;
    }
    float Area()
    {
        return length*length;
    }
    Shape operator +(Shape s)
    {
        Shape temp;
        temp.length = length + s.length;
        return temp;
    }
};

int main()
{
    Shape shape1, shape2;
    shape1.setData(3);
    shape2.setData(4);
    cout << "Area of shape1: " << shape1.Area() << endl;
    cout << "Area of shape2: " << shape2.Area() << endl;
    cout << "Sum of area of shape1 and shape2: " << shape1.Area() + shape2.Area() << endl;
}