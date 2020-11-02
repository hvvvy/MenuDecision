#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "fileReader.h"

using namespace std;

void CFileReader::fileReader(vector<string>& menulist)
{
    const char *fileName = "C:\\temp\\menu.txt";
    string buf;

    ifstream ifs(fileName);
    if (ifs)
    {
    	while (!ifs.eof())
    	{
    		getline(ifs, buf);
    		menulist.push_back(buf);
    	}
    }else{
    	cout << "ファイルが開けませんでした。" << endl;
    }

}
