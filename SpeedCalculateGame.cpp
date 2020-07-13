// <SpeedCalculateGame.cpp>
#include "SpeedCalculate.h"
double TotalTime = 0;	// 전역변수
int main(void) {
	int num;
	int nPlay = 10;
	double score = 0;
	srand((unsigned)time(NULL));

	printf("어서오세요! 계산나라에 오신것을 환영합니다~!!!\n\n");
	printf("========스피드계산 게임을 선택해주세요========\n");
	printf("\t1. 구구단 스피드 계산\n");
	printf("\t2. 두 자리수 곱셈 스피드 계산\n");
	printf("\t3. 세 자리수 덧셈문제 스피드 계산\n");
	printf("\t4. 네 자리수 덧셈문제 스피드 계산\n");
	printf("\t5. 다섯 자리수 덧셈문제 스피드 계산\n");
	printf("==============================================\n\n");
	printf("계산 게임 선택: ");
	scanf_s("%d", &num);
	if ((num >= 1 && num <= 5) == 0) {
		printf("선택하신 게임을 찾을 수 없습니다. 게임을 종료합니다.\n");
		return 0;
	}	// 5~6자리 수부터는 난수가 제대로 나오지 않음
		// 5자리 수는 제대로 나오는 수가 최대 4만 언저리까지 밖에 안나옴
		// 그래서 최대 5자리로 설정하였음
	printf("\n%2d번의 테스트 문제가 준비되었습니다.\n",nPlay);
	printf("시작 할 준비가 되었다면 엔터를 누르세요!!");
	getchar();	// 버퍼를 비우기 위한 getchar()
	getchar();	
	system("cls");	// 전에 출력되어있던 모든 것들을 지워버림

	if(num == 1)
		score = playSpeedGugu(nPlay);
	else if(num == 2)
		score = playSpeedMul(nPlay);
	else 
		score = playSpeedSum(nPlay, num);
	printf("\n점수 = %4.1f점(총 %4.1f초)\n", score, TotalTime);

	return 0;
}