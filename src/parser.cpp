#include <iostream>
#include <vector>
#include <string>
#include "parser.h"
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_iterator.hpp>

using namespace std;
using namespace boost;

void Parser::parser(string input, vector<string>& vect)
{
    typedef boost::tokenizer<boost::char_separator<char>> Tok;
    boost::char_separator<char> conn(" ");
    Tok connector(input, conn);

    for (Tok::iterator tok_iter = connector.begin(); tok_iter != connector.end(); tok_iter++)
    {
        if (tok_iter == connector.end())
        {
            return;
        }

        if (*tok_iter == " ")
        {
            tok_iter++;
        }
        
        for (int a = 0; a < 2; a++)
        {
            if (*tok_iter == "&")
            {
                a++;
                if (tok_iter != connector.end())
                {
                    tok_iter++;
                    if (*tok_iter == "&")
                    {
                        vect.push_back("&&");
                        a++;
                    }
                }
            }
        }

        for (int b = 0; b < 2; b++)
        {
            if (*tok_iter == "|")
            {
                b++;
                if (tok_iter != connector.end())
                {
                    tok_iter++;
                    if (*tok_iter == "|")
                    {
                        vect.push_back("||");
                        b++;
                    }
                }
            }
        }

        if (*tok_iter != "|" && *tok_iter != "&")
        {
            vect.push_back(*tok_iter);
        }
    }
};

string Parser::at(int i)
{
	return parsedVector[i]; //basically a getter
};

void print() {};
