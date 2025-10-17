#include "func.hpp"
#include <iostream>
using namespace std;

int** creatematrix(int strings, int columns) {
	int** matrix = new int* [strings];
	for (int i = 0; i < strings; i++) {
		matrix[i] = new int[columns];
	}
	return matrix;
}
void fillmatrix(int** matrix, int strings, int columns) {
	cout << endl << "введите элементы матрицы:" << endl;
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns; j++) {
			cin >> matrix[i][j];
		}
	}
}
void printmatrix(int** matrix, int strings, int columns) {
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void deletematrix(int** matrix, int strings, int columns) {
	for (int i = 0; i < strings; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
bool contains_0(int x) {
	while (x > 0) {
		if (x % 10 == 0) return true;
		x = x / 10;
	}
	return false;
}
bool checkifalldiagonalelementsarebiggest(int** matrix, int strings, int columns) {
	bool alldiagonalelementsarebiggest = false;
	for (int i = 0; i < strings; i++) {
		int max = matrix[i][i];
		for (int j = 0; j < columns; j++) {
			if (j != i && matrix[i][j] > max) {
				return false;
			}
		}
	}
	return true;
}
int replaceelementscontainszerowithdiagonalmult(int** matrix, int strings, int columns) {
	int mult = 1;
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j) mult *= matrix[i][j];
		}
	}
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns; j++) {
			if (contains_0(matrix[i][j])) matrix[i][j] = mult;
		}
	}
	return mult;
}