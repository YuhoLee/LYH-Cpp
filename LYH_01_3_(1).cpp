// 구구단 - 절차적 프로그램
#include <stdio.h>
int main(void) {
	int i = 1;
	int dan = 2; // 구구단변수(2부터 시작)  ex)3단에서 dan이 1증가 시 4단

	printf("[절차적 프로그래밍]\n");
	printf(" 구구단 2~9단\n\n");

loop: 
	for (i = 1; i <= 9; i++) 
		printf("%2d x %2d = %2d\n", dan, i, dan * i);
	printf("\n");

	if (dan < 9) {
	// dan이 9보다 작다고 해야 8일 때 조건문 안의 내용을 통해 1증가한 뒤
	// 루프로 가서 9단을 출력하고 조건문을 무시하여 빠져나올 수 있다.
		dan++;
		goto loop;
	}

	return 0;
}