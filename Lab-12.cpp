#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <>
using namespace std;

class Ведомость {
public:
    string type;
    string number;
    double length;
    int time;
    void Show() {
        printf("%s          |\t  %c        |\t  %.2f         |\t  %d\n", type, number, length, time);
        printf("|---------------------------------------------------------------------------------|\n");
    }
    void Set() {
        printf("Введiть прiзвище, код, бали, мiсце для першого учасника: ");
        scanf("%s %c %f %hd", &type, &number, &length, &time);
    }
    Ведомость& operator=(const Ведомость& right) {
        if (this == &right) {
            return *this;
        }
        length = right.length;
        strcpy(type, right.type);
        number = right.number;
        time = right.time;
        return *this;
    }
    const Ведомость& operator+(const Ведомость& other) {
        Ведомость temp;
        temp.length = length + other.length;
        temp.time = time + other.time;
        temp.number = number + other.number;
        return temp;
    }
    bool operator==(const Ведомость& right) {
        return ((time == right.time) && (number == right.number) && (length == right.length));
    }
    friend ostream& operator<< (ostream& out, const Ведомость& temp)
    {
        out << temp.type << " " << temp.number << " " << temp.length << " " << temp.time << endl;
        cout << "|---------------------------------------------------------------------------------|\n";
        return out;
    }
    friend istream& operator>> (istream& in, Ведомость& temp)
    {
        in >> temp.type >> temp.length >> temp.number >> temp.type;
        return in;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    int size;
    cout << "Сколько ведомостей: "; cin >> size;
    Ведомость* a = new Ведомость[size];
    for (int i = 0; i < size; i++) {
        a[i].Set();
    }
    printf("|---------------------------------------------------------------------------------|\n");
    printf("Вiдомiсть спортивних змагань\n");
    printf("|---------------------------------------------------------------------------------|\n");
    printf("Прiзвище учасника  |  Код команди  |  Кiлькiсть балiв    |    Мiсце в результатi\n");
    printf("|---------------------------------------------------------------------------------|\n");
    for (int i = 0; i < size; i++) {
        a[i].Show();
    }
    printf("|Примітка: Тр – трамвай, Тс – тролейбус, А – автобус                 |\n");
    printf("|---------------------------------------------------------------------------------|\n");
}