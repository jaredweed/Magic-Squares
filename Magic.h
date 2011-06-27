#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

#define VERSION "1.0 (June 21st, 2011)"
#define AUTHOR "Jared Weed"
#define N 4
#define Nsq N * N
#define M N * (N * N + 1) / 2


struct Matrix{
	int ctype;
	int cell[N][N];
	Matrix *next;
};

class Magic
{
private:
	unsigned long total;
	Matrix *head;

public:
	int remaining[Nsq];
	Magic(void);
	~Magic(void);
	bool isMagic(Matrix *A);
	unsigned long count();
	void makeSquares3(int (&B)[Nsq], Matrix *A, int n);
	void makeSquares4(int (&B)[Nsq], Matrix *A, int n);
	void makeSquares5(int (&B)[Nsq], Matrix *A, int n);
	void push(Matrix *A);
	void pop(Matrix *A);
	bool unique(Matrix *A, Matrix *B);
	void printSquare(Matrix *A);
	void permute(int perm[], Matrix *A);
	void permute(Matrix *A, int perm[]);
	void classify();
	void sort();
};

