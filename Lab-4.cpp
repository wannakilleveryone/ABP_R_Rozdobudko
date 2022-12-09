#include <iostream>

using namespace std;

int main()
{
    int matrix[9][9];
    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = 0 + rand() % (99 + 0 + 1);
            matrix[i][j] = num;
        }
    }
    cout << "Random matrix: " << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i < 4) {
                int copy = matrix[i][j];
                matrix[i][j] = matrix[8 - i][j];
                matrix[8 - i][j] = copy;
            }
        }
    }
    cout << "Symetric matrix: " << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}