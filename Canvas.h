// <Canvas.h>
#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#define MAXLINES 100
using namespace std;

class Canvas {
	string line[MAXLINES];	// ȭ�� ����� ���� ���ڿ�
	int xMax, yMax;		// ���� ũ��
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {		// ������
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');
	}
	void draw(int x, int y, string val) {		// ���ӿ� ���� ȭ���� �׸� 
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);
	}
	void draw(Point& p, string val) {
		draw(p.x, p.y, val);
	}
	void clear(string val = ". "){		// ĵ������ �׸��� ���� val�� �ٲ�
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
	void print(const char* title = "<My Canvas>") {		
		// ��ü ���� �� print�� �ƹ��� �μ��� ���� ���� �ÿ��� ���� ������ ����ϱ� ���� �����尪�� ��
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)	
			cout << line[y] << endl;
		cout << endl;
	}
};