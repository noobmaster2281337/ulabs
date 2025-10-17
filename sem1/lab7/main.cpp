#include <iostream>
#include "func.hpp"
using namespace std;

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

	if (checkifalldiagonalelementsarebiggest(firstmatrix, mstrings, mcolumns)) {
		replaceelementscontainszerowithdiagonalmult(firstmatrix, mstrings, mcolumns);
		cout << endl;
		printmatrix(firstmatrix, mstrings, mcolumns);
	}
	deletematrix(firstmatrix, mstrings, mcolumns);
	return 0;
}