#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

class DSA_2D{
    private:
        int rows;
        int cols;
        int **dynamicarray;
    public:
        DSA_2D()
        {
            rows = 0;
            cols = 0;
            dynamicarray = 0;
        }
        DSA_2D(int r, int c)
        {
            rows = r;
            cols = c;
            dynamicarray = new int *[rows];
            for(int i=0; i< rows; i++)
            {
                dynamicarray[i] = new int[cols];
            }
        }
        ~DSA_2D()
        {
            if(dynamicarray!=0)
            {
                for(int i=rows-1; i>=0; i--)
                {
                    if(dynamicarray[i]!=0)
                    {
                        delete dynamicarray[i];
                    }
                    dynamicarray[i] = 0;
                }
                delete dynamicarray;
            }
            dynamicarray = 0;
        }
        void FillArray()
        {
            int value;
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    cout << "Enter Values [" << i << "][" << j << "] : "; 
                    cin >> value;
                    dynamicarray[i][j] = value;
                }
            }
        }
        int &operator ()(int i, int j)
        {
            if(i<0 || i>rows-1 || cols<0 || cols>cols-1)
            {
                cout <<"Error: Boundary Error." << endl;
                exit(1);
            }
            return dynamicarray[i][j];
        } 
        DSA_2D(const DSA_2D &obj)
        {
            cout << endl << "Copy Constructor." << endl;
            rows = obj.rows;
            cols = obj.cols;
            dynamicarray = new int*[rows];
            for(int i=0; i<rows; i++)
            {
                dynamicarray[i] = new int[cols];
                memcpy(dynamicarray[i], obj.dynamicarray[i], sizeof(int)*cols);
            }
        }
        DSA_2D& operator = (const DSA_2D &obj)
        {
            cout << endl << "Assignment operator overloading" << endl;
            if(this == &obj)
            {
                return *this;
            }
            for(int i=rows-1; i>=0; i--)
            {
                delete dynamicarray[i];
                delete dynamicarray;
            }
            rows = obj.rows;
            cols = obj.cols;
            dynamicarray = new int *[rows];
            for(int i=0; i< rows; i++)
            {
                dynamicarray[i] = new int[cols];
                memcpy(dynamicarray[i], obj.dynamicarray[i], sizeof(int)*cols);
            }
            return *this;
        }
        DSA_2D& operator !=(const DSA_2D &obj)
        {
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    if(dynamicarray[i][j] != obj.dynamicarray[i][j])
                    {
                        cout << "NOT EQUAL" << endl;
                        break;
                    }
                }
                break;
            }
        }
};

int main()
{
    int rows, cols;
    cout << "Enter number of rows and column: " << endl;
    cin >> rows >> cols;
    DSA_2D obj1(rows, cols);
    obj1.FillArray();
    DSA_2D obj2 = obj1;
    DSA_2D obj3(2, 2);
    obj3.FillArray();
    DSA_2D obj4;
    obj4 = obj3;
    cout << obj1(1, 1) << endl;
    cout << obj3(2, 2) << endl;
    obj3!=obj1;
}