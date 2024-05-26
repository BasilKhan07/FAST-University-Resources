#include<iostream>

using namespace std;

class Shape{
    protected:
    float length;
    float breadth;
    public:
    void setData(float l, float b)
    {
        length = l;
        breadth = b;
    }
    virtual float getArea()=0;
};

class Rectangle : public Shape{
    public:
    float getArea(){
        return length * breadth;
    }
};

class Triangle : public Shape{
    public:
    float getArea(){
        return 0.5 * length * breadth;
    }
};

int main()
{
    Rectangle r;
    Triangle t;
    r.setData(5,4);
    cout << "Area of Rectangele: " << r.getArea() << endl;
    t.setData(4,8);
    cout << "Area of Triangle: " << t.getArea() << endl;
}