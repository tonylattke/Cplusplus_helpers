#include <iostream>
#include <fstream>

using namespace std;

int main () {
  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open()) {
    while ( myfile.good() ) {
      getline (myfile,line);
			char* prueba = (char*) &line[0];
      cout << prueba << endl;
    }
    myfile.close();
  } else {
    cout << "Unable to open file"; 
  }

  return 0;
}
