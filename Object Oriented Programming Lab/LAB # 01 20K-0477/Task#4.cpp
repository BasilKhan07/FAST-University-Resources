#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct playerDetails {
	string player_name;
	int num_home;
	int num_hits;
}arr[10];
void EnterData(struct playerDetails *ptr,int n);
void UpdateData(struct playerDetails *ptr,int n);
void SearchData(struct playerDetails *ptr,int n);
void DisplayContact(struct playerDetails *ptr,int n);
void menu(){
	int x;
	system("cls");
	cout << "BASEBALL"<<endl;
	cout << "1. Enter Player Data " <<endl << "2. Search for Player " <<endl << "3. Update Player Info"<<endl<<"4. Display Player Info"<<endl<<"5. Exit"<<endl;
	cin >> x;
	while(x>=0){
	switch(x){
		case 1:{
			EnterData(arr,10);
			break;
		}
		case 2:{
			SearchData(arr,10);
			break;
		}
		case 3:{
			UpdateData(arr,10);
			break;
		}
		case 4:{
			DisplayContact(arr,10);
			break;
		}
		default:{
			exit(1);
			break;
		}
	}
	
}
}
int main(){
	menu();
}
void EnterData(struct playerDetails *ptr, int n)
{
	system("cls");
	cout<<"ENTER PLAYER INFORMATION"<<endl<<endl;
	int i;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		cout << "Enter Player Name : ";
		getline(cin,ptr->player_name);
	    cout << endl;
		cout << "Enter Number Of Home Runs : ";
		cin >> ptr->num_home;
  	    fflush(stdin);
		cout << "Enter Number Of Hits : ";
		cin >> ptr->num_hits;
	    fflush(stdin);
      	ptr++;
		system("cls");
	}
	menu();
}
void SearchData(struct playerDetails *ptr, int n)
{
	system("cls");
	cout<<"SEARCH PLAYER INFORMATION"<<endl<<endl;
	string str;
	int i,x;
	cout << "Press 1 to Start"<<endl<<"Press 0 to Exit"<<endl;
	while(x>=0){
		cin >> x;
	switch(x){
		case 1:{
			fflush(stdin);
			cout << "Input Name : ";
	getline(cin,str);
	for(i=0;i<n;i++){
		if(ptr->player_name == str)
		{
			cout<<"Player Name : "<<ptr->player_name<<endl;
			cout<<"Number Of Home Runs : "<<ptr->num_home<<endl;
			cout<<"Number Of Total Hits : "<<ptr->num_hits<<endl;
	    }
	    ptr++;
	}
			break;
		}
		default:{
			menu();
			break;
		}
}
}
}
void UpdateData(struct playerDetails *ptr, int n)
{
	system("cls");
	cout<<"UPDATE PLAYER INFORMATION"<<endl<<endl;
	string str;
	int i,x;
	cout <<"Press 1 to Start"<<endl<< "Press 0 to exit"<<endl;
	while(x>=0){
		cin >> x;
	switch(x){
	case 1:{
		fflush(stdin);
		cout << "Input Name Of Contact to be Updated : ";
	getline(cin,str);
	for(i=0;i<n;i++){
		if(ptr->player_name == str){
			cout<<"Player Name : ";
			cin>>ptr->player_name;
			fflush(stdin);
			cout<<"Number Of Home Runs : ";
			cin>>ptr->num_home;
			fflush(stdin);
			cout<<"Number Of Total Hits : ";
			cin>>ptr->num_hits;
			fflush(stdin);
		}	
		ptr++;
	}
		break;
	}
	default:{
		menu();
		break;
	}
}
}
}
void DisplayContact(struct playerDetails *ptr, int n){
	 system("cls");
	 cout<<"DISPLAY PLAYER INFORMATION"<<endl<<endl;
		int i,x;
		cout <<"Press 1 To Start"<<endl<<"Press 0 to exit"<<endl;
		while(x>=0){
			cin >> x;
		switch(x){
			case 1:{
					for(i=0;i<n;i++){
			cout<<"Player Name : "<<ptr->player_name<<endl;
			cout<<"Number Of Home Runs : "<<ptr->num_home<<endl;
			cout<<"Number Of Total Hits : "<<ptr->num_hits<<endl;
			ptr++;
			cout<<endl<<endl;
		}
				break;
			}
	   default:{
	   	menu();
		break;
	   }
}
}
}
