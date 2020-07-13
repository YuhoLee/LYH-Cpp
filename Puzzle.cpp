// <Puzzle.cpp>
#include "Ranking.h"
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define DIM 3			// 퍼즐 크기
#define SHUFFLE 100		// 섞는횟수

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int DirKey[4] = { Left, Right, Up, Down };	
static int map[DIM][DIM];			// 퍼즐 맵
static int x, y;					// 빈칸의 위치 (행:y, 열:x)
static int nMove;					// 이동한 횟수
static clock_t tStart;				// 기준 시각
static int sRep[100] = { 0 };		// Shuffle의 움직임을 저장하는 배열
static int pRep[1000];				// 퍼즐을 플레이 할 때 움직임을 저장하는 배열
static double sTime[100] = { 0 };	// Shuffle의 움직임에 따른 시간을 저장하는 배열
static double pTime[1000];			// 퍼즐 플레이의 움직임에 따른시간을 저장하는 배열
static int cnt = 0;					// Shuffle 카운트변수
static int pMove;					// 퍼즐을 플레이 할 때 총 움직인 횟수
static int eMove = 0;				// 저장된 움직인 횟수
static double eTime = 0;			// 저장된 걸린 시간
static int emap[DIM][DIM];			// 저장된 퍼즐 맵
static int ex, ey;					// 저장된 빈칸 위치 (행:y 열:x)

