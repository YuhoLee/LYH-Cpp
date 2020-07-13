// <SpeedSum.cpp>
#include "SpeedCalculate.h"
static int NumGames = 0;
static int NumWins = 0;
static double Score = 0;
extern double TotalTime;	// �ٸ� �ҽ����Ͽ� �ִ� TotalTime�� �������� ���� extern ���

static bool playSumOnce(int n) {
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