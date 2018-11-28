
#ifndef END_H
#define END_H

#include "shell.h"

using namespace std;

class End : public Shell
{
    private:
	Shell* command;
	char** arg;
    public:
        End(Shell* c)
	{
	    command = c;
	};
	void print() {};
	void convert();
	void execute();
	char** get() {};

};

#endif
