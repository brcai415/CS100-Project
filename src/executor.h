

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <vector>
#include "shell.h"

class Executor : public Shell
{
    private:
        vector<Shell*> toExecute;
    public:
        Executor() {};
        void add(Shell* leaf)
        {
            toExecute.push_back(leaf);
        }
        void print()
        {
            for(int i=0; i<toExecute.size(); i++)
	    {
		cout << "Executor commands: ";
		toExecute[i]->print();
	    }
        }
	char** get() {};
	void execute()
	{
	    for(int i=0; i<toExecute.size(); i++)
	    {
		toExecute[i]->execute();
	    }
	}

};

#endif
