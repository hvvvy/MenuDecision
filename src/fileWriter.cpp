#include <iostream>
#include <fstream>
#include <string>
#include <fileSystem>

#include "fileWriter.h"

using namespace std;

CFileWriter::CFileWriter()
{
	fileName = "C:\\temp\\menu.txt";
}

/*
void CFileWriter::createDir()
{

}
*/

void CFileWriter::fileWriter(string menu,bool empty)
{
    ofstream ofs(fileName,ios::app);
    if (ofs)
    {
    	if(empty)
    	{
    		//ファイルが空ならmenuの後ろに改行
    		ofs<< menu;
    	}else{
    		//既にメニューが登録されていればmenuの前に改行
    		ofs<< "\n" << menu;
    	}
    	 cout << fileName << "に書き込みました。" << endl;
    }else{
    cout << "ファイルが開けませんでした。\n"
    		"ファイルを開いている場合は閉じてください。" << endl;
    }
}
