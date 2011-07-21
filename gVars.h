#ifndef GVARS_H
#define GVARS_H

#define AUTHOR "Jared Weed"
#define REVISION_DATE "July 20th, 2011"
#define LATEST_VERSION "v1.1"

/*	THIS IS THE ONLY DEFINITION YOU MUST CHANGE
	THE PROGRAM WILL WORK ONLY WITH THE ORDER
	DEFINED BELOW. IT MUST BE CHANGED PRIOR TO
	RESUMING ANALYSIS IN A GIVEN ORDER */

#define N 4

/*	END USER EDITTED DECLARATIONS */




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