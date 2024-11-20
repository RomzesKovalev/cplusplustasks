#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int A[size] = { 12, 7, 9, 4, 10 };
    int B[size] = { 3, 8, 5, 6, 2 };
    int minA = A[0];
    int minB = B[0];
    for (int i = 1; i < size; i++) {
        if (A[i] < minA) {
            minA = A[i];
        }
    }

    for (int i = 1; i < size; i++) {
        if (B[i] < minB) {
            minB = B[i];
        }
    }

    cout << "Array A: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }

    cout << endl;

    cout << "New array A: ";
    for (int i = 0; i < size; i++) {
        cout << (A[i] * minA) << " ";
    }

    cout << endl;

    cout << "Array B: ";
    for (int i = 0; i < size; i++) {
        cout << B[i] << " ";
    }

    cout << endl;

    cout << "New array B: ";
    for (int i = 0; i < size; i++) {
        cout << (B[i] * minB) << " ";
    }

    cout << endl;

    return 0;
}