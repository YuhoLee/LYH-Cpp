// <SpeedGugu.cpp>
#include "SpeedCalculate.h"
static int NumGames = 0;
static int NumWins = 0;
static double Score = 0;
extern double TotalTime;	// 다른 소스파일에 있는 TotalTime을 가져오기 위해 extern 사용

static bool playGuguOnce() {
	int a = rand() % 8 + 2;	// 2 ~ 9의 난수 발생
	int b = rand() % 8 + 2;	// 2 ~ 9의 난수 발생
	int result;

	NumGames++;
	printf("[문제%2d]: %d X %d = ", NumGames, a, b);
	scanf_s("%d", &result);
	if (result == (a * b)) NumWins++;
	return (result == (a * b));
}

double playSpeedGugu(int nPlay) {
	clock_t t0 = clock();	// 시간의 시작
	for (int i = 0; i < nPlay; i++) {
		if (playGuguOnce() == false)
			printf("\t틀렸습니다.\n");
	}
	clock_t t1 = clock();	// 시간의 끝
	TotalTime = (double)(t1 - t0) / CLOCKS_PER_SEC;	// 끝에서의 시간 - 시작에서의 시간 = 걸린 시간
	Score = (NumGames > NumWins) ? 0.0
		: 100 * (5.0 * NumGames - TotalTime) / (5.0 * NumGames);
	if (Score < 0.0)
		Score = 0;
	return Score;
}