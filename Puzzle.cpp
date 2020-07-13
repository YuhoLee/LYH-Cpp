// <Puzzle.cpp>
#include "Ranking.h"
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define DIM 3			// ���� ũ��
#define SHUFFLE 100		// ����Ƚ��

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int DirKey[4] = { Left, Right, Up, Down };	
static int map[DIM][DIM];			// ���� ��
static int x, y;					// ��ĭ�� ��ġ (��:y, ��:x)
static int nMove;					// �̵��� Ƚ��
static clock_t tStart;				// ���� �ð�
static int sRep[100] = { 0 };		// Shuffle�� �������� �����ϴ� �迭
static int pRep[1000];				// ������ �÷��� �� �� �������� �����ϴ� �迭
static double sTime[100] = { 0 };	// Shuffle�� �����ӿ� ���� �ð��� �����ϴ� �迭
static double pTime[1000];			// ���� �÷����� �����ӿ� �����ð��� �����ϴ� �迭
static int cnt = 0;					// Shuffle ī��Ʈ����
static int pMove;					// ������ �÷��� �� �� �� ������ Ƚ��
static int eMove = 0;				// ����� ������ Ƚ��
static double eTime = 0;			// ����� �ɸ� �ð�
static int emap[DIM][DIM];			// ����� ���� ��
static int ex, ey;					// ����� ��ĭ ��ġ (��:y ��:x)

