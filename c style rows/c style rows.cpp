#include <iostream>
using namespace std;

int myStrlen(const char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

int main() {
    char s[256];
    cout << "Введіть рядок: ";
    cin.getline(s, 256);

    int a = 0, o = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'A') a++;
        if (s[i] == 'o' || s[i] == 'O') o++;
    }
    if (a > o) cout << "Більше 'a'" << endl;
    else if (o > a) cout << "Більше 'o'" << endl;
    else cout << "Порівну" << endl;

    int letters = 0, digits = 0, spaces = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) letters++;
        else if (s[i] >= '0' && s[i] <= '9') digits++;
        else if (s[i] == ' ') spaces++;
    }
    cout << "Букв: " << letters << ", цифр: " << digits << ", пробілів: " << spaces << endl;

    char t[256];
    int k = 0;
    for (; s[k] != '\0'; k++) {
        if (s[k] >= 'A' && s[k] <= 'Z') t[k] = s[k] + 32;
        else if (s[k] >= 'a' && s[k] <= 'z') t[k] = s[k] - 32;
        else t[k] = s[k];
    }
    t[k] = '\0';
    cout << "Змінений регістр: " << t << endl;

    cout << "Довжина рядка: " << myStrlen(s) << endl;

    int ws = 0, vowels = 0, consonants = 0, punct = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f') ws++;
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            char l = (c >= 'A' && c <= 'Z') ? c + 32 : c;
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') vowels++;
            else consonants++;
        }
        else if (c >= '!' && c <= '~' && !(c >= '0' && c <= '9')) punct++;
    }
    cout << "Пробільних: " << ws << endl;
    cout << "Голосних: " << vowels << endl;
    cout << "Приголосних: " << consonants << endl;
    cout << "Знаків пунктуації: " << punct << endl;

    return 0;
}