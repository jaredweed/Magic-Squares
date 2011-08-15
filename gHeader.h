/*	gHeader.h
	LAST REVISION: 08-14-2011

	Note that gHeader is the storage for all include headers
	And is the superceding header file for all subsequent 
	source files. The redundancy is checked using the #ifdefn
	statement found below. Note also below that there is only
	one variable that must be changed for the program to 
	work on different order squares. */

#ifndef GVARS_H
#define GVARS_H

#define AUTHOR "JARED WEED"
#define REVISION_DATE "AUGUST 15TH, 2011"
#define LATEST_VERSION "2.0"

/*	THIS IS THE ONLY DEFINITION YOU MUST CHANGE
	THE PROGRAM WILL WORK ONLY WITH THE ORDER
	DEFINED BELOW. IT MUST BE CHANGED PRIOR TO
	RESUMING ANALYSIS IN A GIVEN ORDER */

#define N 4

/*	END USER-EDIT DECLARATIONS */

#define NSQ N * N
#define M N * (N * N + 1) / 2

#endif

#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <cmath>
#include <string>
using namespace std;