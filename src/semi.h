//semi class
#ifndef SEMI_H
#define SEMI_H

#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

using namespace std;

class Semi: public Shell
{
    private:
        Shell* semiCommand;
	char** arg;

    public:
        Semi(Shell* com)
        {
            semiCommand = com;
        };

        void print()
        {
	    cout << "Semi Command: " << semiCommand << endl;
        };
	string getStr() {};
	char** get() {};
	bool getEsc()
	{
	    return esc;
	}
	void convert();
        void execute();
};

#endif
