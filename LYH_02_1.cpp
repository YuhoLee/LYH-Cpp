// �й�: 2017136087 / ���ڸ� - 7 / 7 % 3 + 2 = 3 / (3)��
#include <stdio.h>
int main(void) {
	int i, j;	// �ݺ����� ���Ǵ� ����
	int n;	// ���� �Է¿� ���Ǵ� ����

	printf("������ �Է����ּ���: ");
	scanf_s("%d", &n);	// ���� �Է�

	for (i = n; i >= 1; i--) {	
	// �պ��� ������������ ����ؾ� �ϱ� ����
		for (j = 1; j < i ; j++)
			printf("  ");
		// ����(space) ���
		for (j = n; j >= i; j--)
			printf("%2d", j);
		// * ���
		printf("\n");
	}

	return 0;
}