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
		int a = rand() % 8 + 2;	// 2 ~ 9�� ���� �߻�
		int b = rand() % 8 + 2;	// 2 ~ 9�� ���� �߻�
		int result;

		NumGames++;
		printf("[����%2d]: %d X %d = ", NumGames, a, b);
		scanf_s("%d", &result);
		if (result == (a * b)) NumWins++;
		return (result == (a * b));
	}

	bool playMulOnce() {
		int a = rand() % 90 + 10;	// 10 ~ 99�� ���� �߻�
		int b = rand() % 90 + 10;	// 10 ~ 99�� ���� �߻�
		int result;

		NumGames++;
		printf("[����%2d]: %d X %d = ", NumGames, a, b);
		scanf_s("%d", &result);
		if (result == a * b) NumWins++;
		return (result == a * b);
	}

	bool playSumOnce(int n) {
		int s = pow(10, n) * 0.9;
		int a = rand() % s + pow(10, n - 1);	// 10^(n-1) ~ (10^n - 1)�� ���� �߻� (n�� �ڸ���)
		int b = rand() % s + pow(10, n - 1);	// 10^(n-1) ~ (10^n - 1)�� ���� �߻� (n�� �ڸ���)
		int result;

		NumGames++;
		printf("[����%2d]: %d + %d = ", NumGames, a, b);
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
		clock_t t0 = clock();	// �ð��� ����
		for (int i = 0; i < nPlay; i++) {
			if (playGuguOnce() == false)
				printf("\tƲ�Ƚ��ϴ�.\n");
		}
		clock_t t1 = clock();	// �ð��� ��
		TotalTime = (double)(t1 - t0) / CLOCKS_PER_SEC;	// �������� �ð� - ���ۿ����� �ð� = �ɸ� �ð�
		Score = (NumGames > NumWins) ? 0.0
			: 100 * (5.0 * NumGames - TotalTime) / (5.0 * NumGames);
		if (Score < 0.0)
			Score = 0;
		return Score;
	}

	double playSpeedMul(int nPlay) {
		clock_t t0 = clock();	// �ð��� ����  
		for (int i = 0; i < nPlay; i++) {
			if (playMulOnce() == false)
				printf("\tƲ�Ƚ��ϴ�.\n");
		}
		clock_t t1 = clock();	// �ð��� ��
		TotalTime = (double)(t1 - t0) / CLOCKS_PER_SEC;	// �������� �ð� - ���ۿ����� �ð� = �ɸ� �ð�
		Score = (NumGames > NumWins) ? 0.0
			: 100 * (5.0 * NumGames - TotalTime) / (5.0 * NumGames);
		if (Score < 0.0)
			Score = 0;
		return Score;
	}

	double playSpeedSum(int nPlay, int n) {
		clock_t t0 = clock();	// �ð��� ����
		for (int i = 0; i < nPlay; i++) {
			if (playSumOnce(n) == false)
				printf("\tƲ�Ƚ��ϴ�.\n");
		}
		clock_t t1 = clock();	// �ð��� ��
		TotalTime = (double)(t1 - t0) / CLOCKS_PER_SEC;	// �������� �ð� - ���ۿ����� �ð� = �ɸ� �ð�
		Score = (NumGames > NumWins) ? 0.0
			: 100 * (5.0 * NumGames - TotalTime) / (5.0 * NumGames);
		if (Score < 0.0)
			Score = 0;
		return Score;
	}
};
