/*	main.cpp 
	LAST REVISION: 07-04-2011

	main.cpp functionality:

		entry point for command-line program
		creates an instance of an IODHandler and passes
		priority to the object. IODHandler's member function
		"exit" will allow for reiteration of operation
		through MAIN until the user requests termination,
		at which point MAIN will return and quit. 

	Below is the include directive to the IODHandler class */

#include "IODHandler.h"

/*	No other directive is required. All other global definitions
	and directives are found in the father header files, pointing
	to gVars.h */

void main(){
	IODHandler handle;
	while(handle.exit() == false){
		handle.run();
	}
	return; }