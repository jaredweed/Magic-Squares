#pragma once
#include "gVars.h"

class STDMatrix
{
private:
	int classType;

public:
	int c[N][N];
	STDMatrix(void);
	~STDMatrix(void);
	bool isMagic();
	void print();
	int getClass();
	void classify();
	void permute_l(int p);
	void permute_r(int p);
	void transpose();
	bool operator=(const STDMatrix& m) const;
	bool operator>(const STDMatrix& m) const;
};

