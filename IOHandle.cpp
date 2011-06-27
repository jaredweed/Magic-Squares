#include "IOHandle.h"


IOHandle::IOHandle(void)
{
	terminate = false;
	cout << "MAGIC SQUARE CONSTRUCTOR PROGRAM \nversion " << VERSION << "\nwritten by " << AUTHOR << "\n\n\n\n\n";
}


IOHandle::~IOHandle(void)
{
}

bool IOHandle::exit(){
	return terminate;
}

void IOHandle::run(){
	cout << "Enter a command (or type 'help' for a list of commands): ";
	this->parseInput();
}

void IOHandle::listCommands(){
	cout << "\n\nSHOWING ALL COMMANDS\n(X is any integer)\n\n";
	cout << "quit" << endl;
	cout << "exit" << endl;
	cout << "generate order-4" << endl;
}

void IOHandle::parseInput(){
	string str;
	getline(cin, str);
	//cin.ignore(1000,'\n');
	for(int z = 0; z < str.length(); z++)
		str[z] = tolower(str[z]);

	//cases to check for handle
	//if a case is true but cannot be run, an exception will be thrown.
	if(str == "help")
		this->listCommands();

	if(str == "exit" || str == "quit")
		this->terminate = true;

	if(str == "generate order-4"){
		cout << "Generating 4x4 magic squares. . . \n\n";
		time (&start);
		obj.makeSquares4(obj.remaining, &m, 1);
		time (&end);
		int t = obj.count();
		cout << "Total squares parsed: " << t << "." << endl;
		cout << "Time to complete: " << difftime(end, start) << " seconds.\n\n";
	}
}
