#pragma once

#include "gHeader.h"

class STDMatrix
{

private:
	int classType;

public:
	int c[N][N];
	STDMatrix(void);
	~STDMatrix(void);
	void operator=(const STDMatrix& m);
	bool operator==(const STDMatrix& m) const;
	bool operator>(const STDMatrix& m) const;
	void print();
	int getType();
	void setType(int t);
	void pA(int p); //permute from left
	void Ap(int p); //permute from right
	void pAp(int p); //permute from both
	void transpose();
};

