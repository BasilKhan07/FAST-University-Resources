#include<iostream>
using namespace std;

class Circle {
public:
    float r, area;

    void input() {
        cout << "Enter radius of a circle:";
        cin >> r;

    }

    void findArea() {
        area = 3.14 * r * r;
        cout << "Area of circle is:\n" << area;
    }

    void display() {
        cout << "\n Area of circle is:\n" << area;
    }
};

int main() {

    Circle obj;

    obj.input();
    obj.findArea();
    obj.display();

    return 0;
}
