#include<iostream>
using namespace std;

class Car {
public:
    string model;
	int numOfDoors;
	string color;

    void accelerate() {
        cout << "logic for acceleration:\n";
        

    }

    void brake() {
        cout<<"logic for brake:\n";
    }

   
};

int main() {

    Car mycar;

    mycar.accelerate();
    mycar.brake();
    
    return 0;
}
