#include<iostream>

using namespace std;

class Employee{
    protected:
        string Name;
        string Code;
     public:
        Employee(string n, string c)
        {
            Name = n;
            Code = c;
        }
};

class Consultant : virtual public Employee{
    protected:
        int YearsOfExperience;
    
    public:
        Consultant(int y, string n, string c) : Employee(n, c)
        {
            YearsOfExperience = y;
        } 
};

class Manager : virtual public Employee{
    protected:
        int NoOfTeams;

    public:
        Manager(int t, string n, string c) : Employee(n, c)
        {
            NoOfTeams = t;
        }
};

class ConsultantManager : public Consultant, public Manager{
    public:
        ConsultantManager(string n, string c, int y, int t) : Employee(n, c), Manager(t, n, c), Consultant(y, n, c)
        {

        }
        void Display()
        {
            cout << "Name Of Employee: " << Name << endl;
            cout << "Code: " << Code << endl;
            cout << "Years Of Experience: " << YearsOfExperience << endl;
            cout << "No of Teams: " << NoOfTeams << endl;
        }
};

int main()
{
    ConsultantManager obj("Ali", "S-123", 17, 5);
    obj.Display();
    return 0;
}