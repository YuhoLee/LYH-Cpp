// <SpeedSum.cpp>
#include "SpeedCalculate.h"
static int NumGames = 0;
static int NumWins = 0;
static double Score = 0;
extern double TotalTime;	// 다른 소스파일에 있는 TotalTime을 가져오기 위해 extern 사용

static bool playSumOnce(int n) {
	int s = pow(10, n) * 0.9;
	int a = rand() % s + pow(10, n - 1);	// 10^(n-1) ~ (10^n - 1)의 난수 발생 (n은 자리수)
	int b = rand() % s + pow(10, n - 1);	// 10^(n-1) ~ (10^n - 1)의 난수 발생 (n은 자리수)
	int result;

	NumGames++;
	printf("[문제%2d]: %d + %d = ", NumGames, a, b);
	scanf_s("%d", &result);
	if (result == (a + b)) NumWins++;
	return (result == (a + b));
}

double playSpeedSum(int nPlay, int n) {
	clock_t t0 = clock();	// 시간의 시작
	for (int i = 0; i < nPlay; i++) {
		if (playSumOnce(n) == false)
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