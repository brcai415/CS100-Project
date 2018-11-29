#include <iostream>
#include "and.h"
#include <vector>

using namespace std;

void And::convert()
{
    argLeft = andLeft->get();
    argRight = andRight->get();
};


void And::execute()
{

    string checkL = andLeft->getStr();
    string checkR = andRight->getStr();

    if (checkL == "exit " || checkL == "exit" || checkL == " exit" || checkL == " exit ")
    {
	esc = true;
        return;
    }

    if (checkL== "test" || checkL == "test " || checkL == " test" || checkL == " test ")
    {
        cout << "FOUND TEST COMMAND" << endl;

    }

    //And execution logic
    this->convert();

    int status;
    pid_t childID, parentID;

    if (fail == 0)
    {
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
    }

    if (fail != -1 && (checkR == "exit " || checkR == "exit" || checkR == " exit" || checkR == " exit "))
    {
	esc = true;
	return;
    }

    if (fail != -1 && (checkR == "test" || checkR == "test" || checkR == " test" || checkR == " test "))
    {
        cout << "FOUND TEST COMMAND" << endl;
    }

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

    if (fail != -1)
        fail = 1;
};
