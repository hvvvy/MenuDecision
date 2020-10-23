#include <iostream>
#include <stdio.h>
#include <time.h>
#include "random.h"

using namespace std;


int main()
{

	CRandom rd;
	//乱数の初期値を設定
	rd.InitRand();

	//乱数を表示させる(仮）
    for(int i = 0; i < 20; i++)
        cout << rd.random() << ' ';
    cout << flush;

    return 0;
}
