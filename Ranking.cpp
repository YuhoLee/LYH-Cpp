// <Ranking.cpp>
#include "Ranking.h"
#define NUM_MVP 10				// 랭킹 크기
static PlayInfo MVP[NUM_MVP];	// 랭킹 배열
static int nMVP = NUM_MVP;		// 랭킹 인원 수

void initRanking() {	// 랭킹 초기값 설정
	PlayInfo noname = {"C++좋아요", 1000, 1000.0 };
	for (int i = 0; i < nMVP; i++)
		MVP[i] = noname;
}
void loadRanking(const char* fname) {	// 랭킹 불러오기
	FILE* fp = fopen(fname, "r");	// 읽기모드로 파일 열기
	if (fp == NULL) 
		initRanking();
	else {
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);	// 이진파일 읽어오기
		fclose(fp);
	}
}
void storeRanking(const char* fname) {	// 랭킹 저장하기
	FILE* fp = fopen(fname, "w");	// 쓰기모드로 파일 열기
	if (fp == NULL) return;
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);	// 이진파일에 저장하기
	fclose(fp);
	}
void printRanking() {	// 랭킹 출력하기
	printf("\n  <순위>   <소요시간>          <이름>       <이동횟수>\n\n");
	for (int i = 0; i < nMVP; i++)
		printf("  [%2d위]     %5.1f           %-16s %4d\n", i + 1, MVP[i].tElapsed, MVP[i].name, MVP[i].nMove);
}
int addRanking(int nMove, double tElap){	// 랭킹 추가하기
	if (tElap < MVP[nMVP - 1].tElapsed) {
	// 인수로 받은 값이 가장 순위가 낮은 값보다 작을 시(성적이 더 우수할 시)
		int pos = nMVP - 1;	// 가장 낮은 랭킹 부여
		for (; pos > 0; pos--) {
			if (tElap >= MVP[pos - 1].tElapsed) break; 
			// 더 우수한 랭킹 만났을 시 반복문 탈출
			MVP[pos] = MVP[pos - 1];
			// 아닐 시에는 만난 랭킹을 다음 순위로 미루기
		}
		MVP[pos].tElapsed = tElap;
		MVP[pos].nMove = nMove;
		printf("\n\n[%5.1f초] %d위 입니다. 이름을 입력하세요: ", tElap, pos + 1);
		scanf("%s", MVP[pos].name);
		getchar();
		return pos + 1;
	}
}