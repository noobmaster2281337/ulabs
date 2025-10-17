#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Ru");
	// Вариант 6
    // 1
	int a, b, c;
	cin >> a >> b >> c;
	if (a < b && b > c) cout << b + a - c << endl;
	else if (b % c == 0) cout << (b / c) - b << endl;
	else cout << a * b - c << endl; 
	// 2
	int N;
	cin >> N;
    switch (N) {
    case 1: cout << "Январь";
        break;
    case 2: cout << "Февраль";
        break;
    case 3: cout << "Март";
        break;
    case 4: cout << "Апрель";
        break;
    case 5: cout << "Май";
        break;
    case 6: cout << "Июнь";
        break;
    case 7: cout << "Июль";
        break;
    case 8: cout << "Август";
        break;
    case 9: cout << "Сентябрь";
        break;
    case 10: cout << "Октябрь";
        break;
    case 11: cout << "Ноябрь";
        break;
    case 12: cout << "Декабрь";
        break;
    default: cout << "Ошибочный ввод номера месяца" << endl;
    }
    // 3
    int x;
    cin >> x;
    if (x == 1) cout << "Positive number";
    else cout << "Negative number";
    // ну по-моему очень даже логично, а как ещё?
    return 0;
}