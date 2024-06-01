#include<iostream>

using namespace std;

string removeDup(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char str = s[0];
    string rem = removeDup(s.substr(1));
    if(str == rem[0])
    {
        return rem;
    }
    return str+rem;
}

int main()
{
    cout << removeDup("aaaaabbbbbccccddddeeefff");

}