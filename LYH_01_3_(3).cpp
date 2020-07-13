// 구구단 - 객체지향 프로그래밍
#include <stdio.h>
class GuguGame {
private:
	// 멤버변수(필드), 캡슐화를 위해 private에 선언하여 함부로 접근할 수 없도록 함.
	int from;
	int to;

public:
	GuguGame() {
		set(); 
	}
	// 생성자
	~GuguGame() {
	}
	// 소멸자

	int getFrom() {
	// from 설정자
		return from;
	}

	int getTo() {
	// to 설정자
		return to;
	}

	void set(int f = 2, int t = 9) {
	// 멤버변수 접근자 - 단의 범위를 설정
		if ((f >= 2) && (t >= 2)) {
			from = f;
			to = t;
		}
		else {
			printf("구구단의 단을 2미만으로 설정할 수 없습니다. 기본값으로 설정하겠습니다.\n");
			from = 2;
			to = 9;
		}

		if (f > t) {
			printf("구구단의 범위가 잘못되었습니다. 기본값으로 설정하겠습니다.\n");
			from = 2;
			to = 9;
		}
	}
	// 단의 처음과 끝이 2보다 작은 수로 설정되거나 처음이 끝보다 클 때, 기본값인 2단 ~ 9단으로 설정 

	void printGugudan() {
		//구구단을 네 단씩 끊어서 출력하는 클래스 내부 메소드 
		int t = 1;	// 네 단씩 끊어서 출력해야 하기 때문에 4번을 세주는 카운트 변수
		int n = from;	// 현재 단 수
		int cnt = 0;	// 현재 끊은 횟수
		int max_cnt = (to - from) / 4; // 최대 끊을 횟수를 정하는 변수

		printf(" 구구단 %d~%d단\n", from, to);

		while (cnt <= max_cnt) {
		// 네 단씩 최대로 끊을 때 까지
			for (int i = 1; i <= 9; i++) {
			// 단에 곱해지는 수들, 1부터 9까지로 설정하였음
				printf("\n");
				while (1) {
				// 반복문
					printf("%2d x %2d = %2d    ", n, i, n * i);
					if ((t % 4)!=0 && (n < to)) {
					// 카운트 횟수가 4번이 안되었고, 현재 단이 단의 끝보다 작을 때 
						t++;
						n++;
						// 카운트 횟수와 현재 단을 하나씩 더해줌
					}
					else {
					// 카운트 횟수가 4번이 되었고, 현재 단이 단의 끝보다 크거나 같을 때
						t = 1;
						n = from + (4 * cnt);
						break;
						// 카운트 횟수 초기화 및 네 단의 첫단으로 이동. 
					}
				}
			}
			cnt++;	
			printf("\n");
			n += 4;
			// 네 단을 출력한 뒤, 한번 끊어주고 다음 단 출력을 위해 n에 4를 더함
		}
		printf("\n");

	}
};

int main(void) {
	printf("[객체지향 프로그래밍]\n");
	GuguGame g;		// 객체 g 생성
	g.set(2, 9);	// 2단 ~ 9단
	g.printGugudan();
	printf("\n");
	g.set(3, 7);	// 4단 ~ 7단
	g.printGugudan();

	return 0;
}