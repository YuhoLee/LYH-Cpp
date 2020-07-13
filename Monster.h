// <Monster.h>
#pragma once
#include "Canvas.h"
#include "Point.h"
#include <stdlib.h>
#include <time.h>

class Monster {
public:
	string name, icon;	// ������ �̸��� ȭ�� ��¿� ������
	int nItem;			// ���� ������ ��
	static int nMon;	// ���� ������ ������ nMon(���� ��)
	Point q, p;			// �߰�: ���� ��ġ(q)�� ���� ��ġ(p)
	int nSleep;			// �߰�: ����� �ϴ� Ƚ��
	double dist;		// �߰�: ���� �� ���� ������ �Ÿ�
	double total;		// �߰�: �� ������ �Ÿ�

	void clip(int maxx, int maxy) {		// ���͵��� ������ ������ ���� �ʵ��� ��.
		p(maxx, maxy);
	}
	void eat(int** map) {		// ������ ȹ�� ����
		if (map[p.y][p.x] == 1) {
			map[p.y][p.x] = 0;
			nItem++;
		}
		dist = dist + double(p - q);
		total = total + double(p - q);
		q = p;
		if (dist > 20) {
			dist = 0;
			nSleep = 10;
		}
	}
	bool isSleep() {
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		else return false;
	}
	Monster(string n = "������", string i = "��", int px = 0, int py = 0)
		:name(n), icon(i), p(px,py), q(px,py), nSleep(0), dist(0.0), total(0.0), nItem(0) {
		nMon++;
	}
	// �����ڸ� ���� ������ �� ��ҵ鿡 ���� �ʱⰪ�� ��������
	virtual ~Monster() { 	// �Ҹ��ڸ� ���� �÷��̰� ���� �� ����ִ� ���Ϳ� ���� ������ ����ϵ��� ��
		nMon--;
		cout << name << " " << icon << "  �Ÿ� : " << total << endl;
	}
	string getName() { return name; }
	void draw(Canvas& canvas) { canvas.draw(p, icon); }	// ĵ������ ������ ��ġ�� �׷������� ��
	virtual void move(int** map, int maxx, int maxy) {		// �������� 8���� �� �ϳ��� �����Ͽ� �̵� 
		if (!isSleep()) {		// �� Ÿ�̹� �ƴҽ�
			Point i = Point(rand() % 3 - 1, rand() % 3 - 1);
			p = p + i;
			clip(maxx, maxy);
			eat(map);
		}
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl; }
	// ������ ���� ���� ��� (���� ������, ������ ���)
	static void printCount() { cout << "\t���� ���� ��: " << nMon << endl; }
};