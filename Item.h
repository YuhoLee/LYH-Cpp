#pragma once
#include "Canvas.h"
class Item {
public:
	int x;
	int y;
	Item(int ix = -1, int iy = -1)
	:x(ix), y(iy){}

	virtual void draw(Canvas& canvas) {	// �������� �׷���
		canvas.draw(x, y, "��");
	}
};

class Potion : public Item{
public:
	Potion()
		:Item(0, 0){}
	Potion(int ix)
		:Item(ix, 0){}			
	Potion(int ix, int iy) 
		:Item(ix, iy){}
	// ������ �ߺ�: ������ ���� �� ���ϴ� ���� ����� ���ϰ� �ϱ� ���ؼ�
	// ������ �̺�Ʈ �߻� �ÿ��� �ʿ�

	void draw(Canvas& canvas) {	// ������ �׷���
		canvas.draw(x, y, "��");
	}
};

class BombUp: public Item {
public:
	BombUp()
		:Item(0, 0){}
	BombUp(int ix)
		:Item(ix, 0){}
	BombUp(int ix, int iy)
		:Item(ix, iy){}
	// ������ �ߺ�: �վ��� ���� �� ���ϴ� ���� ����� ���ϰ� �ϱ� ���ؼ�
	// ������ �̺�Ʈ �߻� �ÿ��� �ʿ�

	void draw(Canvas& canvas) {	// ��ǳ���� �׷���
		canvas.draw(x, y, "��");
	}
};