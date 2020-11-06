#include <cassert>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

#include "fileWriter.h"
#include "fileReader.h"
#include "random.h"
#include "check.h"


using namespace std;


int main()
{
	CFileWriter fw;
	CFileReader fr;
	CRandom rd;
	CCheck ck;

	vector<string> menulist;
	string choice;
	string menu;
	string allMenu;
	int iChoice;
	int resltRand;
	int rbuf;
	char yn;
	bool judge = true;
	bool fileExists;

	cout << "メニューを登録する場合は「1」を、抽選を開始する場合は「5」を、"
			"現在登録されているメニューを確認する場合は「6」を入力してください。";

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
			iChoice = stoi(choice);
			//数字でその後の処理を選択
			switch(iChoice){
				//0が選択された場合
				//ファイル削除処理
				case 0:
				{
					cout << "本当にリセットしますか？\n(y/n)" << endl;
					cin >> yn;
					if(yn == 'y')
					{
						//menu.txtの削除
						remove("C:\\temp\\menu.txt");
						menulist.clear();
						cout << "リセットしました。" << endl;
					}else
					{
						cout << "キャンセルされました。" << endl;
					}
					cout <<"\n続けて登録する場合は「1」を、"
							"抽選を開始する場合は「5」を、\n"
							"現在登録されているメニューの一覧を確認する場合は「6」を、"
							"アプリを終了する場合は「9」を入力してください。"<< endl;
					break;
				}
				//1が選択された場合の処理
				//登録処理
				case 1:
				{
					cout << "料理を登録してください。";
					//入力した料理を受け付ける
					cin >> menu;
					if(!menu.empty())
					{
						//受け付けた料理をファイルに書き込む処理
						fw.fileWriter(menu,ck.checkEmpty());
						//menulistを更新する
						fr.exchangeMenulist(menulist);
						cout <<"\n続けて登録する場合は「1」を、"
								"抽選を開始する場合は「5」を、\n"
								"現在登録されているメニューの一覧を確認する場合は「6」を、"
								"アプリを終了する場合は「9」を入力してください。"<< endl;
					}else
					{
							cout << "正しく入力されませんでした。もう一度入力して下さい。" << endl;
					}

				break;
				}
				//5が選択された場合の処理
				//抽選処理
				case 5:
				{
					//乱数の初期値を設定
					rd.InitRand();
					//抽選結果を重複させない処理
					do
					{
						//登録している料理の数に合わせて乱数を発生させる
						resltRand = rd.random(menulist.size());
					}
					while(rbuf == resltRand);
					//発生させた乱数を一時的にrbufに格納
					rbuf = resltRand;

					cout << "今日のご飯は" << menulist[resltRand] << "です。" <<flush;
					cout <<"\nもう一度抽選を行う場合は「5」を、アプリを終了する場合は「9」を入力してください。"<< endl;

					break;
				}
				//6が選択された場合の処理
				//一括表示処理
				case 6:
				{
					cout << fr.allMenuReader(allMenu,fileExists) << endl;
					if(fileExists)
					{
						cout << "メニューの一覧を表示します。" << endl;
						//メニューの総数を表示
						cout << "現在登録されているメニューの総数は"<<menulist.size() << endl;
					}

					break;
				}
				//9が選択された場合の処理
				//プログラムの終了処理
				case 9:
				{
					cout << "アプリを終了します。" << endl;
					judge = false;
					break;
				}
				default:
				{
					cout << "入力が正しくありません。\n追加する場合は「1」を、抽選を開始する場合は「5」を、\n"
							"現在登録されているメニューの一覧を確認する場合は「6」を、"
							"アプリを終了する場合は「9」を入力してください。" << endl;

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
