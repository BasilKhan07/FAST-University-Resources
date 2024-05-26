#include<iostream>

using namespace std;

class Shape{
    protected:
    int length, breadth, height, radius;
};

class Cube : public Shape{
    public:
    Cube(int l)
    {
        length = l;
    }
    void Volume()
    {
        cout << "Volume of cube: " << length * length * length << endl;
    }
};

class Cylinder : public Shape{
    public:
    Cylinder(int r, int h)
    {
        radius = r;
        height = h;
    }
    void Volume()
    {
        cout << "Volume of cylinder: " << 3.142 * radius * radius * height << endl;
    }
};

class Rectangular : public Shape{
    public:
    Rectangular(int l, int b, int h)
    {
        length = l;
        breadth = b;
        height = h;
    }
    void Volume()
    {
        cout << "Volume of rectangle: " << length * height * breadth << endl;
    }
};

int main()
{
    Cube obj1(3);
    obj1.Volume();
    Cylinder obj2(2, 3);
    obj2.Volume();
    Rectangular obj3(2, 3, 4);
    obj3.Volume();
}