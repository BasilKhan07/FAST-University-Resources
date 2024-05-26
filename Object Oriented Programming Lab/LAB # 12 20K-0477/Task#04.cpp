#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Participant{
    private:
        int ID;
        char  Name[20];
        int Score;
    public:
        void getData()
        {
            cout << endl << endl << "PARTICIPANT INFORMATION:" << endl;
            cout << "Enter ID: ";
            cin >> ID;
            cout << "Enter Name: ";
            cin >> Name;
            cout << "Enter Score: ";
            cin >> Score;
        }
        void Display()
        {
            cout << endl << "PARTICIPANT FOUND" << endl;
            cout << "Name: " << Name << endl;
            cout << "ID: " << ID << endl;
            cout << "Score: " << Score << endl; 
        }
        void Input()
        {
            Participant obj;
            ofstream add;
            add.open("Task#04.dat", ios::out | ios::app | ios::binary);
            if(!add)
            {
                cout << "File not created !" << endl;
            }
            else
            {
                obj.getData();
                add.write((char *)&obj, sizeof(obj));
                add.close();
            }
        }
        void Displayallrecord()
        {
            ifstream all;
            Participant obj;
            all.open("Task#04.dat", ios::in | ios::binary);
            all.read((char *)&obj, sizeof(obj));
            while(!all.eof())
            {
                obj.Display();
                all.read((char *)&obj, sizeof(obj));
            }
        }
        void Output()
        {
            char name[20];
            cout << "Enter Name to find Participant: ";
            cin >> name;
            Participant obj;
            ifstream search;
            search.open("Task#04.dat", ios::in);
            if(!search)
            {
                cout << "File not created !" << endl;
            }
            search.read((char *)&obj, sizeof(obj));
            while(!search.eof())
            {
                if(!strcmp(name, obj.Name))
                {
                    obj.Display();
                }
                search.read((char *)&obj, sizeof(obj));
            }
        }
        int Max()
        {
            ifstream find;
            find.open("Task#04.dat", ios::in | ios::binary);
            Participant obj;
            find.read((char*)&obj, sizeof(obj));
            int max = 0;
            string name;
            while (!find.eof()) 
            {
                if (obj.Score > max) 
                {
                    max = obj.Score;
                    name = obj.Name;
                }
                find.read((char*)&obj, sizeof(obj));
            }
            find.close();
            cout << endl << "Highest Scorer: " << name;
            return 0;
        }
};

int main()
{
    Participant Obj;
    Obj.Displayallrecord();
    Obj.Input();
    Obj.Output();
    Obj.Max();
}