#pragma once
#include "STDMatrix.h"

#pragma once
#include "STDMatrix.h"

class Magic
{
private:
	int remaining[NSQ];

public:
	vector<STDMatrix> magics;
	STDMatrix builder;
	Magic(void);
	~Magic(void);
	void simpleSort();
	void sortByEnumeration();
	void sortByClassification();
	void classifyOrder4();
	void push(STDMatrix &A);
	void pull();
	void findUnique_shallow();
	void findUnique_deep();
	void createSquares(); // entry point for N-order creation from IOHandler

/* square creation setting */
	void createOrder3(int (&B)[NSQ], STDMatrix &A, int n);
	void createOrder4(int (&B)[NSQ], STDMatrix &A, int n);
	void createOrder5(int (&B)[NSQ], STDMatrix &A, int n);
};

