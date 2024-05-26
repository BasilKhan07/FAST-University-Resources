#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    string str;
    cout << "Enter String: ";
    getline(cin,str);
    cout << "Length of String: " << str.length();
    ofstream myFile;
    myFile.open("Task#01.txt");
    if(!myFile)
    {
        cout << "Error Openning File !" << endl;
    }
    myFile << str;
    myFile.close();
}