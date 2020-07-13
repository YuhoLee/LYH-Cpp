// 학번: 2017136087 / 끝자리 - 7 / 7 % 3 + 2 = 3 / (3)번
#include <stdio.h>
int main(void) {
	int i, j;	// 반복문에 사용되는 변수
	int n;	// 정수 입력에 사용되는 변수

	printf("정수를 입력해주세요: ");
	scanf_s("%d", &n);	// 정수 입력

	for (i = n; i >= 1; i--) {	
	// 앞부터 내림차순으로 출력해야 하기 위함
		for (j = 1; j < i ; j++)
			printf("  ");
		// 공백(space) 출력
		for (j = n; j >= i; j--)
			printf("%2d", j);
		// * 출력
		printf("\n");
	}

	return 0;
}