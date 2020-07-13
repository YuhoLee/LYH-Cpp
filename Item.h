#pragma once
#include "Canvas.h"
class Item {
public:
	int x;
	int y;
	Item(int ix = -1, int iy = -1)
	:x(ix), y(iy){}

	virtual void draw(Canvas& canvas) {	// 아이템을 그려냄
		canvas.draw(x, y, "△");
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
	// 생성자 중복: 포션을 만들 때 원하는 곳에 만들기 편하게 하기 위해서
	// 아이템 이벤트 발생 시에도 필요

	void draw(Canvas& canvas) {	// 물약을 그려냄
		canvas.draw(x, y, "△");
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
	// 생성자 중복: 붐업을 만들 때 원하는 곳에 만들기 편하게 하기 위해서
	// 아이템 이벤트 발생 시에도 필요

	void draw(Canvas& canvas) {	// 물풍선을 그려냄
		canvas.draw(x, y, "♤");
	}
};