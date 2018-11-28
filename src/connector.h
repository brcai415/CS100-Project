#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <iostream>
#include <vector>
#include "shell.h"

using namespace std;

class Connector: public Shell
{
    private:
        vector<string> passedVector;
        Shell* leftChild;
        Shell* rightChild;

    public:
        Connector(vector<string> parsedVector)
        {
            passedVector = parsedVector;
        };

        void execute();

        void checkConnectors();
	void print() {};
	char** get() {};
};

#endif
