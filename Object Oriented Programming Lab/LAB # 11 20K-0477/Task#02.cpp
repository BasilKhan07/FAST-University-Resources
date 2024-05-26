#include<iostream>
#include<string.h>

using namespace std;

class Vehicle{
    private:
        string Make;
        string Model;
        string Color;
        int Year;
        double Milesdriven;
    public:
        string TypeOfCar;
        Vehicle(){}
        Vehicle(string typeofcar, string make, string model, string color, int year, double milesdriven)
        {
            TypeOfCar = typeofcar;
            Make = make;
            Model = model;
            Color = color;
            Year = year;
            Milesdriven = milesdriven;
        }
        string gettypeofcar()
        {
            return TypeOfCar;
        }
        string getmake()
        {
            return Make;
        }
        string getcolor()
        {
            return Color;
        }
        int getyear()
        {
            return Year;
        }
        double getmilesdriven()
        {
            return Milesdriven;
        }
        string getmodel()
        {
            return Model;
        }
};

class ElectricVehicle : virtual public Vehicle{
    private:
        double EnergyStored;
    public:
        ElectricVehicle(){}
        ElectricVehicle(double energystored, string typeofcar, string make, string model, string color, int year, double milesdriven) : Vehicle(typeofcar, make, model, color, year, milesdriven)
        {
            EnergyStored = energystored;
        }
        double getenergystored()
        {
            return EnergyStored;
        }
};

class GasVehicle : virtual public Vehicle{
    private: 
        double FuelTankSize;
    public:
        GasVehicle(){}
        GasVehicle(double fueltanksize, string typeofcar, string make, string model, string color, int year, double milesdriven) : Vehicle(typeofcar, make, model, color, year, milesdriven)
        {
            FuelTankSize = fueltanksize;
        }
        double getfueltanksize()
        {
            return FuelTankSize;
        }
};

class HighPerformance : public GasVehicle {
    private:
        double HorsePower;
        double TopSpeed;
    public:
        HighPerformance(double horsepower, double topspeed, double fueltanksize, string typeofcar, string make, string model, string color, int year, double milesdriven) : GasVehicle(fueltanksize, typeofcar, make, model, color, year, milesdriven)
        {
            HorsePower = horsepower;
            TopSpeed = topspeed;
        }
        double gethorsepower()
        {
            return HorsePower;
        }
        double gettopspeed()
        {
            return TopSpeed;
        }
};

class SportsCar : public HighPerformance{
    private:
        string GearBox;
        string DriveSystem;
    public:
        SportsCar(string gearbox, string drivesystem, double horsepower, double topspeed, double fueltanksize, string typeofcar, string make, string model, string color, int year, double milesdriven) : HighPerformance(horsepower, topspeed, fueltanksize, typeofcar, make, model, color, year, milesdriven)
        {
            GearBox = gearbox;
            DriveSystem = drivesystem;
        }
};

class HeavyVehicle : public ElectricVehicle, public GasVehicle{
    private:
        double MaximumWeight;
        int NumberOfWheels;
        double Length;
    public:
        HeavyVehicle(){}
        HeavyVehicle(double maximumheight, int numberofwheels, double length, double energystored, double fueltanksize, string typeofcar, string make, string model, string color, int year, double milesdriven) : Vehicle(typeofcar, make, model, color, year, milesdriven), ElectricVehicle(energystored, typeofcar, make, model, color, year, milesdriven), GasVehicle(fueltanksize, typeofcar, make, model, color, year, milesdriven)
        {
            MaximumWeight = maximumheight;
            NumberOfWheels = numberofwheels;
            Length = length;
        }
        double getmaximumheight()
        {
            return MaximumWeight;
        }
        int getnumberofwheels()
        {
            return NumberOfWheels;
        }
        double getlength()
        {
            return Length;
        }
};

class ConstructionTruck : public HeavyVehicle{
    private:
        string Cargo;
    public:
        ConstructionTruck(string cargo, double maximumheight, int numberofwheels, double length, double energystored, double fueltanksize, string typeofcar, string make, string model, string color, int year, double milesdriven) : HeavyVehicle(maximumheight, numberofwheels, length, energystored, fueltanksize, typeofcar, make, model, color, year, milesdriven)  
        {
            Cargo = cargo;
        }
        string getcargo()
        {
            return Cargo;
        }
};

class Bus : public HeavyVehicle{
    private:
        int NumberOfSeats;
    public:
        Bus(){}
        Bus(int numberofseats, double maximumheight, int numberofwheels, double length, double energystored, double fueltanksize, string typeofcar, string make, string model, string color, int year, double milesdriven) : HeavyVehicle(maximumheight, numberofwheels, length, energystored, fueltanksize, typeofcar, make, model, color, year, milesdriven), Vehicle(typeofcar, make, model, color, year, milesdriven)
        {
            NumberOfSeats = numberofseats;
        }
        void Display()
        {
            cout << "      Vehicle      " << endl;
            cout << "Type Of Car: " << gettypeofcar() << endl;
            cout << "Make: " << getmake() << endl;
            cout << "Model: " << getmodel() <<endl;
            cout << "Color: " << getcolor() << endl;
            cout << "Year: " << getyear() << endl;
            cout << "Miles Driven: " << getmilesdriven() << endl;
            cout << endl << "   Electric Vehicle       " << endl;
            cout << "Electric Vehicle Energy Stored: " << getenergystored() << endl;
            cout << endl << "     Gas Vehicle  " << endl;
            cout << "Gas vehicle Fuel Tank Size: " << getfueltanksize() << endl;
            cout << endl << "    Heavy Vehicle " << endl;
            cout << "Maximum Weight: " << getmaximumheight() << endl;
            cout << "Number Of Wheels: " << getnumberofwheels() << endl;
            cout << "Length: " << getlength() << endl;
            cout << endl << "       Bus" << endl;
            cout << "Number Of Seats: " << NumberOfSeats << endl;
        }
};

int main()
{
    Bus obj(4, 45.5, 4, 67.6, 20.45, 30.9, "SUV", "Honda", "K-0477", "Red", 2020, 232.232);
    obj.Display();
}
