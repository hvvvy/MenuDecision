#include "random.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void CRandom::InitRand()
{
	srand((unsigned int)time(NULL));
}

int CRandom::random()
{
	return rand() % 6 + 1;
}
