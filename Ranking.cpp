// <Ranking.cpp>
#include "Ranking.h"
#define NUM_MVP 10				// ��ŷ ũ��
static PlayInfo MVP[NUM_MVP];	// ��ŷ �迭
static int nMVP = NUM_MVP;		// ��ŷ �ο� ��

void initRanking() {	// ��ŷ �ʱⰪ ����
	PlayInfo noname = {"C++���ƿ�", 1000, 1000.0 };
	for (int i = 0; i < nMVP; i++)
		MVP[i] = noname;
}
void loadRanking(const char* fname) {	// ��ŷ �ҷ�����
	FILE* fp = fopen(fname, "r");	// �б���� ���� ����
	if (fp == NULL) 
		initRanking();
	else {
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);	// �������� �о����
		fclose(fp);
	}
}
void storeRanking(const char* fname) {	// ��ŷ �����ϱ�
	FILE* fp = fopen(fname, "w");	// ������� ���� ����
	if (fp == NULL) return;
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);	// �������Ͽ� �����ϱ�
	fclose(fp);
	}
void printRanking() {	// ��ŷ ����ϱ�
	printf("\n  <����>   <�ҿ�ð�>          <�̸�>       <�̵�Ƚ��>\n\n");
	for (int i = 0; i < nMVP; i++)
		printf("  [%2d��]     %5.1f           %-16s %4d\n", i + 1, MVP[i].tElapsed, MVP[i].name, MVP[i].nMove);
}
int addRanking(int nMove, double tElap){	// ��ŷ �߰��ϱ�
	if (tElap < MVP[nMVP - 1].tElapsed) {
	// �μ��� ���� ���� ���� ������ ���� ������ ���� ��(������ �� ����� ��)
		int pos = nMVP - 1;	// ���� ���� ��ŷ �ο�
		for (; pos > 0; pos--) {
			if (tElap >= MVP[pos - 1].tElapsed) break; 
			// �� ����� ��ŷ ������ �� �ݺ��� Ż��
			MVP[pos] = MVP[pos - 1];
			// �ƴ� �ÿ��� ���� ��ŷ�� ���� ������ �̷��
		}
		MVP[pos].tElapsed = tElap;
		MVP[pos].nMove = nMove;
		printf("\n\n[%5.1f��] %d�� �Դϴ�. �̸��� �Է��ϼ���: ", tElap, pos + 1);
		scanf("%s", MVP[pos].name);
		getchar();
		return pos + 1;
	}
}