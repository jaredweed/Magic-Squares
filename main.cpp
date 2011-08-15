#include "STDMatrix.h"
#include "gHeader.h"


void showCommands();
void runProg();
void throwException(int e);
void generateOrder4(int (&B)[NSQ], STDMatrix &A, int n);
void push(STDMatrix &A);
void permuteUT();
void findUnique_Comparison();
void classify4();
void classList();
void sortLinearCompare();
void findUnique_Permute();

vector<STDMatrix> magics;


int main(){

/*					*/
/* BEGIN INITIALIZE */
/*					*/
	bool loop = true;
	cout << "MAGIC SQUARE CONSTRUCTION PROGRAM \nBUILD VERSION "
		 << LATEST_VERSION
		 << "\nLAST REVISED "
		 << REVISION_DATE
		 << "\nCOPYRIGHT "
		 << AUTHOR
		 << "\n\n\n";
/* END INITIALIZE */


	while(loop){
		cout << "Enter command (or type 'help' for command list): ";
		string str;
		getline(cin, str);
		for(unsigned int z = 0; z < str.length(); z++)
			str[z] = tolower(str[z]);
		cout << endl;


/*						  */
/* BEGIN CHECK USER INPUT */
/*						  */
		if(str == "help")
			showCommands();

		else if(str == "exit" || str == "quit")
			loop = false;

		else if(str == "generate squares"){
			int remaining[NSQ];
			STDMatrix builder;
			for(int i = 0; i < NSQ; i++)
				remaining[i] = 0;
			cout << "Generating Order-" << N << " squares. . . \n\n";
			generateOrder4(remaining, builder, 1);
			cout << "All squares built.";
		}

		else if(str.find("output square ") != -1){
			if(magics.size() == 0)
				throwException(1);
			else{
				unsigned int a = atoi(str.substr(14).c_str()) - 1;
				if(a <= magics.size() - 1 && a >= 0)
					magics[a].print();
				else
					throwException(2);
			}
		}

		else if(str.find("output squares ") != -1){
			if(magics.size() == 0)
				throwException(1);
			else{
				int pos = str.find("to") - 1;
				unsigned int a = atoi(str.substr(15, pos-2).c_str()) - 1;
				unsigned int b = atoi(str.substr(pos+3).c_str()) - 1;
				while(a <= b){
					if(a <= magics.size() - 1 && a >= 0){
						magics[a].print();
						if(a != b)
							cout << "\n\n\n";
						a++;
					}
					else{
						throwException(2);
						break;
					}
				}
			}
		}

		else if(str.find("output type ") != -1){
			if(magics.size() == 0)
				throwException(1);
			else{
				unsigned int a = atoi(str.substr(12).c_str());
				for(unsigned int i = 0; i < magics.size(); i++){
					if(magics[i].getType() == a){
						magics[i].print();
						cout << "\n\n\n";
					}
				}
			}
		}

		else if(str == "permute upper triangular"){
			if(magics.size() == 0)
				throwException(1);
			else{
				cout << "Permuting squares as upper triangular. . .\n\n";
				permuteUT();
				cout << "Permutation complete.";
			}
		}

		else if(str == "check square equality"){
			if(magics.size() == 0)
				throwException(1);
			else{
				cout << "Finding unique squares after tests for equality. . .\n\n";
				findUnique_Comparison();
				cout << "Unique squares found.";
			}
		}

		else if(str == "classify squares"){
			if(magics.size() == 0)
				throwException(1);
			else{
				cout << "Classifying squares as Dudeney Types. . .\n\n";
				classify4();
				cout << "Classification complete." << endl << "Remember to reclassify squares after any operation!";
			}
		}

		else if(str == "sort squares"){
			if(magics.size() == 0)
				throwException(1);
			else{
				cout << "Sorting squares from least to greatest. . .\n\n";
				sortLinearCompare();
				cout << "Sorting complete.";
			}
		}

		else if(str == "find unique squares"){
			if(magics.size() == 0)
				throwException(1);
			else{
				cout << "Finding unique squares after tests for permutations. . .\n\n";
				findUnique_Permute();
				cout << "\nUnique squares found.";
			}
		}

		else if(str == "analysis"){
			if(magics.size() == 0){
				cout << "There are currently 0 squares created." << endl
					 << "Generate squares for further details.";
			}
			else{
				cout << "There are currently " << magics.size() << " squares created." << endl;
				if(magics[0].getType() == -1)
					cout << "Classify squares for further details.";
				else
					classList();
			}
		}

		else if(str == "run program")
			runProg();

		else
			cout << "Unknown Command '" << str << "'";
/* END CHECK USER INPUT */


		cout << endl << endl;
	}
	return 0;
}


