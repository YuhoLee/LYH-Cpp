#include <stdio.h>
int main(void) {
	int n;	// ���� �Է¿� ���Ǵ� ����
	int i;
	double val = 0;	// ���� ���� ���ϱ� ���� ���� �׿� �������ų� ������ ���� ����
	double PI = 0;	// ������ ����

	printf("���� n�� �Է��ϼ���: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("���� ���� �����Դϴ�.\n");
		return 0;
	}
	// 0 ������ ���ڸ� �Է��ϸ� ������� �ʵ��� ������

	for (i = 0; i <= n; i++) {
		val = 1.0 / (i * 2 + 1);	// 1/(2n+1)
		if ((i % 2) == 0)
			PI += val;
		// ¦���� �� PI���� val�� ���ϰ�
		else
			PI -= val;
		// Ȧ���� �� PI���� val�� ����.
	}

	PI = PI * 4;	// �������� �������� 4
	printf("PI�� �ٻ�: %lf", PI);
		
	return 0;
}