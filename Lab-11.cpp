#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
using namespace std;

class Мужчина {
public:
    string ФИО;
    string дата_рождения;
    string место_рождения;
    Мужчина() {
        ФИО = "Underfined";
        дата_рождения = "Undefined";
        место_рождения = "Undefined";
    }
    Мужчина(string NewФИО, string NewДата, string NewМесто) {
        ФИО = NewФИО;
        дата_рождения = NewДата;
        место_рождения = NewМесто;
    }
    ~Мужчина() {
        cout << "Вызвался деструктор" << endl;
    }
    Мужчина(const Мужчина& other) {
        ФИО = other.ФИО;
        дата_рождения = other.дата_рождения;
        место_рождения = other.место_рождения;
    }
    void SetRik(string NewRik) {
        дата_рождения = NewRik;
    }
    void PrintRik() {
        cout << "Место рождения человека " << ФИО << " " << место_рождения << endl;
    }
    void SetPIB(string NewPIB) {
        ФИО = NewPIB;
    }
    void PrintAllData() {
        cout << "ФИО: " << ФИО << endl;
        cout << "Дата Рождения: " << дата_рождения << endl;
        cout << "Место Рождения: " << место_рождения << endl;
    }
};
class Одружений : public Мужчина {
    string имя_жены;
};
int main() {
    setlocale(LC_ALL, "Rus");
    Мужчина a;
    a.место_рождения = "Кириловка";
    a.SetPIB("Филипп Пирожков");
    a.SetRik("10.01.2002");
    Мужчина b("Андрей Андреевич Андреев", "22.12.1999", "Киев");
    Мужчина c(a);
    cout << c.ФИО << endl;
}