void showCommands(){
	cout << "COMMANDS LIST" << endl << endl
		 << "run program" << endl
		 << "generate squares" << endl
		 << "output square ###" << endl
		 << "output squares ### to ###" << endl
		 << "output type ###" << endl
		 << "permute upper triangular" << endl
		 << "sort squares" << endl
		 << "classify squares" << endl
		 << "check square equality" << endl
		 << "find unique squares" << endl
		 << "quit/exit" << endl;
}

/*	THIS FEATURE WILL RUN ALL FUNCTIONS AT ONCE INSTEAD
	OF HAVING TO TYPE EACH ONE IN INDIVIDUALLY */

void runProg(){
	int remaining[NSQ];
	STDMatrix builder;
	for(int i = 0; i < NSQ; i++)
		remaining[i] = 0;
	cout << "Generating Order-" << N << " squares. . . \n\n";
	generateOrder4(remaining, builder, 1);
	cout << "All squares built.";

	cout << endl << endl;

	cout << "Permuting squares as upper triangular. . .\n\n";
	permuteUT();
	cout << "Permutation complete.";

	cout << endl << endl;

	cout << "Finding unique squares after tests for equality. . .\n\n";
	findUnique_Comparison();
	cout << "Unique squares found.";

	cout << endl << endl;

	cout << "Classifying squares as Dudeney Types. . .\n\n";
	classify4();
	cout << "Classification complete.";

	cout << endl << endl;

	cout << "Finding unique squares after tests for permutations. . .\n\n";
	findUnique_Permute();
	cout << "\nUnique squares found.";

	cout << endl << endl;

	cout << "Sorting squares from least to greatest. . .\n\n";
	sortLinearCompare();
	cout << "Sorting complete.";

	cout << endl << endl;

	cout << "Classifying squares as Dudeney Types. . .\n\n";
	classify4();
	cout << "Classification complete.";

	cout << endl << endl;

	cout << "There are currently " << magics.size() << " squares created." << endl;
	classList();
}


void throwException(int e){
	cout << "ERROR: ";
	switch(e){
		case 1:
			cout << "Magic Squares must be generated prior to operations.";
			break;

		case 2:
			cout << "Referenced square out of scope.";
			break;

		default:
			cout << "Unknown error occured.";
			break;
	}
}


