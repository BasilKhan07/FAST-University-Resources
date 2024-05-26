#include<iostream>
#include<iomanip>

using namespace std;

struct ticket_details{
	char movie_name[20];
	int adult_ticket;
	int child_ticket;
	int total_tickets;
	int num_childtickets;
	int num_adulttickets;
	float gross;
	float per;
	float per_gross;
	float net_sale;
};
int main()
{
	ticket_details d;
	cout << "Input Child Ticket Price: ";
	cin >> d.child_ticket;
	cout << "Input Adult Price: ";
	cin >> d.adult_ticket;
	cout << "Input Number of Child Tickets: ";
	cin >> d.num_childtickets;
	cout << "Input Number Of Adult Tickets: ";
	cin >> d.num_adulttickets;
	d.total_tickets = d.num_adulttickets + d.num_childtickets;
	d.gross = (d.num_adulttickets * d.adult_ticket) + (d.num_childtickets * d.child_ticket);
	cout << "Enter Movie Name: ";
	cin >> d.movie_name;
	cout << "Enter Percentage of donation: " << endl;
	cin >> d.per;
	d.per_gross = d.gross * (0.1);
	d.net_sale = d.gross - d.per_gross;
	system("cls");
	cout<<left<<setw(30)<<setfill('.')<<"MOVIE NAME";
	cout<<right<<setw(4)<<setfill(' ')<<d.movie_name<<"\n";
	cout<<left<<setw(30)<<setfill('.')<<"NUMBER OF TICKET SOLD";
	cout<<right<<setw(4)<<setfill(' ')<<d.total_tickets<<"\n";
	cout<<left<<setw(30)<<setfill('.')<<"GROSS AMOUNT";
	cout<<right<<setw(4)<<setfill(' ')<<"$"<<d.gross<<"\n";
	cout<<left<<setw(30)<<setfill('.')<<"PERCENTAGE OF GROSS AMOUNT";
	cout<<right<<setw(4)<<setfill(' ')<<d.per<<"%"<<"\n";
	cout<<left<<setw(30)<<setfill('.')<<"AMOUNT DONATED";
	cout<<right<<setw(4)<<setfill(' ')<<"$"<<d.per_gross<<"\n";
	cout<<left<<setw(30)<<setfill('.')<<"NET SALE";
	cout<<right<<setw(4)<<setfill(' ')<<"$"<<d.net_sale<<"\n";
}
