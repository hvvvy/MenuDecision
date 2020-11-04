#include <cassert>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

#include "fileWriter.h"
#include "fileReader.h"
#include "random.h"
#include "checkType.h"


using namespace std;


int main()
{
	CFileWriter fw;
	CFileReader fr;
	CRandom rd;
	CCheckType ck;

	vector<string> menulist;
	string choice;
	string menu;
	bool judge = true;

	cout << "料理を追加するなら「1」を、メニューを決めるなら「5」を入力してください。";

	//読み込み処理
	//ファイルから料理をmenulistに格納
	fr.fileReader(menulist);

	while(judge) {
		//入力を受け付ける
		cin >> choice;
		//半角数字チェック
		if(ck.checkType(choice))
		{
			cout <<"「" << choice <<"」が選択されました。" << endl;
			//string型からint型へ変換
			int iChoice = stoi(choice);
			//数字でその後の処理を選択
			switch(iChoice){
				//1が選択された場合の処理
				case 1:
				{
					cout << "料理を登録してください。";
					//入力した料理を受け付ける
					cin >> menu;
					if(!menu.empty()){
						//受け付けた料理をファイルに書き込む処理
						fw.fileWriter(menu);
						//menulistを更新する
						fr.exchangeMenulist(menulist);
						cout <<"\n続けて追加するなら「1」を、メニューを決定するなら「5」を、追加を終了しアプリを閉じるなら「9」を入力してください。"<< endl;
					}else{
							cout << "正しく入力されませんでした。もう一度入力して下さい。" << endl;
				}
				break;
				}
				//5が選択された場合の処理
				case 5:
				{
					//乱数の初期値を設定
					rd.InitRand();
					//登録している料理の数に合わせて乱数を発生させる
					int resltRand = rd.random(menulist.size());
					cout << "今日のご飯は" << menulist[resltRand] << "です。" <<flush;


					//確認用のコードなので後で消す
					cout <<"要素は"<< resltRand  <<endl<< "料理の数は"<<menulist.size();


					cout <<"\nもう一度抽選を行うなら「5」を、アプリを終了するなら「9」を入力してください。"<< endl;
					break;
				}
				//9が選択された場合の処理
				case 9:
				{
					cout << "アプリを終了します。" << endl;
					judge = false;
					break;
				}
				default:
				{
					cout << "入力が正しくありません。\n追加するなら「1」を、メニューを決定するなら「5」を、アプリを終了するなら「9」を入力してください。" << endl;
					break;
				}
			}
		}
		else
		{
			cout << "半角数字で入力してください。"<<endl;
		}
	}
		return 0;
};
