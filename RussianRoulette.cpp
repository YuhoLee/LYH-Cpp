// <RussianRoulette.cpp>
#include "RussianRoulette.h"
void playRussianRoulette(int nRooms, int nTurns, int nBullets) {
	int nDead[50] = { 0 };
	// ���� ����� ��ȣ�� ���� �迭. �뷫 50����� �����ϵ��� ����
	int shooter = rand() % nTurns + 1;	// ���� �� ����� ���ʸ� ��ȣ�� �Ͽ� ������ �� ����
	printf("�Ѿ� ���� �Ϸ�. ������ �����մϴ�.\n");
	printf("%d������ �����Դϴ�.\n\n",shooter);
	while (nBullets != 0) {	
	// �Ѿ��� ��� ������ ������ ���� ����
		while (1) {
			while (shooter == nDead[shooter]) {
				shooter++;
				if (shooter == nTurns) shooter = 1;
			}
			// ������ �� ����� ��������̶�� ���� ���ʷ� �ѱ⵵�� �ϴ� �ڵ�

			int index = rand() % nRooms + 1;	// ��ź ����ŭ�� ������ ���� ����
			printf("[%d��]\tźâ�� �������� �����ϴ�.\n", shooter);
			printf("\tEnter Key�� ������ �ݹߵ˴ϴ�.");
			getchar();
			if (index <= nBullets) break;	// ������ ������ ���� �Ѿ� �������� �۰ų� ���Ƽ� �װԵǸ� �ݺ��� Ż��
			printf("\tö��...!! �������� ��ҽ��ϴ�!!\n\n");
			if (shooter == nTurns) shooter = 1;	// ������ ������� ������ ���� �Ǹ� �ٽ� ó������ ���ư����� ��
			else shooter++;
		}
		printf("\t����~~~~~~~~~~~%d���� �׾����ϴ�.\n\n", shooter);
		nBullets--;	// �Ѿ� ���� ����
		nDead[shooter] = shooter;	// ���� ��� �迭�� ���
		if (shooter == nTurns) shooter = 1;	
		else shooter++;
		// �׾ ���� ������� ����� �� �ֵ��� ��
	}
}
