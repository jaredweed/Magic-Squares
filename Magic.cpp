#include "Magic.h"

Magic::Magic(void) : total(0), head(NULL) {
	for(int i = 0; i < Nsq; i++){
		this->remaining[i] = 0;
	}
}

Magic::~Magic(void){
}

bool Magic::isMagic(Matrix *A){
	return false;
}

unsigned long Magic::count(){
	return this->total;
}

void Magic::makeSquares3(int (&B)[Nsq], Matrix *A, int n){
}

void Magic::makeSquares4(int (&B)[Nsq], Matrix *A, int n){
	int rSum, rSum2, rSum3;

	for(int i = 1; i <= Nsq; i++){
		if(B[i-1] == 0){
			switch(n){
				case 1:
					B[i-1] = 1;
					A->cell[0][0] = i;
					makeSquares4(B, A, 2);
					break;

				case 2:
					B[i-1] = 1;
					A->cell[0][1] = i;
					makeSquares4(B, A, 3);
					break;

				case 3:
					rSum = M - A->cell[0][0] - A->cell[0][1] - i;
					if(rSum > 16 || B[rSum-1] == 1)
						continue;
					B[i-1] = 1;
					A->cell[0][2] = i;
					makeSquares4(B, A, 4);
					break;
				
				case 4:
					rSum = M - A->cell[0][0] - A->cell[0][1] - A->cell[0][2] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A->cell[0][3] = i;
						makeSquares4(B, A, 5);
					}
					else
						continue;
					break;

				case 5:
					B[i-1] = 1;
					A->cell[1][0] = i;
					makeSquares4(B, A, 9);
					break;

				case 9:
					rSum = M - A->cell[0][0] - A->cell[1][0] - i;
					if(rSum > 16 || B[rSum-1] == 1)
						continue;
					B[i-1] = 1;
					A->cell[2][0] = i;
					makeSquares4(B, A, 13);
					break;

				case 13:
					rSum = M - A->cell[0][0] - A->cell[1][0] - A->cell[2][0] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A->cell[3][0] = i;
						makeSquares4(B, A, 6);
					}
					else
						continue;
					break;
				
				case 6:
					B[i-1] = 1;
					A->cell[1][1] = i;
					makeSquares4(B, A, 7);
					break;

				
				case 7:
					rSum = M - A->cell[1][0] - A->cell[1][1] - i;
					rSum2 = M - A->cell[0][3] - A->cell[3][0] - i;
					if(rSum > 16 || rSum2 > 16 || B[rSum-1] == 1 || B[rSum2-1] == 1)
						continue;
					B[i-1] = 1;
					A->cell[1][2] = i;
					makeSquares4(B, A, 8);
					break;

				case 8:
					rSum = M - A->cell[1][0] - A->cell[1][1] - A->cell[1][2] - i;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A->cell[1][3] = i;
						makeSquares4(B, A, 10);
					}
					else
						continue;
					break;

				case 10:
					rSum = M - A->cell[0][3] - A->cell[1][2] - A->cell[3][0] - i;
					rSum2 = M - A->cell[0][1] - A->cell[1][1] - i;
					if(rSum2 > 16 || B[rSum2-1] == 1)
						continue;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A->cell[2][1] = i;
						makeSquares4(B, A, 14);
					}
					else
						continue;
					break;
				
				case 14:
					rSum = M - A->cell[0][1] - A->cell[1][1] - A->cell[2][1] - i;
					if(rSum == 0 && B[rSum-1] != 1)
						B[i-1] = 1;
						A->cell[3][1] = i;
						makeSquares4(B, A, 11);
						break;

				case 11:
					rSum = M - A->cell[0][2] - A->cell[1][2] - i;
					rSum2 = M - A->cell[2][0] - A->cell[2][1] - i;
					rSum3 = M - A->cell[0][0] - A->cell[1][1] - i;
					if(rSum > 16 || rSum2 > 16 || rSum3 > 16 || B[rSum-1] == 1 || B[rSum2-1] == 1 || B[rSum3-1] == 1)
						continue;
					B[i-1] = 1;
					A->cell[2][2] = i;
					makeSquares4(B, A, 12);
					break;

				case 12:
					rSum = M - A->cell[2][0] - A->cell[2][1] - A->cell[2][2] - i;
					rSum2 = M - A->cell[0][3] - A->cell[1][3] - i;
					if(rSum2 > 16 || B[rSum2-1] == 1)
						continue;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A->cell[2][3] = i;
						makeSquares4(B, A, 15);
					}
					else
						continue;
					break;

				case 15:
					rSum = M - A->cell[0][2] - A->cell[1][2] - A->cell[2][2] - i;
					rSum2 = M - A->cell[3][0] - A->cell[3][1] - i;
					if(rSum2 > 16 || B[rSum2-1] == 1)
						continue;
					if(rSum == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A->cell[3][2] = i;
						makeSquares4(B, A, 16);
					}
					else
						continue;
					break;
				
				case 16:
					rSum = M - A->cell[0][0] - A->cell[1][1] - A->cell[2][2] - i;
					rSum2 = M - A->cell[0][3] - A->cell[1][3] - A->cell[2][3] - i;
					rSum3 = M - A->cell[3][0] - A->cell[3][1] - A->cell[3][2] - i;
					if(rSum == 0 && rSum2 == 0 && rSum3 == 0 && B[i-1] != 1){
						B[i-1] = 1;
						A->cell[3][3] = i;
						this->push(A);
					}
					break;
			}
			B[i-1] = 0;
		}
	}
	return;
}

void Magic::makeSquares5(int (&B)[Nsq], Matrix *A, int n){
}

void Magic::push(Matrix *A){
	Matrix *temp = new Matrix;
	temp = A;
	temp->next = this->head;
	this->head = temp;
	this->total++;
}

void Magic::pop(Matrix *A){

}

bool Magic::unique(Matrix *A, Matrix *B){
	return false;
}

void Magic::printSquare(Matrix *A){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << A->cell[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}


