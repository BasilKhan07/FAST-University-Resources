#include<iostream>

using namespace std;

bool WordFinder(char **arr, int row, int col, string word, int p, int n1, int n2, int n3)
{
    if(n1<0 || n1>=row || n2<0 || n2>=col)
    {
        return false;
    }
    if(arr[n1][n2] == '-')
    {
        return false;
    }
    if(n2>=word.length() || arr[n1][n2]=='+')
    {
        return true;
    }
    else if(p==0)
    {
        return false;
    }
    char t;
    if(arr[n1][n2]==word[n2])
    {
        t = arr[n1][n2];
        arr[n1][n2] = '-';
        if(WordFinder(arr, row, col, word, p, n1, n2+1, n3+1))
        {
            p--;
            if(n3!=0)
            {
                return true;
            }
            else
            {
                cout << n1 << " " << n2 << "R" << endl;
            }
        }
        else if(WordFinder(arr, row, col, word, p, n1+1, n2, n3+1))
        {
            p--;
            if(n3!=0)
            {
                return true;
            }
            else
            {
                cout << n1 << " " << n2 << "D" << endl;
            }
        }
        else if(WordFinder(arr, row, col, word, p, n1-1, n2, n3+1))
        {
            p--;
            if(n3!=0)
            {
                return true;
            }
            else
            {
                cout << n2 << " " << n2 << "U" << endl;
            }
        }
        else if(WordFinder(arr, row, col, p, n1, n2-1, n3+1))
        {
            p--;
            if(n3!=0)
            {
                return true;
            }
            else
            {
                cout << n1 << " " << n2 << "L" << endl;
            }
        }
        arr[n1][n2] = t;
    }
    else if(n3==0)
    {
        if(WordFinder(arr, row, col, word, p, n1, n2+1, n3))
        {
            
        }
    }
}

int main()
{

}