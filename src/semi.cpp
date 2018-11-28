#include <iostream>
#include <vector>
#include "semi.h"


using namespace std;

void Semi::convert()
{
    arg = semiCommand->get();
};

void Semi::execute()
{
    this->convert();

    int status, fail;
    pid_t childID, parentID;

    childID = fork();
    if (childID < 0)
    {
	perror("Forking error");
	exit(EXIT_FAILURE);
    }
    if (childID == 0)
    {
	fail = execvp(*arg, arg);
	if (fail < 0)
	    perror("Child execution failed");
    }

    parentID = wait(&status);
    if(status < 0)
	perror("Abnormal exit of program");
};
