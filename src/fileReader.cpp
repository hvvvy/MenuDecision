#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "fileReader.h"

using namespace std;

CFileReader::CFileReader()
{
	fileName = "C:\\temp\\menu.txt";
}

void CFileReader::fileReader(vector<string>& menulist)
{
    ifstream ifs(fileName);
    if (ifs)
    {
    	while (!ifs.eof())
    	{
    		getline(ifs, buf);
    		menulist.push_back(buf);
    	}
    }else{
		cout << "\nファイルが開けない、もしくは存在しません。"
				"\nまだメニューを登録していない場合に表示されることがあります。" << endl;
    }

}

void CFileReader::exchangeMenulist(std::vector<std::string>& menulist)
{
	//ファイルの中身を一旦リストに格納
	vector<string> buflist;

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

string CFileReader::allMenuReader(string& allMenu,bool& fileExists)
{
	//呼び出すたびallMenuをリセット
	allMenu = "";
	ifstream ifs(fileName);
	if (ifs)
	{
		while (!ifs.eof())
		{
			getline(ifs, buf);
			allMenu += (buf + "\n");
		}
		fileExists = true;
	}else{
		cout << "ファイルが存在しません。" << endl;
		fileExists = false;
	}
	return allMenu;
}
