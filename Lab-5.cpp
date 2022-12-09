#include <iostream>

using namespace std;

int main()
{
    int N;
    int arr[1000];
    cout << "Vvedit kilkist: ";
    cin >> N;
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int num = -50 + rand() % (50 + 50 + 1);
        arr[i] = num;
    }
    cout << "Random array: " << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    int countDupl = 0;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] == arr[i + 1]) countDupl++;
    }
    cout << "\nKilkist: " << countDupl;
}