void generateOrder4(int (&B)[NSQ], STDMatrix &A, int n){
	int rSum, rSum2, rSum3;

	for(int i = 1; i <= NSQ; i++){
		if(B[i-1] == 0){
			switch(n){
				case 1:
					B[i-1] = 1;
					A.c[0][0] = i;
					generateOrder4(B, A, 2);
					break;

				case 2:
					B[i-1] = 1;
					A.c[0][1] = i;
					generateOrder4(B, A, 3);
					break;

				case 3:
					rSum = M - A.c[0][0] - A.c[0][1] - i;
					if(rSum > 16 || B[rSum-1] == 1)
						continue;
					B[i-1] = 1;
					A.c[0][2] = i;
					generateOrder4(B, A, 4);
					break;
				
				case 4:
					rSum = M - A.c[0][0] - A.c[0][1] - A.c[0][2] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[0][3] = i;
						generateOrder4(B, A, 5);
					}
					else
						continue;
					break;

				case 5:
					B[i-1] = 1;
					A.c[1][0] = i;
					generateOrder4(B, A, 9);
					break;

				case 9:
					rSum = M - A.c[0][0] - A.c[1][0] - i;
					if(rSum > 16 || B[rSum-1] == 1)
						continue;
					B[i-1] = 1;
					A.c[2][0] = i;
					generateOrder4(B, A, 13);
					break;

				case 13:
					rSum = M - A.c[0][0] - A.c[1][0] - A.c[2][0] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[3][0] = i;
						generateOrder4(B, A, 6);
					}
					else
						continue;
					break;
				
				case 6:
					B[i-1] = 1;
					A.c[1][1] = i;
					generateOrder4(B, A, 7);
					break;

				
				case 7:
					rSum = M - A.c[1][0] - A.c[1][1] - i;
					rSum2 = M - A.c[0][3] - A.c[3][0] - i;
					if(rSum > 16 || rSum2 > 16 || B[rSum-1] == 1 || B[rSum2-1] == 1)
						continue;
					B[i-1] = 1;
					A.c[1][2] = i;
					generateOrder4(B, A, 8);
					break;

				case 8:
					rSum = M - A.c[1][0] - A.c[1][1] - A.c[1][2] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[1][3] = i;
						generateOrder4(B, A, 10);
					}
					else
						continue;
					break;

				case 10:
					rSum = M - A.c[0][3] - A.c[1][2] - A.c[3][0] - i;
					rSum2 = M - A.c[0][1] - A.c[1][1] - i;
					if(rSum2 > 16 || B[rSum2-1] == 1)
						continue;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[2][1] = i;
						generateOrder4(B, A, 14);
					}
					else
						continue;
					break;
				
				case 14:
					rSum = M - A.c[0][1] - A.c[1][1] - A.c[2][1] - i;
					if(rSum == 0 && B[rSum-1] != 1)
						B[i-1] = 1;
						A.c[3][1] = i;
						generateOrder4(B, A, 11);
						break;

				case 11:
					rSum = M - A.c[0][2] - A.c[1][2] - i;
					rSum2 = M - A.c[2][0] - A.c[2][1] - i;
					rSum3 = M - A.c[0][0] - A.c[1][1] - i;
					if(rSum > 16 || rSum2 > 16 || rSum3 > 16 || B[rSum-1] == 1 || B[rSum2-1] == 1 || B[rSum3-1] == 1)
						continue;
					B[i-1] = 1;
					A.c[2][2] = i;
					generateOrder4(B, A, 12);
					break;

				case 12:
					rSum = M - A.c[2][0] - A.c[2][1] - A.c[2][2] - i;
					rSum2 = M - A.c[0][3] - A.c[1][3] - i;
					if(rSum2 > 16 || B[rSum2-1] == 1)
						continue;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[2][3] = i;
						generateOrder4(B, A, 15);
					}
					else
						continue;
					break;

				case 15:
					rSum = M - A.c[0][2] - A.c[1][2] - A.c[2][2] - i;
					rSum2 = M - A.c[3][0] - A.c[3][1] - i;
					if(rSum2 > 16 || B[rSum2-1] == 1)
						continue;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[3][2] = i;
						generateOrder4(B, A, 16);
					}
					else
						continue;
					break;
				
				case 16:
					rSum = M - A.c[0][0] - A.c[1][1] - A.c[2][2] - i;
					rSum2 = M - A.c[0][3] - A.c[1][3] - A.c[2][3] - i;
					rSum3 = M - A.c[3][0] - A.c[3][1] - A.c[3][2] - i;
					if(rSum == 0 && rSum2 == 0 && rSum3 == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[3][3] = i;
						push(A);
					}
					break;
			}
			B[i-1] = 0;
		}
	}
	return;
}


void push(STDMatrix &A){
	STDMatrix temp;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			temp.c[i][j] = A.c[i][j];
		}
	}
	magics.push_back(temp);
}


