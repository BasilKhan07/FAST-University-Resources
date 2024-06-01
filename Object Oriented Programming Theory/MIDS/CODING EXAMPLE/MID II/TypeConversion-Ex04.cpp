//Explicit Type conversion


#include <iostream>

using namespace std;

int main() {
    // initializing a double variable
    double a = 3.56;
    cout << "a = " << a << endl;

    // C-style conversion from double to int
    int b = a;
    cout << "b   = " << b << endl;

    // function-style conversion from double to int
    int c = int(a);
    cout << "c   = " << c << endl;

    return 0;
}






