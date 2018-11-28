//or class
#ifndef OR_H
#define OR_H

#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

using namespace std;

class Or: public Shell
{
    private:
        Shell* orLeft;
        Shell* orRight;
	char** argLeft;
	char** argRight;
				
    public:
        Or(Shell* leftChild, Shell* rightChild)
        {
            orLeft = leftChild;
            orRight = rightChild;
        }

        void print()
        {
            cout << "Left Child = ";
	    orLeft->print();
            cout << "Right Child = ";
	    orRight->print();
        }
	char** get() {};
	void convert();
        void execute();
};

#endif
