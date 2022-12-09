#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>

using namespace std;

struct transport {
    string type;
    string number;
    double length;
    int time;
};

bool comp(transport a, transport b) {
    return a.type < b.type;
}

int main()
{
    setlocale(LC_ALL, "");
    vector <transport> dataBase;
    int N;
    cout << "Vvedit kilkist danih: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << "\nVvedit tip transportu: ";
        transport temp;
        cin >> temp.type;
        cout << "\nVvedit # marshrutu: ";
        cin >> temp.number;
        cout << "\nVvedit dovzhinu marshrutu: ";
        cin >> temp.length;
        cout << "\nVvedit chas v dorozi: ";
        cin >> temp.time;
        dataBase.push_back(temp);
    }

    sort(dataBase.begin(), dataBase.end(), comp);

    cout << "\nTablicya: \n";
    string message = "--------------------------------------------------------------------\n";
    message += "|Відомість громадського транспорту                                   |\n";
    message += "--------------------------------------------------------------------\n";
    message += "|Вид транспорту|№ маршруту  |Протяжність маршруту | Час у дорозі     |\n";
    message += "--------------------------------------------------------------------\n";
    for (int i = 0; i < N; i++) {
        message += ('|' + dataBase[i].type + "            |" + dataBase[i].number + "          |" + to_string(dataBase[i].length) + "                |" + to_string(dataBase[i].time) + "           |\n");
    }
    message += "--------------------------------------------------------------------\n";
    message += "|Примітка: Тр – трамвай, Тс – тролейбус, А – автобус                 |\n";
    message += "--------------------------------------------------------------------";
    cout << message;
}
