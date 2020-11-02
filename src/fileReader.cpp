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
void CFileReader::exchangeMenulist(std::vector<std::string>& menulist)
{
	//ファイルの中身を一旦リストに格納
	vector<string> buflist;
	const char *fileName = "C:\\temp\\menu.txt";
	    string buf;

	    ifstream ifs(fileName);
	    if (ifs)
	    {
	    	while (!ifs.eof())
	    	{
	    		getline(ifs, buf);
	    		buflist.push_back(buf);
	    	}
	    	//menulistがbuflistのアドレスを指すことにより、中身が更新される
	    	menulist = buflist;
	    }else{
	    	cout << "ファイルが開けませんでした。" << endl;
	    }

}
