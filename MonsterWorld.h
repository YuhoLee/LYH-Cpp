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
	Matrix world;					// 아이템의 유무를 나타내는 배열 
	Monster* pMon[MAXMONS];			// 최대 몬스터 수 만큼의 몬스터 객체
	Canvas canvas;					// 게임의 출력을 담당하는 캔버스 객체
	int xMax, yMax, nMon, nMove;			// 최대 x와 y, 몬스터의 수, 움직인 횟수
	
	int& Map(int x, int y) { return world.elem(x,y); }	// map의 특정 위치 현재 상황 반환
	bool isDone() { return countItems() == 0; }
	int countItems() {		// 남아있는 아이템 개수를 셈
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;		
		return nItems;
	}
	void print() {		// 배열 map에 따라서 아이템을 캔버스에 그리고 몬스터도 그린 후 게임상태 메세지 출력
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "■");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Monster World (몬스터들의 세상) ]");

		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
		Monster::printCount();	// Monster클래스의 printCount()를 통해 몬스터 수 출력
	}
public:
	MonsterWorld(int w, int h) : world(h,w), canvas(w, h), xMax(w), yMax(h) {		
		// 생성자 - 객체 생성시 받을 인수와 초기화 해야 할 요소들 초기화
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;		
	}
	~MonsterWorld() {	// 소멸자
		for (int i = 0; i < nMon; i++)
			delete pMon[i];
	}
	void add(Monster* m) {	// 몬스터 생성
		if (nMon < MAXMONS) pMon[nMon++] = m;
	}
	
	void play(int maxwalk, int wait) {	// 게임 플레이
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon-1; k++)
				pMon[k]->move(world.Data(), xMax, yMax);
			if (_kbhit()) {				// 1p대한 조작을 하기 위함, 2p는 삭제
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

