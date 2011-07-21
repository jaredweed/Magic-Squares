#include "Magic.h"


Magic::Magic(void){
	for(int i = 0; i < NSQ; i++){
		this->remaining[i] = 0;
	}
}

Magic::~Magic(void){
}

void Magic::createSquares(){
	if(N == 4)
		createOrder4(remaining, builder, 1);
}

void Magic::createOrder4(int(&B)[NSQ], STDMatrix &A, int n){
	int rSum, rSum2, rSum3;

	for(int i = 1; i <= NSQ; i++){
		if(B[i-1] == 0){
			switch(n){
				case 1:
					B[i-1] = 1;
					A.c[0][0] = i;
					createOrder4(B, A, 2);
					break;

				case 2:
					B[i-1] = 1;
					A.c[0][1] = i;
					createOrder4(B, A, 3);
					break;

				case 3:
					rSum = M - A.c[0][0] - A.c[0][1] - i;
					if(rSum > 16 || B[rSum-1] == 1)
						continue;
					B[i-1] = 1;
					A.c[0][2] = i;
					createOrder4(B, A, 4);
					break;
				
				case 4:
					rSum = M - A.c[0][0] - A.c[0][1] - A.c[0][2] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[0][3] = i;
						createOrder4(B, A, 5);
					}
					else
						continue;
					break;

				case 5:
					B[i-1] = 1;
					A.c[1][0] = i;
					createOrder4(B, A, 9);
					break;

				case 9:
					rSum = M - A.c[0][0] - A.c[1][0] - i;
					if(rSum > 16 || B[rSum-1] == 1)
						continue;
					B[i-1] = 1;
					A.c[2][0] = i;
					createOrder4(B, A, 13);
					break;

				case 13:
					rSum = M - A.c[0][0] - A.c[1][0] - A.c[2][0] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[3][0] = i;
						createOrder4(B, A, 6);
					}
					else
						continue;
					break;
				
				case 6:
					B[i-1] = 1;
					A.c[1][1] = i;
					createOrder4(B, A, 7);
					break;

				
				case 7:
					rSum = M - A.c[1][0] - A.c[1][1] - i;
					rSum2 = M - A.c[0][3] - A.c[3][0] - i;
					if(rSum > 16 || rSum2 > 16 || B[rSum-1] == 1 || B[rSum2-1] == 1)
						continue;
					B[i-1] = 1;
					A.c[1][2] = i;
					createOrder4(B, A, 8);
					break;

				case 8:
					rSum = M - A.c[1][0] - A.c[1][1] - A.c[1][2] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[1][3] = i;
						createOrder4(B, A, 10);
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
						createOrder4(B, A, 14);
					}
					else
						continue;
					break;
				
				case 14:
					rSum = M - A.c[0][1] - A.c[1][1] - A.c[2][1] - i;
					if(rSum == 0 && B[rSum-1] != 1)
						B[i-1] = 1;
						A.c[3][1] = i;
						createOrder4(B, A, 11);
						break;

				case 11:
					rSum = M - A.c[0][2] - A.c[1][2] - i;
					rSum2 = M - A.c[2][0] - A.c[2][1] - i;
					rSum3 = M - A.c[0][0] - A.c[1][1] - i;
					if(rSum > 16 || rSum2 > 16 || rSum3 > 16 || B[rSum-1] == 1 || B[rSum2-1] == 1 || B[rSum3-1] == 1)
						continue;
					B[i-1] = 1;
					A.c[2][2] = i;
					createOrder4(B, A, 12);
					break;

				case 12:
					rSum = M - A.c[2][0] - A.c[2][1] - A.c[2][2] - i;
					rSum2 = M - A.c[0][3] - A.c[1][3] - i;
					if(rSum2 > 16 || B[rSum2-1] == 1)
						continue;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A.c[2][3] = i;
						createOrder4(B, A, 15);
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
						createOrder4(B, A, 16);
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

void Magic::push(STDMatrix &A){
	STDMatrix *magic = new STDMatrix;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			magic->c[i][j] = A.c[i][j];
		}
	}
	magics.push_back(*magic);
}

void Magic::simpleSort(){
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
				magics[x].permute_r(4321);
		}
		if(loc_i == 1){
			if(loc_j == 0)
				magics[x].transpose();
			if(loc_j == 1){
				magics[x].permute_l(2143);
				magics[x].permute_r(2143);
			}
			if(loc_j == 2){
				magics[x].permute_l(2143);
				magics[x].permute_r(3412);
			}
			if(loc_j == 3){
				magics[x].transpose();
				magics[x].permute_l(4321);
			}
		}
		if(loc_i == 2){
			if(loc_j == 0){
				magics[x].transpose();
				magics[x].permute_r(4321);
			}
			if(loc_j == 1){
				magics[x].permute_l(3412);
				magics[x].permute_r(2143);
			}
			if(loc_j == 2){
				magics[x].permute_l(3412);
				magics[x].permute_r(3412);
			}
			if(loc_j == 3){
				magics[x].transpose();
				magics[x].permute_l(4321);
				magics[x].permute_r(4321);
			}
		}
		if(loc_i == 3){
			if(loc_j == 0 || loc_j == 1)
				magics[x].permute_l(4321);
			if(loc_j == 2 || loc_j == 3){
				magics[x].permute_l(4321);
				magics[x].permute_r(4321);
			}
		}
		found = false;
	}
}

void Magic::sortByEnumeration(){
	//first pass, break matrices into two vectors
	vector<STDMatrix> tl_1;
	vector<STDMatrix> tl_2;
	//int passed = 0;
	//STDMatrix *temp;
	for(unsigned int x = 0; x < magics.size(); x++){
		if(magics[x].c[0][0] == 1)
			tl_1.push_back(magics[x]);
		else
			tl_2.push_back(magics[x]);
			//cout << magics.size()-1-passed << endl;
			//swap(magics[x], magics[magics.size()-1-passed]);
			/*temp = &magics[magics.size() - 1 - passed];
			magics[magics.size() - 1 - passed] = magics[x];
			magics[x] = *temp;*/
			//passed++;
			//x--;
			
			//magics.erase(magics.begin() + x - passed + 1);
			/*magics.push_back(*temp);
			magics[magics.size()-1].print();
			cout << endl << endl;
			magics[x].print();
			cout << "position: " << x << endl;
			cin.get();*/
		//	magics[magics.size() - 1 - passed] = magics[x];
		//	magics[x] = *temp;*/
		//	passed++;
		//}

	//next, bubble sort
	}
	for(unsigned int x = 0; x < tl_1.size()-2; x++){
		for(unsigned int y = 0; y < tl_1.size()-1-x; y++){
			if(tl_1[y] > tl_1[y+1])
				swap(tl_1[y], tl_1[y+1]);
		}
	}

	for(unsigned int x = 0; x < tl_2.size()-2; x++){
		for(unsigned int y = 0; y < tl_2.size()-1-x; y++){
			if(tl_2[y] > tl_2[y+1])
				swap(tl_2[y], tl_2[y+1]);
		}
	}
	//push them back in
	magics.resize(0);
	for(unsigned int i = 0; i < tl_1.size(); i++)
		magics.push_back(tl_1[i]);
	for(unsigned int i = 0; i < tl_2.size(); i++)
		magics.push_back(tl_2[i]);
}