void permuteUT(){
	int loc_i, loc_j;
	bool found;
	for(unsigned int x = 0; x < magics.size(); x++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(magics[x].c[i][j] == 1){
					loc_i = i;
					loc_j = j;
					found = true;
					break;
				}
			}
			if(found) break;
		}
		if(loc_i == 0){
			if(loc_j == 2 || loc_j == 3)
				magics[x].Ap(4321);
		}
		if(loc_i == 1){
			if(loc_j == 0)
				magics[x].transpose();
			if(loc_j == 1){
				magics[x].pAp(2143);
			}
			if(loc_j == 2){
				magics[x].pA(2143);
				magics[x].Ap(3412);
			}
			if(loc_j == 3){
				magics[x].transpose();
				magics[x].pA(4321);
			}
		}
		if(loc_i == 2){
			if(loc_j == 0){
				magics[x].transpose();
				magics[x].Ap(4321);
			}
			if(loc_j == 1){
				magics[x].pA(3412);
				magics[x].Ap(2143);
			}
			if(loc_j == 2){
				magics[x].pAp(3412);
			}
			if(loc_j == 3){
				magics[x].transpose();
				magics[x].pAp(4321);
			}
		}
		if(loc_i == 3){
			if(loc_j == 0 || loc_j == 1)
				magics[x].pA(4321);
			if(loc_j == 2 || loc_j == 3){
				magics[x].pAp(4321);
			}
		}
		found = false;
	}
}


void findUnique_Comparison(){
	vector<STDMatrix> unique;
	bool ISunique;
	for(unsigned int i = 0; i < magics.size(); i++){
		ISunique = true;
		for(unsigned int j = 0; j < unique.size(); j++){
			if(magics[i] == unique[j]){
				ISunique = false;
				break;
			}
		}
		if(ISunique)
		unique.push_back(magics[i]);
	}
	magics.clear();
	for(unsigned int z = 0; z < unique.size(); z++)
		magics.push_back(unique[z]);
}


void classify4(){
	for(unsigned int i = 0; i < magics.size(); i++){
		//type 1
		if(magics[i].c[0][0] + magics[i].c[2][2] == 17)
			magics[i].setType(1);

		//type 2
		else if(magics[i].c[0][0] + magics[i].c[1][1] == 17)
			magics[i].setType(2);

		//type 3
		else if(magics[i].c[0][0] + magics[i].c[3][3] == 17)
			magics[i].setType(3);

		//type 4
		else if((magics[i].c[0][0] + magics[i].c[1][0] == 17 && magics[i].c[0][1] + magics[i].c[1][1] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][1] == 17 && magics[i].c[1][0] + magics[i].c[1][1] == 17))
			magics[i].setType(4);

		//type 5
		else if((magics[i].c[0][0] + magics[i].c[2][0] == 17 && magics[i].c[0][2] + magics[i].c[2][2] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][2] == 17 && magics[i].c[2][0] + magics[i].c[2][2] == 17))
			magics[i].setType(5);

		//type 6
		else if((magics[i].c[0][0] + magics[i].c[3][0] == 17 && magics[i].c[0][1] + magics[i].c[3][1] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][3] == 17 && magics[i].c[1][0] + magics[i].c[1][3] == 17))
			magics[i].setType(6);

		//type 7
		else if((magics[i].c[0][0] + magics[i].c[3][0] == 17 && magics[i].c[0][1] + magics[i].c[1][1] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][3] == 17 && magics[i].c[1][0] + magics[i].c[1][1] == 17))
			magics[i].setType(7);

		//type 8
		else if((magics[i].c[0][0] + magics[i].c[2][0] == 17 && magics[i].c[0][1] + magics[i].c[3][1] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][2] == 17 && magics[i].c[1][0] + magics[i].c[1][3] == 17))
			magics[i].setType(8);

		//type 9
		else if((magics[i].c[0][0] + magics[i].c[1][0] == 17 && magics[i].c[0][1] + magics[i].c[3][1] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][1] == 17 && magics[i].c[1][0] + magics[i].c[1][3] == 17))
			magics[i].setType(9);

		//type 10
		else if((magics[i].c[0][0] + magics[i].c[3][0] == 17 && magics[i].c[0][1] + magics[i].c[2][1] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][3] == 17 && magics[i].c[1][0] + magics[i].c[1][2] == 17))
			magics[i].setType(10);

		//type 11
		else if((magics[i].c[0][0] + magics[i].c[1][0] == 17 && magics[i].c[0][2] + magics[i].c[1][2] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][1] == 17 && magics[i].c[2][0] + magics[i].c[2][1] == 17) ||
			(magics[i].c[0][1] + magics[i].c[1][1] == 17 && magics[i].c[0][3] + magics[i].c[1][3] == 17) ||
			(magics[i].c[1][0] + magics[i].c[1][1] == 17 && magics[i].c[3][0] + magics[i].c[3][1] == 17))
			magics[i].setType(11);

		//type 12
		else if((magics[i].c[0][0] + magics[i].c[2][0] == 17 && magics[i].c[0][1] + magics[i].c[2][1] == 17) ||
			(magics[i].c[0][0] + magics[i].c[0][2] == 17 && magics[i].c[1][0] + magics[i].c[1][2] == 17) ||
			(magics[i].c[0][2] + magics[i].c[2][2] == 17 && magics[i].c[0][3] + magics[i].c[2][3] == 17) ||
			(magics[i].c[2][0] + magics[i].c[2][2] == 17 && magics[i].c[3][0] + magics[i].c[3][2] == 17))
			magics[i].setType(12);
	}
}


