#include "STDMatrix.h"


STDMatrix::STDMatrix(void)
{
}


STDMatrix::~STDMatrix(void)
{
}


void STDMatrix::operator=(const STDMatrix& m) {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			c[i][j] = m.c[i][j];
		}
	}
}


bool STDMatrix::operator==(const STDMatrix& m) const{
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(c[i][j] != m.c[i][j])
				return false;
		}
	}
	return true;
}


bool STDMatrix::operator>(const STDMatrix& m) const {
	if(c[0][0] > m.c[0][0])
		return true;
	if(c[0][0] < m.c[0][0])
		return false;
	if(c[0][1] > m.c[0][1])
		return true;
	if(c[0][1] < m.c[0][1])
		return false;
	if(c[1][0] > m.c[1][0])
		return true;
	if(c[1][0] < m.c[1][0])
		return false;
	if(c[1][1] > m.c[1][1])
		return true;
	if(c[1][1] < m.c[1][1])
		return false;
	if(c[0][2] > m.c[0][2])
		return true;
	if(c[0][2] < m.c[0][2])
		return false;
	if(c[2][0] > m.c[2][0])
		return true;
	return false;
}

void STDMatrix::print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << setw(2) << c[i][j] << " ";
		}
		cout << endl;
		if(i == N-1)
			cout << "\nTYPE " << classType;
	}
}

int STDMatrix::getType(){
	if(classType > 0)
		return classType;
	else
		return -1;
}

void STDMatrix::setType(int t){
	classType = t;
}


void STDMatrix::pA(int p){
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


void STDMatrix::Ap(int p){
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


void STDMatrix::pAp(int p){
	pA(p);
	Ap(p);
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

