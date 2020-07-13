// <Canvas.h>
#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#define MAXLINES 100
using namespace std;

class Canvas {
	string line[MAXLINES];	// 화면 출력을 위한 문자열
	int xMax, yMax;		// 맵의 크기
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {		// 생성자
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');
	}
	void draw(int x, int y, string val) {		// 게임에 대한 화면을 그림 
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);
	}
	void draw(Point& p, string val) {
		draw(p.x, p.y, val);
	}
	void clear(string val = ". "){		// 캔버스의 그림을 전부 val로 바꿈
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
	void print(const char* title = "<My Canvas>") {		
		// 객체 생성 후 print시 아무런 인수도 주지 않을 시에도 게임 제목을 출력하기 위해 디폴드값을 줌
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)	
			cout << line[y] << endl;
		cout << endl;
	}
};