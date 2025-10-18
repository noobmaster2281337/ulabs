#include <iostream>
#include <iomanip>
using namespace std;

void printBinary(unsigned char byte) { // байт побитово
    for (int i = 7; i >= 0; i--) {
        cout << ((byte >> i) & 1);
    }
}

int main() 
{
    unsigned int x;
    cout << "Enter a number: " << endl;
    cin >> x;

    //unsigned char - так как для одного байта, в unsigned int их - четыре
    unsigned char* n = (unsigned char*) &x;
	cout << "decimal number system" << endl;
    for (int i = 0; i < sizeof(x); i++)
    {
        cout << (int) *(n + i) << " "; // вывод значений байтов числа в десятичной сс
    }
	cout << endl;
	cout << "hexadecimal number system" << endl;
    for (int i = 0; i < sizeof(x); i++)
    {
        cout << hex << (int) *(n + i) << " "; // вывод значений байтов числа в hex сс
    }
	cout << endl;
	cout << "binary number system" << endl;
    for (int i = 0; i < sizeof(x); i++)
    {
        printBinary(*(n + i)); // Просто вызываем функцию для вывода двоичного представления
        cout << " "; // Пробел после каждого байта
    }
    return 0;
}