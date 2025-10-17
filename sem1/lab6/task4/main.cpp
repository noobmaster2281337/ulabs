#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int x) {
    int r = sqrt(x); // целой части хватит
    for (int d = 2; d <= r; d++)
        if (x % d == 0) {
            return false; // простое
        }
    return true; // не простое
}
bool is_cube(int x) {
    int y = exp(log(x) / 3);
    if (y * y * y == x) return true;
    return false;
}

int main()
{
	setlocale(LC_ALL, "Ru");
    int n;
    cin >> n;

    // Инициализируем массив
    int* A = new int[2 * n];
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Читаем элементы массива
    }
    // Удаляем элементы из массива
    for (int i = 0; i < n;) { // i++ не надо
        if (is_prime(A[i])) {
            // Сдвигаем элементы влево
            for (int j = i + 1; j < n; j++) {
                A[j - 1] = A[j];
            }
            n--; // Уменьшаем размер массива
        }
        else {
            i++; // Переходим к следующему элементу
        }
    }
    // Дублирование
    for (int i = 0; i < n;) {
        if (is_cube(A[i])) {
            // Увеличиваем размер массива
            n++;
            for (int j = n - 1; j > i + 1; j--) {
                A[j] = A[j - 1]; // Сдвигаем элементы вправо
            }
            A[i + 1] = A[i]; // Дублируем элемент
            i += 2; // Пропускаем следующий дубликат
        }
        else {
            i++; // Переходим к следующему элементу
        }
    }
    
    // Вывод результата
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[] A; // Освобождаем память
    return 0;
}