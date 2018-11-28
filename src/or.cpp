#include <iostream>
#include <vector>
#include "or.h"

using namespace std;

void Or::convert()
{
    argLeft = orLeft->get();
    argRight = orRight->get();
};

void Or::execute()
{
    //Or execution logic
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
	fail = execvp(*argLeft, argLeft);
	if (fail < 0)
	    perror("Child execution failed");
    }

    parentID = wait(&status);
    if (status < 0)
	perror("Abnormal exit of program");
    if (fail == -1)
    {
	childID = fork();
	if (childID < 0)
	{
	    perror("Forking error");
	    exit(EXIT_FAILURE);
	}
	if (childID == 0)
	{
	    fail = execvp(*argRight, argRight);
	    if (fail < 0)
		perror("Child execution failed");
	}
	
	parentID = wait(&status);
	if (parentID < 0)
	    perror("Abnormal exit of program");
    }
};
