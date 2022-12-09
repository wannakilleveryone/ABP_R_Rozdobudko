#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[200];
    int result[200] = { 0 };
    srand(time(NULL));
    for (int i = 0; i < 200; i++) {
        int num = -100 + rand() % (100 + 100 + 1);
        arr[i] = num;
    }
    cout << "Nash masiv: " << endl;
    for (int i = 0; i < 200; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 200; i++) {
        if (arr[i] <= 0) {
            result[i] = arr[i];
        }
        else {
            int minNumber = arr[i], maxNumber = arr[i], countOfNumbers = 0, sumOfNumbers = 0;
            vector <int> copy;
            while (arr[i] > 0 && i < 200) {
                countOfNumbers++;
                sumOfNumbers += arr[i];
                if (arr[i] > maxNumber) maxNumber = arr[i];
                if (arr[i] < minNumber) minNumber = arr[i];
                copy.push_back(arr[i]);
                i++;
            }
            int med = sumOfNumbers / countOfNumbers;
            for (int j = 0; j < copy.size(); j++) {
                if (copy[j] == maxNumber || copy[j] == minNumber) copy[j] = med;
            }
            int k = 0;
            for (int j = i - countOfNumbers; j < i; j++) {
                result[j] = copy[k];
                k++;
            }
            i--;
        }
    }
    for (int i = 0; i < 200; i++) {
        cout << result[i] << " ";
    }
}
