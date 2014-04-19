#include "charToValue.h"

// Convert char pointer to Char
char charPointerToChar(char* v){
  return v[0];
}

// Convert char pointer to Integer
int charPointerToInt(char* v){
  char* valor = (char*) v;
  return atoi(valor);
}

// Convert char pointer to Float
float charPointerToFloat(char* v){
  char* valor = (char*) v;
  return atof(valor);
}

// Convert char pointer to Double
double charPointerToDouble(char* v){
  double d;
  char* valor = (char*) v;
  sscanf(valor,"%lf",&d);
  return d;
}

// Convert char pointer to Boolean
// Return true if v begins with t, otherwise retrun false
bool charPointerToBool(char* v){
  if (v[0] == 't'){
    return true;
  }
  return false;
}

// Testing functions
int main () {
  // Example char pointer to boolean
  char* v0 = (char*) "false";
  bool r0 = charPointerToBool(v0);
  std::cout << r0 << std::endl;

  // Example char pointer to char
  char* v1 = (char*) "a";
  char r1 = charPointerToChar(v1);
  std::cout << r1 << std::endl;

  // Example char pointer to integer
  char* v2 = (char*) "23";
  int r2 = charPointerToInt(v2);
  std::cout << r2 << std::endl;

  // Example char pointer to float
  char* v3 = (char*) "23.42";
  float r3 = charPointerToFloat(v3);
  std::cout << r3 << std::endl;

  // Example char pointer to double
  char* v4 = (char*) "4.8152342";
  double r4 = charPointerToDouble(v4);
  std::cout << r4 << std::endl; 

  return 0;
}