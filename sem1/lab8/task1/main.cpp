#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int N_Max = 2000;

bool Read(int& n, string words[N_Max])
{
    ifstream in("input.txt");
    if(!in.is_open()) {
        std::cout << "File not opened" << endl;
        return false;
    }
    n = 0;
    while(!in.eof()) {
        in >> words[n];
        n++;
    }
    return true;
}
void Write(int& n, string words[N_Max]) {
    for(int i=0;i<n;i++)
        cout << "<" << words[i] << ">" << endl;
}

void clearWords(int cnt, string words[N_Max]) {
    for (int i = 0; i < cnt; i++) 
        for (j = 0; j < words[i].length();) {
            if (!isalpha(words[i][j])) {
                words[i].erase(j, 1);
            } else {
                words[i][j] = tolower(words[i][j]);
                j++;
            }
        }
}

bool threeInAWord(const string& word) {
    if (word.length() < 3) return false;
    for (size_t i = 0; i <= word.length() - 3; i++) {
        if (word[i + 1] == word[i] + 1 && word[i + 2] == word[i + 1] + 1) {
            return true;
        }
    }
    return false;
}

void sort(int cnt, string words[N_Max]) {
    for (int i = 0; i < cnt - 1; i++)
        for (int j = i + 1; j < cnt; j++) {
            if (words[i].length() > words[j].length() || 
                (words[i].length() == words[j].length() && words[i] > words[j]))
                swap(words[i], words[j]);
        }
}

void writeWords(int n, int cnt, string words[N_Max]) {
    ofstream out("output.txt");
    if (!out.is_open()) {
        cerr << "Ошибка открытия файла output.txt" << endl;
        return;
    }
    int count = 0;
    string previous = "";
    for (int i = 0; i < cnt && count < n; i++) {
        if (threeInAWord(words[i]) && words[i] != previous && !words[i].empty()) {
            cout << words[i] << endl;
            out << words[i] << endl;
            previous = words[i];
            count++;
        }
    }
    out.close();
}

int main() {
    setlocale(LC_ALL, "Ru");
    int n = 0, cnt = 0;
    string words[N_Max];

    if (!Read(n, words))
        return -1;

    cout << "Исходные слова:" << endl;
    Write(cnt, words);

    clearWords(cnt, words);
    sort(cnt, words);
    cout << "Результат:" << endl;
    writeWords(n, cnt, words);

    return 0;
}