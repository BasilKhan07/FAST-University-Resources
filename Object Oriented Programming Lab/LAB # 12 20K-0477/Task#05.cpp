#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream myFile1;
    myFile1.open("STORY.TXT", ios::out);
    myFile1 << "The rose is red." << endl;
    myFile1 << "A girl is playing there." << endl;
    myFile1 << "There is a playground." << endl;
    myFile1 << "An aeroplane is in the sky." << endl;
    myFile1 << "Numbers are not allowed in the password." << endl;
    myFile1 << "A group of People." << endl;
    myFile1 << "My name is Basil." << endl;
    myFile1.close();
    ifstream myFile2;
    myFile2.open("STORY.TXT", ios::in);
    char str[100];
    int count=0, count1=0;
    while(!myFile2.eof())
    {
        myFile2.getline(str, 80);
        if(str[0] != 'A')
        {
            count++;
        }
    }
    cout << "The number of lines not starting with 'A' are: " << count-1 << endl;
    myFile2.close();
}