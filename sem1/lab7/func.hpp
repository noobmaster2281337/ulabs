#pragma once
int** creatematrix(int strings, int columns);
void fillmatrix(int** matrix, int strings, int columns);
void printmatrix(int** matrix, int strings, int columns);
void deletematrix(int** matrix, int strings, int columns);
bool contains_0(int x);
bool checkifalldiagonalelementsarebiggest(int** matrix, int strings, int columns);
int replaceelementscontainszerowithdiagonalmult(int** matrix, int strings, int columns);