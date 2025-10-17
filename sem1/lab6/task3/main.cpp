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
	cout << endl << "Введите элементы матрицы:" << endl;
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
int findstringnumberwithbiggestvalue(int** matrix, int strings, int columns) {
	int max_mult = 0, maxstringnumber = -1;
	for (int i = 0; i < strings; i++) {
		int mult = 1;
		for (int j = 0; j < columns; j++) {
			mult *= matrix[i][j];
		}
		if (mult > max_mult) {
			max_mult = mult;
			maxstringnumber = i;
		}
	}
	return maxstringnumber;
}
int findstringmultwithbiggestvalue(int** matrix, int strings, int columns) {
	int max_mult = 0;
	for (int i = 0; i < strings; i++) {
		int mult = 1;
		for (int j = 0; j < columns; j++) {
			mult *= matrix[i][j];
		}
		if (mult > max_mult) {
			max_mult = mult;
		}
	}
	return max_mult;
}
void replace_all_elements_ofthis_string_bythismult(int** matrix, int columns, int stringnumber, int totsamiymaxmult) {
	for (int i = 0; i < columns; i++) {
		matrix[stringnumber][i] = totsamiymaxmult;
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");

	int mstrings = 0, mcolumns = 0;
	cout << "Введите количество строк матрицы: ";
	cin >> mstrings;
	cout << "Введите количество столбцов матрицы: ";
	cin >> mcolumns;

	int** firstmatrix = creatematrix(mstrings, mcolumns);
	fillmatrix(firstmatrix, mstrings, mcolumns);

	replace_all_elements_ofthis_string_bythismult(firstmatrix, mcolumns, 
		findstringnumberwithbiggestvalue(firstmatrix, mstrings, mcolumns),
		findstringmultwithbiggestvalue(firstmatrix, mstrings, mcolumns));

	printmatrix(firstmatrix, mstrings, mcolumns);
	deletematrix(firstmatrix, mstrings, mcolumns);
	return 0;
}