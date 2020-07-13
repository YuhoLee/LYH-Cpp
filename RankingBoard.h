// <RankingBoard.h>
#pragma once
#include <iostream>
#include <fstream>
#include "FileException.h"
using namespace std;
#define NUM_MVP 5

struct PlayInfo {			// 게임 정보 클래스
	string name;			// 게이머의 이름
	int nItem;				// 획득한 아이템의 수
	double itemPerMove;		// 이동 거리당 아이템 수
	PlayInfo(string na = "신인류", int ni = 0, double ipm = 0.0)
		: name(na), nItem(ni), itemPerMove(ipm) {}
};

class RankingBoard {		// 랭킹 관리 클래스
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;
public:
	void load(string filename) {		// 랭킹 파일 로드
		ifstream is;
		is.open(filename);
		if (!is)	// 파일 열기 실패 시
			throw(FileException(filename, true));	// 예외 throw
		for (int i = 0; i < nMVP; i++)
			is >> MVP[i].nItem >> MVP[i].name >> MVP[i].itemPerMove;	// 로드 내용 불러오기
		is.close();
	}
	void store(string filename) {		// 랭킹 파일 저장
		ofstream os;
		os.open(filename);
		if (!os)	// 파일 열기 실패 시
			throw (FileException(filename, false));		// 예외 throw
		for (int i = 0; i < nMVP; i++)
			os << MVP[i].nItem << " " << MVP[i].name << " " << MVP[i].itemPerMove << "\n";
			// 내용 저장하기
		os.close();
	}
	void print(string title = "게임 랭킹") {		// 랭킹 출력
		cout << endl << title << endl;
		for (int i = 0; i < nMVP; i++)
			cout << "[" << i + 1 << "위] " << MVP[i].name << "\t" << MVP[i].nItem << " " << MVP[i].itemPerMove << "\n";
		if (title == "[게임 랭킹: 시작]"){
			cout << "엔터를 입력하세요.";
			getchar();
		}
		cout << endl;
	}
	int add(int nItem, double ipm) {		// 랭킹 추가
		if (nItem <= MVP[nMVP - 1].nItem) return 0;

		int pos = nMVP - 1;
		for (; pos > 0; pos--) {
			if (nItem <= MVP[pos - 1].nItem) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nItem = nItem;
		MVP[pos].itemPerMove = ipm;
		cout << "\n[" << pos + 1 << "위] 이름을 입력하세요: ";
		cin >> MVP[pos].name;
		return pos + 1;
	}
};
