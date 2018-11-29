
#include "end.h"

using namespace std;

void End::convert()
{
    arg = command->get();
};

void End::execute()
{
    this->convert();

    int status;
    pid_t childID, parentID;


    if (command->getStr() == "exit" || command->getStr() == "exit " ||
	command->getStr() == " exit" || command->getStr() == " exit ")
    {
	esc = true;
	return;
    }

    if (command->getStr() == "test" || command->getStr() == "test " || 
	command->getStr() == " test" || command->getStr() == " test "  )
    {
        cout << "FOUND TEST COMMAND" << endl;
    }

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
    if (status < 0)
	perror("Abnormal exit of program");

    fail = 0;
};
