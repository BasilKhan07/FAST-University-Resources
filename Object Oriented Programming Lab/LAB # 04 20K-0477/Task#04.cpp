#include<iostream>

using namespace std;

class BookStore{
	private:
		string author[3];
		string title[3];
		int price[3];
		string publisher[3];
		int stockposition[3];
	
	public:
		BookStore(){
			author[0] = "ABC author";
			title[0] = "ABC title";
			price[0] = 500;
			publisher[0] = "ABC";
			stockposition[0] = 100;
			author[1] = " DEF author";
			title[1] = "DEF title";
			price[1] = 700;
			publisher[1] = "DEF";
			stockposition[1] = 120;
			author[2] = "GHI author";
			title[2] = "GHI title";
			price[2] = 400;
			publisher[2] = "GHI";
			stockposition[2] = 160;	
		}
		void searchbook(string book){
			int i, no, total;
			for(i=0;i<3;i++)
			{
				if(book==title[i])
				{
					cout << "Book Available." << endl;
					cout << "Title: " << title[i] << endl;
					cout << "Author: " << author[i] << endl;
					cout << "Price: " << price[i] << endl;
					cout << "Publisher: " << publisher[i] << endl;
					cout << "Stock Position: " << stockposition[i] << endl;
					cout << "Enter Quantity of Books: ";
					cin >> no;
					if(no>stockposition[i])
					{
						cout << "Requested copies not in stock." << endl;
						break;
					}
					else
					{
						stockposition[i] -= no;
						total = price[i] * no;
						cout << endl << "Bill: " << total << endl;
						break;
					}
				}
				else
				{
					cout << "Book Not Available." << endl;
				}
			}
		}
};

int main()
{
	BookStore B;
	string book;
	cout << "Enter Name of Book: ";
	getline(cin,book);
	B.searchbook(book);
}
