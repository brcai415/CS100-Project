#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include <string>
#include "shell.h"

using namespace std;

class Parser: public Shell
{
    protected:
    vector<string> parsedVector;

    public:
    Parser(){};

    vector<string> getVector()
    {
        return parsedVector;
    };

    void print()
    {
        cout << "PARSED VECTOR: ";

        for(int i = 0; i < parsedVector.size(); i++)
        {
            cout << "Index: " << i  << " " << parsedVector[i] << " " << endl;
        }

        cout << "Vector size " << parsedVector.size() << endl;
    };

    void parser(string, vector<string>&);

    string at(int);

    int size()
    {
        return parsedVector.size();
    }

    char** get() {};
};

#endif
