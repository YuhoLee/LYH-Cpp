// <MonsterWorld.h>
#pragma once
#include "Canvas.h"
#include "Monster.h"
#include "Matrix.h"
#include <windows.h>
#include "VariousMonster.h"
#include "Human.h"
#define MAXMONS 5

class MonsterWorld {
	Matrix world;					// �������� ������ ��Ÿ���� �迭 
	Monster* pMon[MAXMONS];			// �ִ� ���� �� ��ŭ�� ���� ��ü
	Canvas canvas;					// ������ ����� ����ϴ� ĵ���� ��ü
	int xMax, yMax, nMon, nMove;			// �ִ� x�� y, ������ ��, ������ Ƚ��
	
	int& Map(int x, int y) { return world.elem(x,y); }	// map�� Ư�� ��ġ ���� ��Ȳ ��ȯ
	bool isDone() { return countItems() == 0; }
	int countItems() {		// �����ִ� ������ ������ ��
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;		
		return nItems;
	}
	void print() {		// �迭 map�� ���� �������� ĵ������ �׸��� ���͵� �׸� �� ���ӻ��� �޼��� ���
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "��");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Monster World (���͵��� ����) ]");

		cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;
		cerr << " ���� ������ �� = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
		Monster::printCount();	// MonsterŬ������ printCount()�� ���� ���� �� ���
	}
public:
	MonsterWorld(int w, int h) : world(h,w), canvas(w, h), xMax(w), yMax(h) {		
		// ������ - ��ü ������ ���� �μ��� �ʱ�ȭ �ؾ� �� ��ҵ� �ʱ�ȭ
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;		
	}
	~MonsterWorld() {	// �Ҹ���
		for (int i = 0; i < nMon; i++)
			delete pMon[i];
	}
	void add(Monster* m) {	// ���� ����
		if (nMon < MAXMONS) pMon[nMon++] = m;
	}
	
	void play(int maxwalk, int wait) {	// ���� �÷���
		print();
		cerr << " ���͸� ��������...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon-1; k++)
				pMon[k]->move(world.Data(), xMax, yMax);
			if (_kbhit()) {				// 1p���� ������ �ϱ� ����, 2p�� ����
				unsigned char ch = _getche();
				if (ch == 224) {
					ch = _getche();
					((Tuman*)(pMon[nMon - 1]))->move(world.Data(), xMax, yMax, ch);
				}
			}
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};

