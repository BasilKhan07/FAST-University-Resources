#include<iostream>
//using namespace std;

class Car {
public:
    std::string model;
	int numOfDoors;
	std::string color;

    void accelerate() {
        std::cout << "logic for acceleration:\n";
        

    }

    void brake() {
        std::cout<<"logic for brake:\n";
    }

   
};

int main() {

    Car mycar;

    mycar.accelerate();
    mycar.brake();
    
    return 0;
}
