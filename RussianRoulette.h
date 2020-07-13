// <RussianRoulette.h>
// 공통적으로 쓰이는 부분을 헤더파일을 생성하여 다른 소스 파일에서도 쓸 수 있도록 함
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern void playRussianRoulette(int nRooms = 6, int nTurns = 2, int nBullets = 1);
// 함수 원형 정의
// 원래 있던 함수가 아닌 원형에서 각 인수에 디폴트값을 주었음
