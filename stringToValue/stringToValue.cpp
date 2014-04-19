#include "stringToValue.h"

// Convert string to Char
char stringToChar(string v){
  return v[0];
}

// Convert string to integer
int stringToInt(string v){
  istringstream buffer(v);
  int valor;
  buffer >> valor;
  return valor;
}

// Convert string to float
float stringToFloat(string v){
  istringstream buffer(v);
  float valor;
  buffer >> valor;
  return valor;
}

// Convert string to double
double stringToDouble(string v){
  istringstream buffer(v);
  double valor;
  buffer >> valor;
  return valor;
}

// Convert string to boolean
bool stringToBool(string v){
  if (v.compare("true") == 0) {
    return true;
  }
  return false;
}

// Convert string to char pointer
char* stringToCharPointer(string v){
  return (char*) &v[0];
}

// Compare two strings and return a boolean
bool compareStrings(string a, string b){
  return (a.compare(b) == 0);
}

// Testing functions
int main () {
  // Example string to boolean
  string v0 = "false";
  bool r0 = stringToBool(v0);
  std::cout << r0 << std::endl;

  // Example string to char
  string v1 = "a";
  char r1 = stringToChar(v1);
  std::cout << r1 << std::endl;

  // Example string to integer
  string v2 = "23";
  int r2 = stringToInt(v2);
  std::cout << r2 << std::endl;

  // Example string to float
  string v3 = "23.42";
  float r3 = stringToFloat(v3);
  std::cout << r3 << std::endl;

  // Example string to double
  string v4 = "4.8152342";
  double r4 = stringToDouble(v4);
  std::cout << r4 << std::endl; 

  return 0;
}