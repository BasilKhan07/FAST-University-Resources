#include<iostream>

using namespace std;

class Person{
    protected:
    int Employee_id;
    public:
    void getData(int id)
    {
        Employee_id = id;
    }
    void displayData()
    {
        cout << "Employee Id: " << Employee_id << endl;
    }
};

class Admin : public Person{
    protected:
    string AdminName;
    private:
    int salary;
    public:
    void getData(string n, int s, int id)
    {
        AdminName = n;
        salary = s;
        Employee_id = id;
    }
    int Bonus()
    {
        return salary * 0.05;
    }
    void displayData()
    {
        cout << endl;
        cout << "Admin employee ID: " << Employee_id << endl;
        cout << "Admin employee Name: " << AdminName <<endl;
        cout << "Admin salary: " << salary << endl;
        cout << "Bonus: " << Bonus() << endl;
        cout << "Salary with Bonus: " << Bonus() + salary << endl;
    }
};

class Accounts : public Person{
    protected:
    string AccountsName;
    private:
    int salary;
    public:
    void getData(string n, int s, int id)
    {
        
        AccountsName = n;
        salary = s;
        Employee_id = id;
    }
    int Bonus()
    {
        return salary * 0.05;
    }
    void displayData()
    {
        cout << endl;
        cout << "Accounts employee ID: " << Employee_id << endl;
        cout << "Accounts employee name: " << AccountsName << endl;
        cout << "Accounts salary: " << salary << endl;
        cout << "Bonus: " << Bonus() << endl;
        cout << "Salary with Bonus: " << Bonus() + salary << endl;
    }
};

int main()
{
    Admin obj1;
    obj1.getData("Basil Ali Khan", 20000, 200477);
    Accounts obj2;
    obj2.getData("Sohaib Ashraf", 30000, 200488);
    obj1.displayData();
    obj2.displayData();
}