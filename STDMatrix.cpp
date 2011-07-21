#include "STDMatrix.h"


STDMatrix::STDMatrix(){
}

STDMatrix::~STDMatrix(){
}

void STDMatrix::print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << setw(2) << c[i][j] << " ";
		}
		cout << endl;
	}
}

int STDMatrix::getClass(){
	return classType;
}

bool STDMatrix::operator=(const STDMatrix& m) const {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(this->c[i][j] == m.c[i][j])
				return false;
		}
	}
	return true;
}

bool STDMatrix::operator>(const STDMatrix& m) const {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(this->c[i][j] > m.c[i][j])
				return true;
		}
	}
	return false;
}

void STDMatrix::permute_l(int p){
	int pArr[N];
	int pCheck[N] = {0,0,0,0};
	int temp;
	for(int i = N-1; i >= 0; i--){
		pArr[i] = p % 10;
		p /= 10;
	}
	for(int i = 0; i < N; i++){
		if(i == pArr[i]-1 || pCheck[i] == 1)
			continue;
		pCheck[i] = 1;
		pCheck[pArr[i]-1] = 1;
		for(int j = 0; j < N; j++){
			temp = c[pArr[i]-1][j];
			c[pArr[i]-1][j] = c[i][j];
			c[i][j] = temp;
		}
	}
}

void STDMatrix::permute_r(int p){
	int pArr[N];
	int pCheck[N] = {0,0,0,0};
	int temp;
	for(int i = N-1; i >= 0; i--){
		pArr[i] = p % 10;
		p /= 10;
	}
	for(int j = 0; j < N; j++){
		if(j == pArr[j]-1 || pCheck[j] == 1)
			continue;
		pCheck[j] = 1;
		pCheck[pArr[j]-1] = 1;
		for(int i = 0; i < N; i++){
			temp = c[i][pArr[j]-1];
			c[i][pArr[j]-1] = c[i][j];
			c[i][j] = temp;
		}
	}
}

void STDMatrix::transpose(){
	int temp;
	for(int i = 1; i < N; i++){
		for(int j = 0; j < i; j++){
			temp = c[i][j];
			c[i][j] = c[j][i];
			c[j][i] = temp;
		}
	}
}