static void init() {
// 게임 초기설정
	for (int i = 0; i < DIM * DIM - 1; i++)
		map[i / DIM][i % DIM] = i + 1;
	map[DIM - 1][DIM - 1] = 0;
	x = DIM - 1;
	y = DIM - 1;
	// map[0]부터 map[DIM*DIM-2]까지 1부터 DIM*DIM-1로 채움 
	srand((unsigned)time(NULL));
	tStart = clock();
	nMove = 0;
}
static void display(double s = -1.0) {	
// 현재의 퍼즐 상태와 이동횟수 및 소요시간 출력
	system("cls");
	printf("\tEightPuzzle\n\t");
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] > 0)
				printf("%3d", map[r][c]);
			else printf("   ");
		}
		printf("\n\t");
	}
	printf("-----------\n\t");
	clock_t t1 = clock();
	if (s == -1.0) {
	// display 함수가 인수로 아무것도 받지 않을 때
		s = (double)(t1 - tStart) / CLOCKS_PER_SEC;	// 시간 측정
		if (sTime[cnt - 1] == 0)	// 셔플 시
			sTime[cnt - 1] = s;
		else if (pTime[nMove - 1] == 0) 	// 셔플이 끝나고 플레이 시
			pTime[nMove - 1] = s + eTime;
	}
	if (s == 0) {	// 초기화면 시
		printf("\n\t이동 횟수:%6d회\n\t소요 시간:%6.1f초\n\n", 0.0,0.0);
		return;
	}
	printf("\n\t이동 횟수:%6d회\n\t소요 시간:%6.1f초\n\n", nMove, s + eTime);
}
static bool move(int dir) {
// map을 움직여서 퍼즐 상태를 바꿈
	if (dir == Right && x > 0) {
	// 오른쪽 화살표를 눌렀을 때 빈칸이 0번째 열에 있지 않다면 
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM - 1) {
	// 왼쪽 화살표를 눌렀을 때 빈칸이 (DIM-1)번째 열에 있지 않다면 
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM - 1) {
	// 위쪽 화살표를 눌렀을 때 빈칸이 (DIM-1)번째 행에 있지 않다면 
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir == Down && y > 0) {
	// 아래쪽 화살표를 눌렀을 때 빈칸이 0번째 행에 있지 않다면
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else return false;	// 모두 아니면 false 반환

	nMove++;	// 움직임 1증가
	return true;	
	// else의 false반환을 거치지 않고 잘 움직였으면 true반환
}
static void shuffle(int nShuffle) {
// 퍼즐을 섞음
	tStart = clock();
	for (int i = 0; i < nShuffle; i++) {
		int key = DirKey[rand() % 4];
		if (move(key) == false) { i--; continue; }
		cnt++;	// 의미있는 움직임의 Shuffle에 대해 
				// Shuffle의 리플레이 카운트변수 1증가
		sRep[cnt - 1] = key;	// Shuffle의 움직임 추가
		display();	
		Sleep(10);
	}
}
static bool isDone() {
// 퍼즐이 완성되었는지 확인
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] != r * DIM + c + 1)
				return (r == DIM - 1) && (c == DIM - 1);
		}
	}
	return true;
}
static int replay() {
// 리플레이
	char alp;
	while (true) {
		printf("\n리플레이를 보시겠습니까?(Y/N): ");
		scanf("%c", &alp);
		getchar();
		if (alp == 'Y' || alp == 'y') {
			tStart = clock();
			nMove = 0;
			eTime = 0;
			printf("\n\n퍼즐을 섞는 과정을 리플레이 하겠습니다. 엔터를 눌러주십시오... ");
			_getche();
			for (int i = 0; i < SHUFFLE; i++) {
				move(sRep[i]);
				display(sTime[i]);
				Sleep(10);
			}
			// Shuffle과 똑같이 움직이고
			// Shuffle의 움직임에 따른 시간을 똑같이 출력

			printf("\n\n퍼즐을 완성하는 과정을 리플레이 하겠습니다. 엔터를 눌러주십시오... ");
			_getche();
			nMove = 0;

			for (int i = 0; i < pMove; i++) {
				move(pRep[i]);
				display(pTime[i]);
				Sleep(10);
			}
			// 퍼즐 플레이 시와 똑같이 움직이고
			// 퍼즐 플레이 할 때의 움직임에 따른 시간을 똑같이 출력
			return pMove;
		}
		else if (alp == 'N' || alp == 'n')
			return nMove;
		else 
			printf("Y/N이 아닌 다른 키입니다. 다시 입력해주십시오.\n\n");
	}
}
static void storePuzzle() {
// 퍼즐 저장
	eMove = nMove;	// 플레이 시 움직인 횟수 저장
	eTime = pTime[nMove - 1];	// 현재까지의 시간 저장
	ex = x;	
	ey = y;
	// 빈칸 위치 저장
	for (int i = 0; i < DIM; i++) 
		for (int j = 0; j < DIM; j++)
			emap[i][j] = map[i][j];
	// 퍼즐 저장
	printf("\n\n------------------저장되었습니다------------------\n");
	Sleep(1000);
}
static bool loadPuzzle() {
// 퍼즐 불러오기
	char alp;
	if (eMove + eTime != 0) {
		// eMove나 eTime이 초기값(0)이 아닐 시
		while (true) {
			printf("\n저장된 게임 기록이 있습니다. 불러오시겠습니까?(Y/N): ");
			scanf("%c", &alp);
			getchar();
			if (alp == 'Y' || alp == 'y') {
				for (int i = 0; i < DIM; i++)
					for (int j = 0; j < DIM; j++)
						map[i][j] = emap[i][j];	// 퍼즐 불러오기
				nMove = eMove;	// 움직인 횟수 불러오기
				x = ex;
				y = ey;
				// 빈칸 위치 불러오기
				return true;
			}

			else if (alp == 'N' || alp == 'n') {
				printf("\n\n게임을 불러오지 않았습니다. 새로 시작해주시기 바랍니다.\n");
				exit(1);
			}
			else
				printf("Y/N이 아닌 다른 키입니다. 다시 입력해주십시오.\n\n");
		}
	}
	return false;
}
static int getDirKey() { return _getche() == 224 ? _getch() : 0; }
int playPuzzle() {
// 퍼즐 플레이
loop1:
	init();
	display(0);		// 초기화면
	printRanking();	// 현재 랭킹 출력
	if(loadPuzzle())
		goto loop2;	// 저장된 퍼즐로 돌아가기
	printf("\n 퍼즐을 섞어주세요(엔터)...");
	_getche();
	shuffle(SHUFFLE);
	printf("\n게임이 시작됩니다(엔터)...");
	_getche();
	nMove = 0;
loop2:
	tStart = clock();
	display();
	printf("\n저장을 원하시면 방향키를 제외한 아무 키나 눌러주세요.");
	while (!isDone()) {
	// 퍼즐이 완성될 때까지
		int s;
		s = getDirKey();
		if (s == 0) {
			storePuzzle();	// 퍼즐 저장
			goto loop1;	// 초기 화면으로 돌아가기
		}
		if (move(s)) {
			pRep[nMove - 1] = s;
			pMove++;	
		}	// 퍼즐 플레이의 움직임이 의미있을 시
			// 퍼즐 리플레이 배열에 움직임 추가 후 움직인 횟수 1증가
		display();
		printf("\n저장을 원하시면 방향키를 제외한 아무 키나 눌러주세요.");
	}
	return addRanking(pMove, pTime[pMove - 1]);
}
int main(void) {
	initRanking();
	loadRanking("ranking.bin");
	playPuzzle();
	storeRanking("ranking.bin");
	replay();
}