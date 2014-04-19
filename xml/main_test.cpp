#include <iostream>
#include <sstream>	

#include "tinyXML/tinyxml.h"

using namespace std;

int writeFileXML() {
	TiXmlDocument doc;  
	TiXmlElement* msg;

	// Add XML Version
 	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );  
	doc.LinkEndChild( decl );  
 
 	// Create tag with name MyApp
	TiXmlElement * root = new TiXmlElement( "MyApp" );  
	doc.LinkEndChild( root );  

	// Create comment
	TiXmlComment * comment = new TiXmlComment();
	comment->SetValue(" Comment on xml " );  
	root->LinkEndChild( comment );  
 
 	// Tag messages
	TiXmlElement * msgs = new TiXmlElement( "Messages" );  
	root->LinkEndChild( msgs );  
 
 	// Tag welcome with content
	msg = new TiXmlElement( "Welcome" );  
	msg->LinkEndChild( new TiXmlText( "Welcome to MyApp" ));  
	msgs->LinkEndChild( msg );  
 	
 	// Tag Test with content
	msg = new TiXmlElement( "Test" );  
	msg->LinkEndChild( new TiXmlText( "Thank you for using MyApp" ));  
	msgs->LinkEndChild( msg );  
 
 	// Tag Windows
	TiXmlElement * windows = new TiXmlElement( "Windows" );  
	root->LinkEndChild( windows );  

	// Tag window with attributes
	TiXmlElement * window;
	window = new TiXmlElement( "Window" );  
	windows->LinkEndChild( window );  
	window->SetAttribute("name", "MainFrame");
	window->SetAttribute("x", 5);
	window->SetAttribute("y", 15);
	window->SetAttribute("w", 400);
	window->SetAttribute("h", 250);

	// Tag Connection with attributes 
	TiXmlElement * cxn = new TiXmlElement( "Connection" );  
	root->LinkEndChild( cxn );  
	cxn->SetAttribute("ip", "192.168.0.1");
	cxn->SetDoubleAttribute("timeout", 123.123);
	
	// Writing the file
	doc.SaveFile( "test_write.xml" );  

	return 0;
}

int readFileXML(char *nombre) {
	TiXmlDocument XMLdoc(nombre);
	bool loadOkay = XMLdoc.LoadFile();
	
	if (loadOkay) {
		cout << nombre <<" loaded" << endl;
		TiXmlElement *pRoot, *pParm, *pProcess, *pApp;
		pRoot = XMLdoc.FirstChildElement( "Configuration" );
		if ( pRoot ) {
			// Parse parameters
			pParm = pRoot->FirstChildElement("Parameter");
			while ( pParm ) {
				cout << "Parameter: name= '" << pParm->Attribute("name") << "', value='" << pParm->Attribute("value") << "'" << endl;
				pParm = pParm->NextSiblingElement( "Parameter" );
			}
			cout << endl;

			// Parse Process 
			pProcess = pRoot->FirstChildElement("Process" );
			while ( pProcess ) {
				cout <<"Process: " << pProcess->Attribute("Name" ) << endl;
				pApp = pProcess->FirstChildElement("App" );
				while ( pApp )
				{
					cout << "..App: ID=" << pApp->Attribute("ID") << ", name=" << pApp->Attribute("Name") << endl;
					// ***************************************************
					// * TODO: Put code in to handle the App details
					// ***************************************************
					pApp = pApp->NextSiblingElement("App");
				}
				pProcess = pProcess->NextSiblingElement("Process");
			}
		} else {
			cout << "Cannot find 'Configuration' node" << endl;
		}
	}

	return 0;
}

int main() {
	writeFileXML();
	readFileXML((char*) "test.xml");

	return 0;
}