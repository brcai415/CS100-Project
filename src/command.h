#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "shell.h"
using namespace std;

class Command: public Shell
{
    private:
        string command;
    	char** arg;
    	vector<string> parsed;
	
    protected:
        bool testResult;
    public:
        Command(string c)
        {
    	    esc = false; // exit command
    	    comment = false; // # connector
	    fail =  0;  // to prevent repeats of && and ||
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
		if (parsed[i] == "#")
		    arg[i] = NULL;

        else if (parsed[i] == "test")
        {
            arg[i] = NULL;
            if((i + 1) < parsed.size() && (i + 2) < parsed.size())
            {
                string flag = parsed[i + 1];
                string path = parsed[i + 2];

                testResult = testCommand(flag, path);
                break;
            }

            else
            cout << "Not a valid test" << endl;
            break;
        }

        else
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
    int getFail() {};
    void setFail(int) {};
    bool testCommand(string passedFlag, string passedPath)
    {
        struct stat sb;
        string flag = passedFlag;
        string path = passedPath;

        //PRIMING STAT WITH PATH.
        int statValue = stat(path.c_str(), &sb);
        /*-e checks if the file/directory exists*/
        if(flag == "-e")
        {
            if(statValue == 0)
            {
                cout << "(True)" << endl;
                return true;
            }
            else
            {
                cout << "(False)" << endl;
                return false;
            }
        }

        /*-f checks if the file/directory exists and is a regular file*/
        if(flag == "-f")
        {
            if(S_ISREG(sb.st_mode))
            {
                cout << "(True)" << endl;
                return true;
            }

            else
            {
                cout << "(False)" << endl;
                return false;
            }
        }

        /*-d checks if the file/directory exists and is a directory*/
        if(flag == "-d")
        {
            if(S_ISDIR(sb.st_mode))
            {
                cout << "(True)" << endl;
                return true;
            }

            else
            {
                cout << "(False)" << endl;
                return false;
            }
        }
    };
};

#endif
