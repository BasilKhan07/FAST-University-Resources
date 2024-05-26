#include<iostream>
#include<fstream>

using namespace std;

class Person{
    private:
        string Name;
        int Age;
    public:
        Person(){}
        Person(string name, int age)
        {
            Name = name;
            Age = age;
        }
        void display()
        {
            cout << "Name: " << Name << endl;
            cout << "Age: " << Age << endl;
        }
};

int main()
{
    ofstream add;
    Person person1("Basil Ali Khan", 19);
    add.open("Task#03.bin", ios::out | ios::binary);
    if(!add)
    {
        cout << "Error Opening File !" << endl;
    }
    else
    {
        add.write((char *)&person1, sizeof(person1));
        add.close();
    }
    ifstream view;
    Person person2;
    view.open("Task#03.bin", ios::in | ios::binary);
    if(!view)
    {
        cout << "Error Opening File !" << endl;
    }
    else
    {
        view.read((char *)&person2, sizeof(person2));
        person2.display();
    }
}