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
int sum_of_digits(int x) {
	int sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int mult_of_digits(int x) {
	int mult = 1;
	while (x > 0) {
		mult = mult * (x % 10);
		x /= 10;
	}
	return mult;
}
void sortmasbysumofdigits(int* mas, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (sum_of_digits(mas[i]) < sum_of_digits(mas[j])) continue;
			else if (sum_of_digits(mas[i]) > sum_of_digits(mas[j])) swap(mas[i], mas[j]);
			else {
				if (mult_of_digits(mas[i]) < mult_of_digits(mas[j])) continue;
				else if (mult_of_digits(mas[i]) > mult_of_digits(mas[j])) swap(mas[i], mas[j]);
				else {
					if (mas[i] > mas[j]) swap(mas[i], mas[j]);
				}
			}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Ru");
	int maslength = 0;
	cout << "Введите длину последовательности: " << endl;
	cin >> maslength;

	int* firstmas = new int[maslength];
	cout << endl << "Введите последовательность: " << endl;
	fillmas(firstmas, maslength);

	sortmasbysumofdigits(firstmas, maslength);

	printmas(firstmas, maslength);
	delete[] firstmas;
	return 0;
}