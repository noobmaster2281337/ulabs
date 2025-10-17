#include <iostream>

using namespace std;
int main()
{
	// 6 Вариант
	setlocale(LC_ALL, "Ru");
	int S, h;
	double V;
	cout << "Введите площадь основания пирамиды" << endl;
	cin >> S;
	cout << "Введите высоту пирамиды" << endl;
	cin >> h;
	if (S >= 1 || S <= 99) {
		if (h >= 1 || h <= 99)
			V = (S * h) / 3.0;
		cout << "Объём пирамиды: " << V;
	}
	else
		cout << "Введены недопустимые значения";
	return 0;
}