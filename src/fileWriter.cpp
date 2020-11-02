#include <iostream>
#include <fstream>
#include <string>
#include "fileWriter.h"

using namespace std;

void CFileWriter::fileWriter(string menu)
{
    const char *fileName = "C:\\temp\\menu.txt";

    ofstream ofs(fileName,ios::app);
    if (ofs)
    {
    	 ofs << menu << endl;
    	 cout << fileName << "に書き込みました。" << endl;
    }else{
    cout << "ファイルが開けませんでした。" << endl;
    }
}
