#include <iostream>

using namespace std;

string result = "";

void solutionArea(double x, double y) {
    if (y <= 1 && x >= -1 && x <= 1 && x * x + y * y <= 1) {
        result = "YES\n";
    }
    else result = "NO\n";
}

int main()
{
    labelOne:
        cout << "Oberit diyu: " << endl;
        cout << "1. Vvedennya koordinat. " << endl;
        cout << "2. Vivedennya rezultatu. " << endl;
        cout << "3. Vihid. " << endl;
        int n;
        double xPos, yPos;
        cin >> n;
    switch (n)
    {
    case 1:
        cin >> xPos >> yPos;
        solutionArea(xPos, yPos);
        goto labelOne;
        break;
    case 2:
        cout << result;
        goto labelOne;
        break;
    case 3:
        exit(0);
        break;
    default:
        break;
    }
    return 0;
}

