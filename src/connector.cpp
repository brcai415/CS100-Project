#include <iostream>
#include <vector>
#include <string>
#include "connector.h"

using namespace std;

void Connector::checkConnectors()
{
    string semiConnector = ";";
    string andConnector = "&&";
    string orConnector = "||";

    for(int i = 0; i < passedVector.size() ; ++i)
    {
        if(passedVector[i] == semiConnector)
        {
            // Semi* foundSemi = new Semi();
            cout << "Found semicolon" << endl;
        }

        if(passedVector[i] == andConnector)
        {
            // And* foundSemi = new And();
            cout << "Found and" << endl;
        }

        if(passedVector[i] == orConnector)
        {
            // Or* foundSemi = new Or();
            cout << "Found or" << endl;
        }
    }
};
