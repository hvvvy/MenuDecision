#include <iostream>
#include <regex>
#include <string>

#include "check.h"

using namespace std;

bool CCheck::checkType(string schoice)
{
	//半角数字の正規表現
	regex pattern("^[0-9]+$");
	smatch sm;
    if (regex_match(schoice, sm, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool CCheck::checkEmpty()
{
	FILE *f = fopen("C:\\temp\\menu.txt", "r");

	if(fscanf(f,"%c",&ch)==EOF)
	{
	    empty = true;
	}else{
		empty = false;
	}
	fclose(f);

	return empty;
}
