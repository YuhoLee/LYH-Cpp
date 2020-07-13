// 구구단 - 구조적 프로그래밍
#include <stdio.h>
void printGuguDan(int dan) { 
// 해당 단의 내용들을 출력하는 함수
	for (int i = 1; i <= 9; i++) 
		printf("%2d x %2d = %2d\n", dan, i, dan * i); 
	printf("\n");
}

int main(void) {
	printf("[구조적 프로그래밍]\n");
	printf(" 구구단 2~9단\n\n");

	for (int rep = 2; rep <= 9; rep++)
	// 2단부터 시작이기에 시작을 2로 설정
		printGuguDan(rep);
		// printGuguDan 함수 호출

	return 0;
}