// <MonsterWorld.cpp>
#include "MonsterWorld.h"
#include "VariousMonster.h"
#include "Human.h"
#include "RankingBoard.h"
#include <time.h>
int Monster::nMon = 0;
int main(void) {
	RankingBoard rank;
	try {
		rank.load("MonsterWorld.rnk");	// 랭킹 파일 로드
	}
	catch (FileException e) {			// 예외 발생 시
		// 비밀번호를 입력하도록 함
		char str[80];
		string password, correct = "123456";
		cout << "관리자 비밀번호를 입력하세요: ";
		for (int i = 0;; i++) {
			str[i] = _getch();
			putchar('*');
			if (str[i] == '\r') {
				str[i] = '\0';
				password = str;
				cout << "\n";
				break;
			}
		}
		if (password != correct) {
			cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
			exit(0);
		}
		// 비밀 번호가 맞으면 기본 랭킹으로 게임을 계속 진행함.
	}

	rank.print("[게임 랭킹: 시작]");
	srand((unsigned int)time(NULL));

	int w = 8, h = 4;
	MonsterWorld game(w, h);		
	game.add(new Zombie("그냥좀비", "◎", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어", "※", rand() % w, rand() % h));
	game.add(new KGhost("처녀귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("일반강시", "↔", rand() % w, rand() % h, true));
	Human* human = new Tuman("플레이어", "♀", rand() % w, rand() % h);
	game.add(human);
	game.play(300, 5);
	printf("------게임 종료-------------------\n");

	rank.add(human->nItem, human->nItem/human->total);
	rank.print("[게임 랭킹: 종료]");

	try {
		rank.store("MonsterWorld.rnk");		// 순위를 랭킹파일에 저장
	}
	catch (FileException e) {				// 예외 발생 시 
		// 파일 생성을 위해 비밀번호를 입력하도록 함
		char str[80];
		string password, correct = "123456";
		cout << "관리자 비밀번호를 입력하세요: ";
		for (int i = 0;; i++) {
			str[i] = _getch();
			putchar('*');
			if (str[i] == '\r') {
				str[i] = '\0';
				password = str;
				cout << "\n";
				break;
			}
		}
		if (password != correct) {
			cout << "비밀번호가 맞지 않습니다. 파일을 저장할 수 없습니다. 게임 종료.\n\n";
			exit(0);
		}
		// 비밀번호가 틀려 exit(0)을 하게 되면 이 아래 순서까지는 오지 않게 됨
		string filename;	// 새로운 파일 이름이 저징되는 곳
		cout << "저장 할 파일 이름을 입력해주세요: ";
		cin >> filename;
		rank.store(filename);	// 새로운 파일에 저장
	}

	
}