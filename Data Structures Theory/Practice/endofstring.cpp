#include<iostream>

using namespace std;

string moveatend(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char str = s[0];
    string rem = moveatend(s.substr(1));
    if(str=='x')
    {
        return rem+str;
    }
    return str+rem;
}

int main()
{
    cout << moveatend("axxsfzxxazxx");
}