// <Monster.h>
#pragma once
#include "Canvas.h"
#include "Point.h"
#include <stdlib.h>
#include <time.h>

class Monster {
public:
	string name, icon;	// 몬스터의 이름과 화면 출력용 아이콘
	int nItem;			// 먹은 아이템 수
	static int nMon;	// 정적 변수로 선언한 nMon(몬스터 수)
	Point q, p;			// 추가: 이전 위치(q)와 현재 위치(p)
	int nSleep;			// 추가: 쉬어야 하는 횟수
	double dist;		// 추가: 쉬고 난 다음 움직인 거리
	double total;		// 추가: 총 움직인 거리

	void clip(int maxx, int maxy) {		// 몬스터들이 엉뚱한 곳으로 가지 않도록 함.
		p(maxx, maxy);
	}
	void eat(int** map) {		// 아이템 획득 여부
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
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		:name(n), icon(i), p(px,py), q(px,py), nSleep(0), dist(0.0), total(0.0), nItem(0) {
		nMon++;
	}
	// 생성자를 통해 몬스터의 각 요소들에 대한 초기값을 지정해줌
	virtual ~Monster() { 	// 소멸자를 통해 플레이가 끝난 후 살아있는 몬스터에 대해 문구를 출력하도록 함
		nMon--;
		cout << name << " " << icon << "  거리 : " << total << endl;
	}
	string getName() { return name; }
	void draw(Canvas& canvas) { canvas.draw(p, icon); }	// 캔버스에 몬스터의 위치를 그려내도록 함
	virtual void move(int** map, int maxx, int maxy) {		// 무작위로 8방향 중 하나를 선택하여 이동 
		if (!isSleep()) {		// 쉴 타이밍 아닐시
			Point i = Point(rand() % 3 - 1, rand() % 3 - 1);
			p = p + i;
			clip(maxx, maxy);
			eat(map);
		}
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl; }
	// 몬스터의 현재 상태 출력 (먹은 아이템, 에너지 등등)
	static void printCount() { cout << "\t남은 몬스터 수: " << nMon << endl; }
};