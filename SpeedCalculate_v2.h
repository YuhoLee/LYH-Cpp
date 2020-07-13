// <SpeedCalculate.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

class SpeedCalculate {
	int NumGames = 0;
	int NumWins = 0;
	double Score = 0;
	double TotalTime = 0;


	bool playGuguOnce() {
		int a = rand() % 8 + 2;	// 2 ~ 9의 난수 발생
		int b = rand() % 8 + 2;	// 2 ~ 9의 난수 발생
		int result;

		NumGames++;
		printf("[문제%2d]: %d X %d = ", NumGames, a, b);
		scanf_s("%d", &result);
		if (result == (a * b)) NumWins++;
		return (result == (a * b));
	}

	bool playMulOnce() {
		int a = rand() % 90 + 10;	// 10 ~ 99의 난수 발생
		int b = rand() % 90 + 10;	// 10 ~ 99의 난수 발생
		int result;

		NumGames++;
		printf("[문제%2d]: %d X %d = ", NumGames, a, b);
		scanf_s("%d", &result);
		if (result == a * b) NumWins++;
		return (result == a * b);
	}

	bool playSumOnce(int n) {
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

public:
	SpeedCalculate() {};
	double getTotalTime() {
		return TotalTime;
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

	double playSpeedMul(int nPlay) {
		clock_t t0 = clock();	// 시간의 시작  
		for (int i = 0; i < nPlay; i++) {
			if (playMulOnce() == false)
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
};
