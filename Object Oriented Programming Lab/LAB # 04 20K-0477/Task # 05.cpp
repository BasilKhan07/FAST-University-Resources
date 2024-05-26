#include<iostream>
#include<iomanip>
#include<conio.h>

static int k=0;
double total=0;

using namespace std;

class CoffeeShop{
	private:
		string nameofshop;
		string itemname[4];
		string itemtype[4];
		int itemprice[4];
		int order[];
	
	public:
		CoffeeShop(){
			nameofshop="FAST COFFEE";
			itemname[0]="Cuppucino";
			itemtype[0]="Drink";
			itemprice[0]=500;
			itemname[1]="CheeseTwister";
			itemtype[1]="Food";
			itemprice[1]=700;
			itemname[2]="Expresso";
			itemtype[2]="Drink";
			itemprice[2]=300;
			itemname[3]="ClubSandwich";
			itemtype[3]="Food";
			itemprice[3]=600;	
		}
		void title(){
			cout << " ========  FAST COFFEE SHOP ======== " << endl << endl;
		}
		void addOrder(){
			int no, i, j;
			string iname;
			cout << "Enter Number Of Orders: ";
			cin >> no;
			for(i=0;i<no;i++)
			{
				cout << endl << "Enter Item name: ";
				cin >> iname;
				for(j=0;j<4;j++)
				{
					if(itemname[j]==iname)
					{
						order[k]=j;
						k++;
						total += itemprice[j];
						break;
					}
				}
				if(j==4)
				{
					cout << "This Item is currently unavailable.";
				}
			}
			cout << endl << "Thank You!" << endl;
			cout << "Press any key to continue.";
			getch();
			system("cls");
		}
		void fullfillorder(){
			int c;
			cout << " ------------ Wait ------------" << endl << endl;
			for(int i=0;i<k;i++)
			{
				if(order[i]!='\0')
				{
					c++;
				}
				if(c>0)
				{
					cout << "The {item} is ready" <<endl;
				}
				else
				{
					cout << "All orders have been fulfilled!" << endl;
				}
		}
	}
		void listorders(int k){
			cout << endl;
			cout << " --------- Order List ----------" << endl << endl;
			for(int i=0;i<k;i++)
			{
				cout << i+1 << ". " << itemname[order[i]] << endl;
			}
		}
		void dueAmount(){
			cout << endl;
			cout << " ----- Amount Due to pay ------- " << endl << endl;
			cout << "Total Bill: " << total << endl;
		}
		void cheapestitem(){
			int sasta=itemprice[0];
			string cheapest;
			cout << endl;
			cout << " ------ Cheapest Item ---------- " << endl << endl;
			for(int i=0;i<4;i++)
			{
				if(itemprice[i]<sasta)
				{
					cheapest=itemname[i];
				}
			}
			cout << "-> " << cheapest <<endl;
		}
		void drinksonly(){
			static int j=1;
			cout << endl;
			cout << " --------  Drinks -------- " << endl << endl;
			for(int i=0;i<4;i++)
			{
				if(itemtype[i]=="Drink")
				{
					cout << j << ". " << itemname[i] << endl;
					j++;
				}
			}
		}
		void foodonly(){
			static int j=1;
			cout << endl;
			cout << " --------  Foods --------- " << endl << endl;
			for(int i=0;i<4;i++)
			{
				if(itemtype[i]=="Food")
				{
					cout << j << ". " << itemname[i] << endl;
					j++;
				}
			}
		}
};

int main()
{
	CoffeeShop c;
	c.title();
	c.addOrder();
	c.title();
	c.fullfillorder();
	c.listorders(k);
	c.dueAmount();
	c.cheapestitem();
	c.drinksonly();
	c.foodonly();
	return 0;
}
