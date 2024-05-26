#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream input_file;
	input_file.open(argv[1], ios::in);
	if(!input_file)
	{
		cout << "Input file doesnot exist." << endl;
		exit(0);
	}
	ofstream output_file;
	output_file.open(argv[2], ios::out);
	if(!output_file)
	{
		cout << "Output file doesnot exist." << endl;
		exit(1);
	}
	string ch;
	while(getline(input_file, ch)) 
	{
		output_file << ch;
		cout << "File Copied" << endl;
	}
	input_file.close();
	output_file.close();
}
