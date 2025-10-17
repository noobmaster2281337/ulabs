#include <iostream>
using namespace std;

void fillmas(int* mas, int length) {
	for (int i = 0; i < length; i++) {
		cin >> mas[i];
	}
}
void printmas(int* mas, int length) {
	for (int i = 0; i < length; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;
}
int is_prime(int x) {
	int r = sqrt(x); // целой части хватит
	for (int d = 2; d <= r; d++)
		if (x % d == 0) {
			return false; // простое
		}
	return true; // не простое
}
bool mascontainsprime(int* mas, int length) {
	bool flag = false;
	for (int i = 0; i < length; i++) {
		if (is_prime(mas[i]) == 0) {
			flag = true;
			break;
		}
	}
	return flag;
}
void sortmas(int* mas, int length) {
	for (int i = 0; i < length; i++)
		for (int j = i; j < length; j++) {
			if (mas[i] > mas[j]) swap(mas[i], mas[j]);
		}
}
int main() 
{
	setlocale(LC_ALL, "Ru");
	int maslength = 0;
	cin >> maslength;
	
	int* firstmas = new int[maslength];
	cout << "Введите элементы массива: ";
	fillmas(firstmas, maslength);
	if (mascontainsprime(firstmas, maslength)) {
		sortmas(firstmas, maslength);
	}
	printmas(firstmas, maslength);
	delete[] firstmas;
	return 0;
}