// <Matrix.h>
#pragma once
using namespace std;
class Matrix {
	int rows, cols;
	int** mat;
public:
	Matrix(int r = 0, int c = 0)	// 생성자 - 2차원 배열 동적 할당
		: rows(r), cols(c), mat(NULL) {
		mat = new int* [rows];	// 먼저 행에 대한 배열을 동적 할당 한 후,
		for (int i = 0; i < rows; i++)
			mat[i] = new int[cols];	// 열에 대한 배열을 각 행에 동적 할당한다.
	}
	~Matrix() {		// 소멸자 - 할당된 메모리 삭제
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				delete[] mat[i];	// 먼저 여러 행에 있는 요소들의 메모리를 삭제한 후
			delete[] mat;			// 행에 대한 메모리 삭제를 진행한다
		}
	}
	int& elem(int x, int y) {		// 반환 값을 lvalue로 반환하여 반환 후에도 바꿀 수 있도록 함.
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
