// <RussianRoulette.cpp>
#include "RussianRoulette.h"
void playRussianRoulette(int nRooms, int nTurns, int nBullets) {
	int nDead[50] = { 0 };
	// 죽은 사람의 번호가 들어가는 배열. 대략 50명까지 가능하도록 설정
	int shooter = rand() % nTurns + 1;	// 총을 쏠 사람의 차례를 번호로 하여 무작위 값 설정
	printf("총알 장전 완료. 게임을 시작합니다.\n");
	printf("%d번부터 시작입니다.\n\n",shooter);
	while (nBullets != 0) {	
	// 총알이 모두 소진될 때까지 게임 진행
		while (1) {
			while (shooter == nDead[shooter]) {
				shooter++;
				if (shooter == nTurns) shooter = 1;
			}
			// 순서가 온 사람이 죽은사람이라면 다음 차례로 넘기도록 하는 코드

			int index = rand() % nRooms + 1;	// 장탄 수만큼의 무작위 값을 설정
			printf("[%d번]\t탄창을 무작위로 돌립니다.\n", shooter);
			printf("\tEnter Key를 누르면 격발됩니다.");
			getchar();
			if (index <= nBullets) break;	// 설정한 무작위 값이 총알 개수보다 작거나 같아서 죽게되면 반복문 탈출
			printf("\t철컥...!! 다행히도 살았습니다!!\n\n");
			if (shooter == nTurns) shooter = 1;	// 마지막 사람까지 순서가 가게 되면 다시 처음으로 돌아가도록 함
			else shooter++;
		}
		printf("\t빵야~~~~~~~~~~~%d번이 죽었습니다.\n\n", shooter);
		nBullets--;	// 총알 개수 감소
		nDead[shooter] = shooter;	// 죽은 사람 배열에 등록
		if (shooter == nTurns) shooter = 1;	
		else shooter++;
		// 죽어도 다음 사람으로 진행될 수 있도록 함
	}
}
