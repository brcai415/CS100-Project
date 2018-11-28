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
	    command = c;
        }
	void print()
	{
	    cout << "Command: " << command << endl;
	}
        char** get(){
	    parsed = this->parsing(command);
	    arg = new char *[parsed.size()+1];
	    for(int i=0; i<parsed.size(); i++)
	    {
		if (parsed[i] == "exit")  //quick exit program. probably not the way to do it. :eaves an endline
		    arg[i] = NULL;
		else
	            arg[i] = const_cast <char*> ((parsed[i]).c_str());
	    }
	    arg[parsed.size()] = NULL;
	    return arg;
	}
        void execute() { };
};

#endif
