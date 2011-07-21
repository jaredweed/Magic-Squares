#pragma once
#include "Magic.h"

class IODHandler
{
private:
	bool terminate;
	Magic mObj;

public:
	IODHandler(void);
	~IODHandler(void);
	void run();
	bool exit();
	void parseInput();
	void listCommands();
	void throwException(int i);
};

