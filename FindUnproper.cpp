#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	vector<string> unmarked;
	for(int i = 1; i < argc; i++)
	{
		ifstream infile(argv[i]);
		string input;
		string name;
		int marking;
		getline(infile, input);
		getline(infile, input);
		while(infile>>name)
		{
			infile>>marking;
			if(!marking && find(unmarked.begin(), unmarked.end(), name) == unmarked.end())
			{
				unmarked.push_back(name);
			}
			while(getline(infile, input) && input != ""){}
		}
	}
	
	ofstream outfile("unproper.txt");
	for(unsigned int i = 0; i < unmarked.size(); i++)
	{
		outfile<<unmarked.at(i)<<endl;
	}
	return 0;
}
