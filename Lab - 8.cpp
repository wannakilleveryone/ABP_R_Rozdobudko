#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct Stack {
    string type;
    string number;
    double way;
    long long time;
};

vector <Stack> st;

void push(Stack elem) {
    st.push_back(elem);
}

void top() {
    if (st.size() != 0) {
        cout << st[0].type << " " << st[0].number << " " << st[0].way << " " << st[0].time;
    }
    else cout << "Stack is empty";

}

void empty() {
    if (st.size()) cout << 1;
    else cout << 0;
}

void pop() {
    if (st.size() != 0) st.erase(st.begin());
    else cout << "Stack is empty";
}

int main()
{
    setlocale(LC_ALL, "");
    cout << "Vvedit kilkist: ";
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << "Vvedit vid trans, nomer, dovzhinu, chas u dorozi: ";
        Stack temp;
        cin >> temp.type >> temp.number >> temp.way >> temp.time;
        push(temp);
    }
    string message = "--------------------------------------------------------------------\n";
    message += "|Відомість громадського транспорту                                   |\n";
    message += "--------------------------------------------------------------------\n";
    message += "|Вид транспорту|№ маршруту  |Протяжність маршруту | Час у дорозі     |\n";
    message += "--------------------------------------------------------------------\n";
    for (int i = st.size() - 1; i >= 0; i--) {
        message += ('|' + st[i].type + "            |" + st[i].number + "          |" + to_string(st[i].way) + "                |" + to_string(st[i].time) + "           |\n");
    }
    message += "--------------------------------------------------------------------\n";
    message += "|Примітка: Тр – трамвай, Тс – тролейбус, А – автобус                 |\n";
    message += "--------------------------------------------------------------------";
    cout << message;
}

