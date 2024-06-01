#include<iostream>

using namespace std;

int main()
{
    int n, max = 0, sum = 0, si, fi;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            for(int k=i; k<=j; k++)
            {  
                sum = sum + arr[k];
            }
            if(sum>max)
            {
                si = i;
                fi = j;
                max = sum;
            }
            sum = 0;
        }
    }
    for(int i=si; i<=fi; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << max;
}