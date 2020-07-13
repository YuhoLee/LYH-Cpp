// <RussianRouletteGame.cpp>
#include "RussianRoulette.h"
int main(void) {
	int nRooms, nTurns, nBullets;
	srand((unsigned)time(NULL));	// rand()를 시간에 따른 무작위 값으로 설정
	printf("권총 연발횟수 입력: ");
	scanf_s("%d", &nRooms);
	printf("게임 인원: ");
	scanf_s("%d", &nTurns);
	printf("총알 개수: ");
	scanf_s("%d", &nBullets);
	getchar();	// 마지막으로 버퍼에 엔터가 입력되어 버퍼를 비우기 위함

	playRussianRoulette(nRooms, nTurns, nBullets);	// 게임 플레이 함수 시작

	return 0;

}