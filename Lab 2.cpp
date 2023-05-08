#include <iostream>
#include <cmath>
#include <random>
#include <vector>

using namespace std;
void zavd_1();
void zavd_2();
void zavd_3();
void zavd_4();

int main()
{
	int choice = 0;
	cout << "Oberit zavdannya.\n 1 - Zavdannya 1\n 2 - Zavdannya 2\n 3 - Zavdannya 3\n 4 - Zavdannya 4 \n";
	cin >> choice;

	switch (choice)
	{
	case 1: 
		zavd_1();
		break;
	case 2:
		zavd_2();
		break;
	case 3:
		zavd_3();
		break;
	case 4:
		zavd_4();
		break;
	default:
		break;
	}
}

void zavd_1() {
	cout << "Vvedit kilkist elementiv: ";
	int N;
	int rZero = -1, lZero = -1;
	cin >> N;

	int arr[500];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int temp = -10 + rand() % (21);
		arr[i] = temp;
	}

	cout << "Masiv: \n";
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	long long mult = 1;
	long long sum = 0;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			mult *= arr[i];
		}
	}
	cout << "Dobutok elementiv na parnih pos: " << mult << "\n";
	for (int i = 0; i < N; i++) {
		if (arr[i] == 0) {
			lZero = i;
			break;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] == 0) {
			rZero = i;
			break;
		}
	}
	if (lZero == -1 || rZero == -1) {
		cout << "Nuli vidsutni";
	}
	else if (lZero == rZero) {
		cout << "Odin nul";
	}
	else {
		for (int i = lZero; i < rZero; i++) {
			sum += arr[i];
		}
		cout << "Suma mizh nulyami: " << sum;
	}
}

void zavd_2() {
	cout << "Vvedit kilkist elementiv: ";
	int N;
	cin >> N;

	int arr[500];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int temp = -10 + rand() % (21);
		arr[i] = temp;
	}

	cout << "Masiv: \n";
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	vector <int> result;
	for (int i = 0; i < N; i++) {
		if (arr[i] >= 0) {
			result.push_back(arr[i]);
		}
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] < 0) {
			result.push_back(arr[i]);
		}
	}
	cout << "Resultat sortuvannya: \n";
	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
}

void zavd_3() {
	cout << "Vvedit rozmir pryamokutnoi matrici: \n";
	int n, m;
	cin >> n >> m;
	int arr[500][500];
	memset(arr, 0, sizeof(arr));
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = -10 + rand() % (21);
			arr[i][j] = temp;
		}
	}


	cout << "Matrica:  \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	int countColumn = 0, longestSequence = 1, indexOfLongestSequence = -1, maxLongest = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 0) {
				countColumn++;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				longestSequence++;
			}
			else {
				if (longestSequence > maxLongest) {
					maxLongest = longestSequence;
					indexOfLongestSequence = i;
				}
				longestSequence = 1;
			}
		}
		if (longestSequence > maxLongest) {
			maxLongest = longestSequence;
			indexOfLongestSequence = i;
		}
		longestSequence = 1;
	}

	cout << "Kilkist stovpciv iz 0: " << countColumn << "\n";
	cout << "Ryadok iz naydovshuyu posl. odn. elementiv: " << indexOfLongestSequence;
}

void zavd_4() {
	cout << "Vvedit rozmir kvadratnoi matrici: \n";
	int n;
	cin >> n;
	int arr[500][500];
	memset(arr, 0, sizeof(arr));
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j < n - 1 && i < j) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = 0;
			}
		}
	}

	cout << "Matrica:  \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

