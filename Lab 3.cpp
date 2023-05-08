#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct School {
    string name;
    int group;
    int subject[5];
};

vector <School> learner;

void inputStudents();
void sortByName();
bool compare(School a, School b);
void lowLevelStudents();

int main()
{
    int change;
label:
        cout << "Oberit. 1 - Vvesti studentiv, 2 - Sortuvati, 3 - Dviyochniki \n";
        cin >> change;
        switch (change)
        {
        case 1:
            inputStudents();
            goto label;
            break;
        case 2:
            sortByName();
            goto label;
            break;
        case 3:
            lowLevelStudents();
            goto label;
            break;
        default:
            break;
        }
}

void inputStudents() {
    cout << "Vvedit kilkist studentiv: ";
    int N;
    cin >> N;
    cout << "Vvedit informaciyu pro studentiv.\n";
    for (int i = 0; i < N; i++) {
        School temp;
        cout << i + 1 << " Vvedit prizvische ta imya studenta\n";
        cin >> temp.name;
        cout << "Teper vvedit nomer grupi: ";
        cin >> temp.group;
        cout << "Vvedit cherez propusk jcinki z 5 predmetiv: \n";
        for (int j = 0; j < 5; j++) {
            cin >> temp.subject[j];
        }
        learner.push_back(temp);
    }
}

bool compare(School a, School b) {
    return a.name < b.name;
}

void sortByName() {
    cout << "Studenti do sortuvannya: \n";
    for (int i = 0; i < learner.size(); i++) {
        cout << "Imya: " << learner[i].name << " Grupa: " << learner[i].group << " Ocinki: ";
        for (int j = 0; j < 5; j++) cout << learner[i].subject[j] << " ";
        cout << endl;
    }
    for (int j = 0; j < learner.size() - 1; j++) {
        for (int k = 0; k < learner.size() - 1 - j; k++) {
            if (learner[k].name > learner[k + 1].name) {
                swap(learner[k], learner[k + 1]);
            }
        }
    }
    cout << "Studenti pislya sortuvannya: \n";
    for (int i = 0; i < learner.size(); i++) {
        cout << "Imya: " << learner[i].name << " Grupa: " << learner[i].group << " Ocinki: ";
        for (int j = 0; j < 5; j++) cout << learner[i].subject[j] << " ";
        cout << endl;
    }
}

void lowLevelStudents() {
    cout << "Studenti yaki mayut dviyki: \n";
    bool check = true;
    for (auto i : learner) {
        for (int j = 0; j < 5; j++) {
            if (i.subject[j] <= 2) {
                cout << "Name: " << i.name << "\n";
                check = false;
                break;
            }
        }
    }
    if (check) {
        cout << "Takih studentiv nemae";
    }
}
