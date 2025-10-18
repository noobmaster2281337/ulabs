#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int N_Max = 2000;

bool Read(int& n, int& cnt, string words[N_Max]) { // Считывает данные с файла в массив
    ifstream in("input.txt");
    if (!in.is_open()) {
        cerr << "file error" << endl; // cerr не буферизирует
        return false; 
    }
    in >> n;
    while (!in.eof()) {
        in >> words[cnt];
        cnt++;
    }
    return true;
}
void debugwrite(int cnt, string words[N_Max]) { // вывод до в консоль
    for (int i = 0; i < cnt; i++)
        cout << "<" << words[i] << ">" << endl;
}
void ClearWords(int cnt, string words[N_Max]) { // очистка и нижний регистр
    for (int i = 0; i < cnt; i++) 
        for (int j = 0; j < words[i].length(); j++) { // пробегаемся по слову
            if (!isalpha(words[i][j])) { // проверяет буква ли
                words[i].erase(j, 1);
                j--;
            }
            else
                words[i][j] = tolower(words[i][j]); // нижний регистр собственно
        }
}
bool threeInAWord(string word) { // Определяет содержит ли слово сочетание из трех алфавитно упорядоченных букв
    int counter = 0;
    for (int i = 0; i < word.length() - 1; i++) {
        char c = word[i];
        if (++c == word[i + 1]) counter++;
        else counter = 0;
        if (counter >= 2) return true;
    }
    return false;
}
void sort(int cnt, string words[N_Max]) { // больше букв сортировка
    for (int i = 0; i < cnt - 1; i++)
        for (int j = i + 1; j < cnt; j++) {
            if (words[i].length() > words[j].length() || (words[i].length() == words[j].length() && words[i] > words[j]))
                swap(words[i], words[j]);
        }
}
void write(int n, int cnt, string words[N_Max]) { // в консоль вывод
    ofstream out("output.txt");
    string previous = "";
    bool isFirst = true;
    for (int i = 0; i < cnt; i++) {
        if (n == 0) break;
        if (isFirst) {
            if (threeInAWord(words[i])) {
            cout << words[i] << endl;
            n--;
            previous = words[i];
            isFirst = false;
            }
        }
        else
        {
            if (threeInAWord(words[i]) && words[i] != previous) {
            cout << words[i] << endl;
            n--;
            previous = words[i];
            }
        }
    }
}
void writeToFile(int n, int cnt, string words[N_Max]) { // в файл
    ofstream out("output.txt");
    string previous = "";
    bool isFirst = true;
    for (int i = 0; i < cnt; i++)
    {
        if (n == 0) break;
        if (isFirst) {
            if (threeInAWord(words[i])) {
            out << words[i] << endl;
            n--;
            previous = words[i];
            isFirst = false;
            }
        }
        else
        {
            if (threeInAWord(words[i]) && words[i] != previous) {
            out << words[i] << endl;
            n--;
            previous = words[i];
            }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Ru");
    int n = 0;
    int cnt = 0; // кол-во слов
    string words[N_Max];

    if (!Read(n, cnt, words))
        return -1;

    debugwrite(cnt, words);

    ClearWords(cnt, words);
    sort(cnt, words);
    write(n, cnt, words);
    writeToFile(n, cnt, words);

    return 0;
}