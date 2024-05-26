#include<iostream>

using namespace std;

class Store{
    protected:
    int totalBill;
    public:
    virtual void Total_Bill()=0;
};

class ImtiazStore : public Store{
    protected:
    float percentDiscount = 0.07;
    public:
    ImtiazStore(int x)
    {
        totalBill = x;
    }
    void Total_Bill()
    {
        cout <<" -------- IMTIAZ STORE --------- " << endl;
        cout << "Total Bill: " << totalBill << endl;
        cout << "Discount: " << percentDiscount * totalBill << endl;
        cout << "Total Bill After 7% Discount: " << totalBill - (percentDiscount * totalBill) << endl;
    }
};

class BinHashimStore : public Store{
    protected:
    float percentDiscount = 0.05;
    public:
    BinHashimStore(int x)
    {
        totalBill = x;
    }
    void Total_Bill()
    {
        cout << " -------- BIN HASHIM STORE -------- " << endl;
        cout << "Total Bill: " << totalBill << endl;
        cout << "Discount: " << percentDiscount * totalBill << endl;
        cout << "Total Bill After 5% Discount: " << totalBill - (percentDiscount * totalBill) << endl;
    }
};

int main()
{
    ImtiazStore i(5000);
    BinHashimStore b(6000);
    i.Total_Bill();
    cout << endl << endl;
    b.Total_Bill();
}