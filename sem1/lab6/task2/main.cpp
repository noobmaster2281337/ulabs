#include <iostream>

using namespace std;
int main()
{
    
	setlocale(LC_ALL, "Ru");
	// 1
    int n; // количество чисел последовательности
    cin >> n;
    int sum = 0, maxnegative = INT_MIN, index = 0;
    for (int i = 0; i < n; i++) {
        int num; 
        cin >> num;
        if ((num < 0) && (num % 7 == 0)) {
            sum += num;
            if (num > maxnegative) {
                maxnegative = num;
                index = i + 1;
            }
        }
    }
    cout << "Сумма: " << sum << endl;
    cout << "Наибольшее число: " << maxnegative << endl;
    cout << "Номер последовательности: " << index << endl;
    // в задаче не указан случай если нет отрицательных чисел/кратных семи
    // 2
    int chislo, proiz = 1;
    cin >> chislo;
    while (chislo > 0) {
        proiz = proiz * (chislo % 10);
        chislo = chislo/10;
    }
    cout << proiz;
    return 0;
}