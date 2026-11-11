#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 1. Пошук кількості пар за допомогою стандартних функцій C
int Count(char* s)
{
    int k = 0;
    int pos = 0;
    char* t;

    // Шукаємо першу з букв 'a', 'b' або 'c' у рядку
    while ((t = strpbrk(s + pos, "abc")) != nullptr)
    {
        pos = t - s; // Позиція знайденої літери
        // Перевіряємо, чи наступний символ такий самий
        if (s[pos + 1] == *t)
        {
            k++;
            pos += 2; // Переходимо за пару
        }
        else
        {
            pos += 1; // Пропускаємо одиночний символ
        }
    }
    return k;
}

// 2. Заміна пар на "***" за допомогою стандартних функцій C
char* Change(char* s)
{
    // 2 символи міняються на 3, виділяємо пам'ять із запасом
    char* t = new char[strlen(s) * 3 / 2 + 1];
    char* p;
    int pos1 = 0;
    int pos2 = 0;
    *t = '\0';

    while ((p = strpbrk(s + pos1, "abc")) != nullptr)
    {
        int found_pos = p - s;
        if (s[found_pos + 1] == *p) // Знайдено пару "aa", "bb" або "cc"
        {
            pos2 = found_pos + 2;
            strncat(t, s + pos1, found_pos - pos1); // Копіюємо текст до пари
            strcat(t, "***");                       // Вставляємо "***"
            pos1 = pos2;
        }
        else
        {
            pos2 = found_pos + 1;
            strncat(t, s + pos1, pos2 - pos1); // Копіюємо текст включно з цією літерою
            pos1 = pos2;
        }
    }
    strcat(t, s + pos1); // Докопійовуємо залишок рядка

    strcpy(s, t);
    return t;
}

#ifndef UNIT_TESTING
int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " pairs of 'aa', 'bb' or 'cc'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
#endif