#ifndef RANDOM_H_
#define RANDOM_H_

#include "random.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

class CRandom{

public:
	//インライン関数
	inline void InitRand()
	{
		//システム内の時間を基に初期化
		srand((unsigned int)time(NULL));
	}
	//インライン関数
	 inline int random(int size)
	 {
	 	return rand() % size;
	 }
};


#endif /* RANDOM_H_ */
