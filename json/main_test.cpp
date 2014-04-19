#include "Jzon/Jzon.h"

class testClass {
	public:
		int data;
		testClass(int v);
		Jzon::Object serialize();
};

testClass::testClass(int v){
	data = v;
}

Jzon::Object testClass::serialize(){
	Jzon::Object root;
	root.Add("name", "value");
	return root;
}

// Generating Json files
int main(){
	// file1.json
	Jzon::Object root;
	root.Add("name", "value");
	root.Add("number", 20);
	root.Add("anothernumber", 15.3);
	root.Add("stuff", true);

	Jzon::Array listOfStuff;
	listOfStuff.Add("json");
	listOfStuff.Add("more stuff");
	listOfStuff.Add(Jzon::null);
	listOfStuff.Add(false);

	Jzon::Object subElem;
	subElem.Add("name", "value");
	subElem.Add("number", 20);

	Jzon::Object elem;
	elem.Add("name", subElem);
	elem.Add("number", 20);

	listOfStuff.Add(elem);

	root.Add("listOfStuff", listOfStuff);

	Jzon::FileWriter::WriteFile("file1.json", root, Jzon::StandardFormat);

	// file2.json
	testClass* aux = new testClass(1);
	Jzon::Object serialized = aux->serialize();
	Jzon::FileWriter::WriteFile("file2.json", serialized, Jzon::StandardFormat);

	return 0;
}
