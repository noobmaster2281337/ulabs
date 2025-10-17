#include <iostream>

using namespace std;
int main()
{
	// Вариант 6
	setlocale(LC_ALL, "Ru");
	unsigned int number;
	cout << "Введите число" << endl;
	cin >> number;
	int index;
	cout << "Введите i-ый бит, который хотите узнать" << endl;
	cin >> index;
	cout << ((number >> index) & 1);
	return 0;
}