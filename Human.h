// <Human.h>
#pragma once
#include "Monster.h"
#include <conio.h>
class Human : public Monster {
protected:
	enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };	// ������
	int DirKey[4] = { Left, Right, Up, Down };
public:
	Human(string n = "�׳��ΰ�", string i = "��", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() {}
	int getDirkey() { return _getche() == 224 ? _getche() : 0; }
	void move(int** map, int maxx, int maxy) {		// ����Ű �Է¿� ���� �̵�
		if (_kbhit()) {
			char ch = getDirkey();
			if (ch == Left) p[0]--;
			else if (ch == Right) p[0]++;
			else if (ch == Up) p[1]--;
			else if (ch == Down) p[1]++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};
class Tuman : public Human {
public:
	Tuman(string n = "��ȭ�ΰ�", string i = "��", int px = 0, int py = 0)
		:Human(n, i, px, py) {}
	~Tuman() { cout << "[Tuman] "; }
	void move(int** map, int maxx, int maxy, char ch) {
		if (ch == Left || ch == 'a' || ch == 'A') p[0]--;
		else if (ch == Right || ch == 'd' || ch == 'D') p[0]++;
		else if (ch == Up || ch == 'w' || ch == 'W') p[1]--;
		else if (ch == Down || ch == 's' || ch == 'S') p[1]++;
		else return;
		clip(maxx, maxy);
		eat(map);
	}
};