#include <stdio.h>
int main(void) {
	int n;	// 정수 입력에 사용되는 변수
	int i;
	double val = 0;	// 현재 항을 구하기 위해 이전 항에 더해지거나 빼지는 값의 변수
	double PI = 0;	// 원주율 변수

	printf("정수 n을 입력하세요: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("범위 밖의 숫자입니다.\n");
		return 0;
	}
	// 0 이하의 숫자를 입력하면 실행되지 않도록 제어함

	for (i = 0; i <= n; i++) {
		val = 1.0 / (i * 2 + 1);	// 1/(2n+1)
		if ((i % 2) == 0)
			PI += val;
		// 짝수일 때 PI에서 val을 더하고
		else
			PI -= val;
		// 홀수일 때 PI에서 val을 뺀다.
	}

	PI = PI * 4;	// 마지막에 곱해지는 4
	printf("PI의 근삿값: %lf", PI);
		
	return 0;
}