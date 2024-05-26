#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream File1("Source.txt");
    ofstream File2("Destination.txt");
    string str;
    if(File1 && File2)
    {
        while (getline(File1, str))
        {
            File2 << str;
        }
        cout << "File Copies Successfully...." << endl;
    }
    else
    {
        cout << "Error Openning File !" << endl;
    }
    File1.close();
    File2.close();
}