void classList(){
	int classTypes[] = {0,0,0,0,0,0,0,0,0,0,0,0};
	for(unsigned int i = 0; i < magics.size(); i++)
		classTypes[magics[i].getType() - 1]++;
	cout << "Class list: " << endl << endl;
	for(int i = 0; i < 12; i++)
		cout << "Type " << i+1 << ": " << classTypes[i] << endl;
}


void sortLinearCompare(){
	STDMatrix temp;
	for(unsigned int i = 0; i < magics.size()-1; i++){
		for(unsigned int j = 0; j < magics.size()-i-1; j++){
			if(magics[j] > magics[j+1]){
				temp = magics[j+1];
				magics[j+1] = magics[j];
				magics[j] = temp;
			}	
		}
	}
}


void findUnique_Permute(){
	vector<STDMatrix> unique;
	STDMatrix dummy;

	int pTable[24] =	{1234, 1243, 1324, 1342, 1423, 1432,
						2134, 2143, 2314, 2341, 2413, 2431,
						3124, 3142, 3214, 3241, 3412, 3421,
						4123, 4132, 4213, 4231, 4312, 4321};
	bool ISunique;

	for(unsigned int i = 0; i < magics.size(); i++){
		ISunique = true;
		for(unsigned int j = 0; j < unique.size(); j++){
			for(int k = 0; k < 24; k++){

				//TESTING aPa UNIQUENESS
				dummy = magics[i];

				dummy.pAp(pTable[k]);
				if(dummy == unique[j]){
					ISunique = false;
					break;
				}
				dummy.transpose();
				if(dummy == unique[j]){
					ISunique = false;
					break;
				}
				//END aPa UNIQENESS TESTING

				for(int l = 0; l < 24; l++){

					//TESTING aP and/or pA UNIQUENESS
					dummy = magics[i];
					dummy.pA(pTable[k]);

					dummy.Ap(pTable[l]);
					if(dummy == unique[j]){
						ISunique = false;
						break;
					}
					dummy.transpose();
					if(dummy == unique[j]){
						ISunique = false;
						break;
					}
				}
				if(!ISunique)
					break;
			}
			if(!ISunique)
				break;
		}
		if(ISunique)
		unique.push_back(magics[i]);
	}
	magics.clear();
	for(unsigned int z = 0; z < unique.size(); z++)
		magics.push_back(unique[z]);
}