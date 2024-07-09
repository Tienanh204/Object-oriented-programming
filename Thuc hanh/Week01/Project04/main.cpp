#include"main.h"

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void RandomIntegers() {
    srand(time(nullptr));

    int n;
    do {
        n = rand() % 11 + 10;
    } while (n < 10 || n > 20);

    vector<int> result;
    for (int i = 0; i < n; ++i) {
        int number;
        do {
            number = rand() % 100 + 1;
        } while (number < 1 || number > 100);
        result.push_back(number);
    }

    cout << "Generated integers in A[]: ";
    int cntEven = 0;
    for (int x : result) {
        cout << x << " ";
        if (x % 2 == 0) {
            cntEven++;
        }
    }
    cout << endl;
    cout << "Even and odd numbers in A[]: " << cntEven << " " << n - cntEven << endl;

    cout << "Prime numbers in A[]: ";
    for (int x : result) {
        if (isPrime(x)) {
            cout << x << " ";
        }
    }
}

int main() {
    RandomIntegers();
    return 0;
}