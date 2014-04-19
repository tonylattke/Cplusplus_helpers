// reading a text file
#include <iostream>
#include <string>
#include <sstream>

#include <cstdio>
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */

using namespace std;

int main () {
	string str = "Hello world - have a nice day";
	string word;
	stringstream stream(str);
	while( getline(stream, word, ' ') )
		cout << word << endl;

	return 0;
}
