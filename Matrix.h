// <Matrix.h>
#pragma once
using namespace std;
class Matrix {
	int rows, cols;
	int** mat;
public:
	Matrix(int r = 0, int c = 0)	// ������ - 2���� �迭 ���� �Ҵ�
		: rows(r), cols(c), mat(NULL) {
		mat = new int* [rows];	// ���� �࿡ ���� �迭�� ���� �Ҵ� �� ��,
		for (int i = 0; i < rows; i++)
			mat[i] = new int[cols];	// ���� ���� �迭�� �� �࿡ ���� �Ҵ��Ѵ�.
	}
	~Matrix() {		// �Ҹ��� - �Ҵ�� �޸� ����
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				delete[] mat[i];	// ���� ���� �࿡ �ִ� ��ҵ��� �޸𸮸� ������ ��
			delete[] mat;			// �࿡ ���� �޸� ������ �����Ѵ�
		}
	}
	int& elem(int x, int y) {		// ��ȯ ���� lvalue�� ��ȯ�Ͽ� ��ȯ �Ŀ��� �ٲ� �� �ֵ��� ��.
		return mat[y][x];
	}
	int Rows() { return rows; }
	int Cols() { return cols; }
	int** Data() { return mat; }
	void print(const char* str = "Mat") {
		cout << str << " " << rows << "x" << cols << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				cout << mat[i][j];
			cout << "\n";
		}
	}
	void setRand(int val = 100) {
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					mat[i][j] = (rand() % val);
		}
	}
};
