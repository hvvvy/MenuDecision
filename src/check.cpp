#include <cassert>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
//#include <mbstring.h>
//#include <Windows.h>

#include "fileWriter.h"
#include "fileReader.h"
#include "random.h"
#include "check.h"
//#include "stdafx.h"

using namespace std;

/*
void CCheck::checkFileEmpty()
{

}

*/
void CCheck::checkChoice()
{
	CFileWriter fw;
	CFileReader fr;
	CRandom rd;

	vector<string> menulist;
	char choice;
	string menu;
	bool judge = true;

	cout << "料理を追加するなら1を、メニューを決めるなら5を入力してください";



	while(judge) {
		//入力を受け付ける
		cin >> choice;
		//半角数字チェック
		if (choice >= '0' && choice <= '9')
		{
			cout << choice <<"が選択されました" << endl;
			//型変換
			int iChoice = choice;
			//数字でその後の処理を選択
			switch(iChoice){
				//1が選択された場合の処理
				case 49:
				{
					cout << "料理を登録してください";
					//入力した料理を受け付ける
					cin >> menu;
					if(!menu.empty()){
						//受け付けた料理をファイルに書き込む処理
						fw.fileWriter(menu);
						cout <<"\n続けて追加するなら1を、メニューを決定するなら5を、追加を終了しアプリを閉じるなら9を入力してください。"<< endl;
					}else{
						cout << "正しく入力されませんでした。もう一度入力して下さい" << endl;
				}
				break;
				}
				//5が選択された場合の処理
				case 53:
				{
					//読み込み処理
					//ファイルから料理をmenulistに格納
					fr.fileReader(menulist);
					//乱数の初期値を設定
					rd.InitRand();
					//登録している料理の数に合わせて乱数を発生させる
					int resltRand = rd.random(menulist.size());
					cout << "今日のご飯は" << menulist[resltRand] << "です" <<flush;



						cout << resltRand ;


					cout <<"\nもう一度やり直すなら5を、アプリを終了するなら9を入力してください。"<< endl;
					break;
				}
				//9が選択された場合の処理
				case 57:
				{
					cout << "アプリを終了します。" << endl;
					judge = false;
					break;
				}
				default:
				{
					cout << "入力が正しくありません。\n追加するなら1を、メニューを決定するなら5を、追加を終了するなら9を入力してください。" << endl;
					break;
				}
			}
		}
		else
		{
			cout << "半角数字で入力してください"<<endl;
		}
	}
}
