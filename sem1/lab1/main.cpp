#include <iostream>

using namespace std;
int main()
{
	// Переменная - хранилище значения определённого типа
	
	// Целочисленный тип
	cout << "Type name: int" << endl;
	cout << "Size: " << sizeof(int) << endl;
	cout << "Min: " << INT_MIN << endl;
	cout << "Max: " << INT_MAX << endl;
	int a, b;
	a = -7; b = 9;
	cout << "a + b = " << a + b << endl;
	cout << endl;
	cout << "Type name: unsigned int" << endl;
	cout << "Size: " << sizeof(int) << endl;
	cout << "Min: " << 0 << endl;
	cout << "Max: " << UINT_MAX << endl;
	unsigned int c, d;
	c = 3; d = 4;
	cout << "c + d = " << c + d << endl;
	cout << endl;
	cout << "Type name: short" << endl;
	cout << "Size: " << sizeof(short) << endl;
	cout << "Min: " << SHRT_MIN << endl;
	cout << "Max: " << SHRT_MAX << endl;
	short e, f;
	e = -2; f = 4;
	cout << "e + f = " << e + f << endl;
	cout << endl;
	cout << "Type name: unsigned short" << endl;
	cout << "Size: " << sizeof(short) << endl;
	cout << "Min: " << 0 << endl;
	cout << "Max: " << USHRT_MAX << endl;
	unsigned short g, h;
	g = 3; h = 4;
	cout << "g + h = " << g + h << endl;
	cout << endl;
	cout << "Type name: long" << endl;
	cout << "Size: " << sizeof(long) << endl;
	cout << "Min: " << LONG_MIN << endl;
	cout << "Max: " << LONG_MAX << endl;
	long i, j;
	i = -7802; j = 98345;
	cout << "i + j = " << i + j << endl;
	cout << endl;
	cout << "Type name: unsigned long" << endl;
	cout << "Size: " << sizeof(long) << endl;
	cout << "Min: " << 0 << endl;
	cout << "Max: " << ULONG_MAX << endl;
	unsigned long k, l;
	k = 972353; l = 28374;
	cout << "k + l = " << k + l << endl;
	cout << endl;
	// Вещественный тип
	cout << "Type name: double" << endl;
	cout << "Size: " << sizeof(double) << endl;
	cout << "Min: " << DBL_MIN << endl;
	cout << "Max: " << DBL_MAX << endl;
	double m, n;
	m = 34.7; n = 4.9;
	cout << "m + n = " << m + n << endl;
	cout << endl;
	// Символьный тип
	cout << "Type name: char" << endl;
	cout << "Size: " << sizeof(char) << endl;
	cout << "Min: " << CHAR_MIN << endl;
	cout << "Max: " << CHAR_MAX << endl;
	char o;
	o = 'w';
	cout << "o = " << o << endl;
	cout << endl;
	// Логический тип
	cout << "Type name: bool" << endl;
	cout << "Size: " << sizeof(bool) << endl;
	cout << "Min: " << false << endl;
	cout << "Max: " << true << endl;
	return 0;
}