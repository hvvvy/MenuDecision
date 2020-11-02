#include "random.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void CRandom::InitRand()
{
	//システム内の時間を基に初期化
	srand((unsigned int)time(NULL));
}

int CRandom::random(int size)
{
	return rand() % size;
}
