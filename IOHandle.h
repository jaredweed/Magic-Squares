#pragma once
#include "Magic.h"

class IOHandle
{
private:
	bool terminate;
	Magic obj;
	Matrix m;

public:
	time_t start;
	time_t end;
	IOHandle(void);
	~IOHandle(void);
	bool exit();
	void run();
	void parseInput();
	void listCommands();

};

