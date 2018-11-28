#include <iostream>
#include "and.h"
#include <vector>

using namespace std;

void And::convert(){
    argLeft = andLeft->get();
    argRight = andRight->get(); 
};

void And::execute(){
    //And execution logic
    this->convert();

    int status, fail;
    pid_t childID, parentID;

    childID = fork(); // for child and parent
    if (childID < 0)
    {
        perror("Forking error");
        exit(EXIT_FAILURE);
    }
    if (childID == 0)
    {
        fail = execvp(*argLeft, argLeft);
        if (fail < 0)
            perror("Child execution failed"); //if child failed to execute
    }

    parentID = wait(&status);
    if (status < 0)
        perror("Abnormal exit of program");
    if (fail != -1)
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
		perror("Child executino failed");
        }
	
	parentID = wait(&status);
	if (parentID < 0)
	    perror("Abnormal exit of program");
    }
};