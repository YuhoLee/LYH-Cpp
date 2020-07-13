// <SpeedCalculateGame.cpp>
#include "SpeedCalculate.h"
double TotalTime = 0;	// ��������
int main(void) {
	int num;
	int nPlay = 10;
	double score = 0;
	srand((unsigned)time(NULL));

	printf("�������! ��곪�� ���Ű��� ȯ���մϴ�~!!!\n\n");
	printf("========���ǵ��� ������ �������ּ���========\n");
	printf("\t1. ������ ���ǵ� ���\n");
	printf("\t2. �� �ڸ��� ���� ���ǵ� ���\n");
	printf("\t3. �� �ڸ��� �������� ���ǵ� ���\n");
	printf("\t4. �� �ڸ��� �������� ���ǵ� ���\n");
	printf("\t5. �ټ� �ڸ��� �������� ���ǵ� ���\n");
	printf("==============================================\n\n");
	printf("��� ���� ����: ");
	scanf_s("%d", &num);
	if ((num >= 1 && num <= 5) == 0) {
		printf("�����Ͻ� ������ ã�� �� �����ϴ�. ������ �����մϴ�.\n");
		return 0;
	}	// 5~6�ڸ� �����ʹ� ������ ����� ������ ����
		// 5�ڸ� ���� ����� ������ ���� �ִ� 4�� ���������� �ۿ� �ȳ���
		// �׷��� �ִ� 5�ڸ��� �����Ͽ���
	printf("\n%2d���� �׽�Ʈ ������ �غ�Ǿ����ϴ�.\n",nPlay);
	printf("���� �� �غ� �Ǿ��ٸ� ���͸� ��������!!");
	getchar();	// ���۸� ���� ���� getchar()
	getchar();	
	system("cls");	// ���� ��µǾ��ִ� ��� �͵��� ��������

	if(num == 1)
		score = playSpeedGugu(nPlay);
	else if(num == 2)
		score = playSpeedMul(nPlay);
	else 
		score = playSpeedSum(nPlay, num);
	printf("\n���� = %4.1f��(�� %4.1f��)\n", score, TotalTime);

	return 0;
}