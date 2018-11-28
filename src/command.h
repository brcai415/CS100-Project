#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include "shell.h"
using namespace std;

class Command: public Shell
{
    private:
        string command;
	char** arg;
	vector<string> parsed;

    public:
        Command(string c)
        {
	    esc = false;
	    comment = false;
	    command = c;
        }
	void print()
	{
	    cout << "Command: " << command << endl;
	}
        char** get(){
	    parsed = this->parsing(command);
	    
	    arg = new char *[parsed.size()+1];

	    for (int i=0; i<parsed.size(); i++)
	    {
		
	        arg[i] = const_cast <char*> ((parsed[i]).c_str());
	    }

	    arg[parsed.size()] = NULL;
	    return arg;
	}
	string getStr()
	{
	    return this->command;
	}
        void execute() {};
	bool getEsc() {};
};

#endif
