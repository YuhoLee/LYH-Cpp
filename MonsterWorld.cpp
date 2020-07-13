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
		rank.load("MonsterWorld.rnk");	// ��ŷ ���� �ε�
	}
	catch (FileException e) {			// ���� �߻� ��
		// ��й�ȣ�� �Է��ϵ��� ��
		char str[80];
		string password, correct = "123456";
		cout << "������ ��й�ȣ�� �Է��ϼ���: ";
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
			cout << "��й�ȣ�� ���� �ʽ��ϴ�. ���� ����.\n\n";
			exit(0);
		}
		// ��� ��ȣ�� ������ �⺻ ��ŷ���� ������ ��� ������.
	}

	rank.print("[���� ��ŷ: ����]");
	srand((unsigned int)time(NULL));

	int w = 8, h = 4;
	MonsterWorld game(w, h);		
	game.add(new Zombie("�׳�����", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�", "��", rand() % w, rand() % h));
	game.add(new KGhost("ó��ͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("�Ϲݰ���", "��", rand() % w, rand() % h, true));
	Human* human = new Tuman("�÷��̾�", "��", rand() % w, rand() % h);
	game.add(human);
	game.play(300, 5);
	printf("------���� ����-------------------\n");

	rank.add(human->nItem, human->nItem/human->total);
	rank.print("[���� ��ŷ: ����]");

	try {
		rank.store("MonsterWorld.rnk");		// ������ ��ŷ���Ͽ� ����
	}
	catch (FileException e) {				// ���� �߻� �� 
		// ���� ������ ���� ��й�ȣ�� �Է��ϵ��� ��
		char str[80];
		string password, correct = "123456";
		cout << "������ ��й�ȣ�� �Է��ϼ���: ";
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
			cout << "��й�ȣ�� ���� �ʽ��ϴ�. ������ ������ �� �����ϴ�. ���� ����.\n\n";
			exit(0);
		}
		// ��й�ȣ�� Ʋ�� exit(0)�� �ϰ� �Ǹ� �� �Ʒ� ���������� ���� �ʰ� ��
		string filename;	// ���ο� ���� �̸��� ��¡�Ǵ� ��
		cout << "���� �� ���� �̸��� �Է����ּ���: ";
		cin >> filename;
		rank.store(filename);	// ���ο� ���Ͽ� ����
	}

	
}