static void init() {
// ���� �ʱ⼳��
	for (int i = 0; i < DIM * DIM - 1; i++)
		map[i / DIM][i % DIM] = i + 1;
	map[DIM - 1][DIM - 1] = 0;
	x = DIM - 1;
	y = DIM - 1;
	// map[0]���� map[DIM*DIM-2]���� 1���� DIM*DIM-1�� ä�� 
	srand((unsigned)time(NULL));
	tStart = clock();
	nMove = 0;
}
static void display(double s = -1.0) {	
// ������ ���� ���¿� �̵�Ƚ�� �� �ҿ�ð� ���
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
	// display �Լ��� �μ��� �ƹ��͵� ���� ���� ��
		s = (double)(t1 - tStart) / CLOCKS_PER_SEC;	// �ð� ����
		if (sTime[cnt - 1] == 0)	// ���� ��
			sTime[cnt - 1] = s;
		else if (pTime[nMove - 1] == 0) 	// ������ ������ �÷��� ��
			pTime[nMove - 1] = s + eTime;
	}
	if (s == 0) {	// �ʱ�ȭ�� ��
		printf("\n\t�̵� Ƚ��:%6dȸ\n\t�ҿ� �ð�:%6.1f��\n\n", 0.0,0.0);
		return;
	}
	printf("\n\t�̵� Ƚ��:%6dȸ\n\t�ҿ� �ð�:%6.1f��\n\n", nMove, s + eTime);
}
static bool move(int dir) {
// map�� �������� ���� ���¸� �ٲ�
	if (dir == Right && x > 0) {
	// ������ ȭ��ǥ�� ������ �� ��ĭ�� 0��° ���� ���� �ʴٸ� 
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM - 1) {
	// ���� ȭ��ǥ�� ������ �� ��ĭ�� (DIM-1)��° ���� ���� �ʴٸ� 
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM - 1) {
	// ���� ȭ��ǥ�� ������ �� ��ĭ�� (DIM-1)��° �࿡ ���� �ʴٸ� 
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir == Down && y > 0) {
	// �Ʒ��� ȭ��ǥ�� ������ �� ��ĭ�� 0��° �࿡ ���� �ʴٸ�
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else return false;	// ��� �ƴϸ� false ��ȯ

	nMove++;	// ������ 1����
	return true;	
	// else�� false��ȯ�� ��ġ�� �ʰ� �� ���������� true��ȯ
}
static void shuffle(int nShuffle) {
// ������ ����
	tStart = clock();
	for (int i = 0; i < nShuffle; i++) {
		int key = DirKey[rand() % 4];
		if (move(key) == false) { i--; continue; }
		cnt++;	// �ǹ��ִ� �������� Shuffle�� ���� 
				// Shuffle�� ���÷��� ī��Ʈ���� 1����
		sRep[cnt - 1] = key;	// Shuffle�� ������ �߰�
		display();	
		Sleep(10);
	}
}
static bool isDone() {
// ������ �ϼ��Ǿ����� Ȯ��
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] != r * DIM + c + 1)
				return (r == DIM - 1) && (c == DIM - 1);
		}
	}
	return true;
}
static int replay() {
// ���÷���
	char alp;
	while (true) {
		printf("\n���÷��̸� ���ðڽ��ϱ�?(Y/N): ");
		scanf("%c", &alp);
		getchar();
		if (alp == 'Y' || alp == 'y') {
			tStart = clock();
			nMove = 0;
			eTime = 0;
			printf("\n\n������ ���� ������ ���÷��� �ϰڽ��ϴ�. ���͸� �����ֽʽÿ�... ");
			_getche();
			for (int i = 0; i < SHUFFLE; i++) {
				move(sRep[i]);
				display(sTime[i]);
				Sleep(10);
			}
			// Shuffle�� �Ȱ��� �����̰�
			// Shuffle�� �����ӿ� ���� �ð��� �Ȱ��� ���

			printf("\n\n������ �ϼ��ϴ� ������ ���÷��� �ϰڽ��ϴ�. ���͸� �����ֽʽÿ�... ");
			_getche();
			nMove = 0;

			for (int i = 0; i < pMove; i++) {
				move(pRep[i]);
				display(pTime[i]);
				Sleep(10);
			}
			// ���� �÷��� �ÿ� �Ȱ��� �����̰�
			// ���� �÷��� �� ���� �����ӿ� ���� �ð��� �Ȱ��� ���
			return pMove;
		}
		else if (alp == 'N' || alp == 'n')
			return nMove;
		else 
			printf("Y/N�� �ƴ� �ٸ� Ű�Դϴ�. �ٽ� �Է����ֽʽÿ�.\n\n");
	}
}
static void storePuzzle() {
// ���� ����
	eMove = nMove;	// �÷��� �� ������ Ƚ�� ����
	eTime = pTime[nMove - 1];	// ��������� �ð� ����
	ex = x;	
	ey = y;
	// ��ĭ ��ġ ����
	for (int i = 0; i < DIM; i++) 
		for (int j = 0; j < DIM; j++)
			emap[i][j] = map[i][j];
	// ���� ����
	printf("\n\n------------------����Ǿ����ϴ�------------------\n");
	Sleep(1000);
}
static bool loadPuzzle() {
// ���� �ҷ�����
	char alp;
	if (eMove + eTime != 0) {
		// eMove�� eTime�� �ʱⰪ(0)�� �ƴ� ��
		while (true) {
			printf("\n����� ���� ����� �ֽ��ϴ�. �ҷ����ðڽ��ϱ�?(Y/N): ");
			scanf("%c", &alp);
			getchar();
			if (alp == 'Y' || alp == 'y') {
				for (int i = 0; i < DIM; i++)
					for (int j = 0; j < DIM; j++)
						map[i][j] = emap[i][j];	// ���� �ҷ�����
				nMove = eMove;	// ������ Ƚ�� �ҷ�����
				x = ex;
				y = ey;
				// ��ĭ ��ġ �ҷ�����
				return true;
			}

			else if (alp == 'N' || alp == 'n') {
				printf("\n\n������ �ҷ����� �ʾҽ��ϴ�. ���� �������ֽñ� �ٶ��ϴ�.\n");
				exit(1);
			}
			else
				printf("Y/N�� �ƴ� �ٸ� Ű�Դϴ�. �ٽ� �Է����ֽʽÿ�.\n\n");
		}
	}
	return false;
}
static int getDirKey() { return _getche() == 224 ? _getch() : 0; }
int playPuzzle() {
// ���� �÷���
loop1:
	init();
	display(0);		// �ʱ�ȭ��
	printRanking();	// ���� ��ŷ ���
	if(loadPuzzle())
		goto loop2;	// ����� ����� ���ư���
	printf("\n ������ �����ּ���(����)...");
	_getche();
	shuffle(SHUFFLE);
	printf("\n������ ���۵˴ϴ�(����)...");
	_getche();
	nMove = 0;
loop2:
	tStart = clock();
	display();
	printf("\n������ ���Ͻø� ����Ű�� ������ �ƹ� Ű�� �����ּ���.");
	while (!isDone()) {
	// ������ �ϼ��� ������
		int s;
		s = getDirKey();
		if (s == 0) {
			storePuzzle();	// ���� ����
			goto loop1;	// �ʱ� ȭ������ ���ư���
		}
		if (move(s)) {
			pRep[nMove - 1] = s;
			pMove++;	
		}	// ���� �÷����� �������� �ǹ����� ��
			// ���� ���÷��� �迭�� ������ �߰� �� ������ Ƚ�� 1����
		display();
		printf("\n������ ���Ͻø� ����Ű�� ������ �ƹ� Ű�� �����ּ���.");
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