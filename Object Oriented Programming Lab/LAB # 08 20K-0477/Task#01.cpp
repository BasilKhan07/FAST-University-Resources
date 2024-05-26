#include<iostream>

using namespace std;

class Animal{
    public:
    void animalSound()
    {
        cout << "The animal makes sound." << endl;
    }
};

class Cat : public Animal{
    public:
    void animalSound()
    {
        cout << "The cat says meow." << endl;
    }
};

class Dog : public Animal{
    public:
    void animalSound()
    {
        cout << "The dog says bow wow." << endl;
    }
};

class Duck : public Animal{
    public:
    void animalSound()
    {
        cout << "The duck says quack quack." << endl;
    }
};

int main()
{
    Animal a;
    a.animalSound();
    Cat c;
    c.animalSound();
    Dog d;
    d.animalSound();
    Duck D;
    D.animalSound();
}