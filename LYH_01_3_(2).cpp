// ������ - ������ ���α׷���
#include <stdio.h>
void printGuguDan(int dan) { 
// �ش� ���� ������� ����ϴ� �Լ�
	for (int i = 1; i <= 9; i++) 
		printf("%2d x %2d = %2d\n", dan, i, dan * i); 
	printf("\n");
}

int main(void) {
	printf("[������ ���α׷���]\n");
	printf(" ������ 2~9��\n\n");

	for (int rep = 2; rep <= 9; rep++)
	// 2�ܺ��� �����̱⿡ ������ 2�� ����
		printGuguDan(rep);
		// printGuguDan �Լ� ȣ��

	return 0;
}