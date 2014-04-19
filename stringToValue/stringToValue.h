#ifndef STRINGTOVALUE_H
#define STRINGTOVALUE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <cstdio>
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */

using namespace std;

char stringToChar(string v);
int stringToInt(string v);
float stringToFloat(string v);
double stringToDouble(string v);
bool stringToBool(string v);
char* stringToCharPointer(string v);
bool compareStrings(string a, string b);

#endif