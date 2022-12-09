//Варіант 22
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double eps = 0.000001, s = -2 / 3;
    int n = 2;
    while (fabs(s) > eps) {
        s += (pow(-1, n) * (1 - (pow(n, 3) + 1) / (pow(n, 3) + 5)));
        n++;
    }
    double s10 = 0.0;
    for (int i = 1; i <= 10; i++) {
        s10 += (pow(-1, n) * (1 - (pow(n, 3) + 1) / (pow(n, 3) + 5)));
    }
    cout << "Suma: " << fixed << setprecision(7) << s << " Suma 10: " << setprecision(7) << s10;
}
