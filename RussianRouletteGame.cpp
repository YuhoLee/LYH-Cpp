// <RussianRouletteGame.cpp>
#include "RussianRoulette.h"
int main(void) {
	int nRooms, nTurns, nBullets;
	srand((unsigned)time(NULL));	// rand()�� �ð��� ���� ������ ������ ����
	printf("���� ����Ƚ�� �Է�: ");
	scanf_s("%d", &nRooms);
	printf("���� �ο�: ");
	scanf_s("%d", &nTurns);
	printf("�Ѿ� ����: ");
	scanf_s("%d", &nBullets);
	getchar();	// ���������� ���ۿ� ���Ͱ� �ԷµǾ� ���۸� ���� ����

	playRussianRoulette(nRooms, nTurns, nBullets);	// ���� �÷��� �Լ� ����

	return 0;

}