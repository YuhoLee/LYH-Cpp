// ������ - ������ ���α׷�
#include <stdio.h>
int main(void) {
	int i = 1;
	int dan = 2; // �����ܺ���(2���� ����)  ex)3�ܿ��� dan�� 1���� �� 4��

	printf("[������ ���α׷���]\n");
	printf(" ������ 2~9��\n\n");

loop: 
	for (i = 1; i <= 9; i++) 
		printf("%2d x %2d = %2d\n", dan, i, dan * i);
	printf("\n");

	if (dan < 9) {
	// dan�� 9���� �۴ٰ� �ؾ� 8�� �� ���ǹ� ���� ������ ���� 1������ ��
	// ������ ���� 9���� ����ϰ� ���ǹ��� �����Ͽ� �������� �� �ִ�.
		dan++;
		goto loop;
	}

	return 0;
}