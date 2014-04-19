#include <iostream>
#include <fstream>

using namespace std;

int main () {
	ofstream myfile;
	myfile.open ("example.txt");
	myfile << "Writing this to a file.\n";
	char* as = (char*) "line 2";
	myfile << as;
	myfile << std::endl << "line 3";
	myfile.close();
	return 0;
}