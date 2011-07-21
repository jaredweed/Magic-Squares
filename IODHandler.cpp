#include "IODHandler.h"


IODHandler::IODHandler(void) : terminate(false){
	cout << "MAGIC SQUARE CONSTRUCTION PROGRAM \nbuild " << LATEST_VERSION << "\nrevised " << REVISION_DATE << "\n## " << AUTHOR << "\n\n\n\n\n";
}


IODHandler::~IODHandler(void){
}


bool IODHandler::exit(){
	return terminate; }


void IODHandler::listCommands(){
	cout << "\nCOMMAND LIST" << endl;
	cout << "quit" << endl;
	cout << "exit" << endl;
	cout << "generate squares" << endl;
	cout << "output square XXX"; }


void IODHandler::parseInput(){
	string str;
	getline(cin, str);
	for(unsigned int z = 0; z < str.length(); z++)
		str[z] = tolower(str[z]);

	cout << endl;
	//cases to check for handle
	//if a case is true but cannot be run, an exception will be thrown.

	if(str == "help")
		listCommands();

	else if(str == "exit" || str == "quit")
		terminate = true;

	else if(str == "generate squares"){
		cout << "Generating Order-" << N << " magic squares. . . \n\n";
		mObj.createSquares();
		cout << mObj.magics.size() << " squares created. ";
	}

	else if(str.find("output square ") != -1){
		if(mObj.magics.size() == 0)
			throwException(2);
		else{
			unsigned int a = atoi(str.substr(14).c_str());
			if(a <= mObj.magics.size() && a > 0)
				mObj.magics[a].print();
			else
				throwException(3);
		}
	}

	else if(str.find("output squares ") != -1){
		int pos = str.find("to") - 1;
		unsigned int a = atoi(str.substr(15, pos-2).c_str()) - 1;
		unsigned int b = atoi(str.substr(pos+3).c_str()) - 1;
		while(a <= b){
			mObj.magics[a].print();
			cout << endl;
			a++;
		}
	}

	else if(str == "simple sort squares"){
		cout << "Simple sorting squares. . . \n\n";
		mObj.simpleSort();
		cout << "Sorting complete.";
	}

	else if(str == "sort squares by enumeration"){
		cout << "Sorting squares by lowest-to-highest method. . . \n\n";
		mObj.sortByEnumeration();
	}

	else if(str == "square count"){
		cout << mObj.magics.size();
	}

	else
		throwException(-1);

	cout << endl << endl; }


void IODHandler::run(){
	cout << "Enter command (or type 'help' for command list): ";
	parseInput(); }


void IODHandler::throwException(int i){
	switch(i){
	case 0:
		break;
	case 1:
		break;
	case 2:
		cout << "Magic Squares have not been initialized.";
		break;
	case 3:
		cout << "Out of bounds request.";
		break;
	default:
		cout << "An unknown error has occured.";
		break;
	}
	return; }