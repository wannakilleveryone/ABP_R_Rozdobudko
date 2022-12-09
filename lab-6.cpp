#include <iostream>

using namespace std;

int matrix[1000][1000];
int N;

void Init(int(*matrix)[1000], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = -50 + rand() % (50 + 50 + 1);
            matrix[i][j] = num;
        }
    }
}

void print(int(*matrix)[1000], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(int(*matrix)[1000], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(matrix[i][j], matrix[i][N - j - 1]);
        }
    }
}

int main()
{
    cout << "Vvedit rozmir: ";
    cin >> N;
    Init(matrix, N);
    print(matrix, N);
    cout << "Clockwise: " << endl;
    rotate(matrix, N);
    print(matrix, N);
}