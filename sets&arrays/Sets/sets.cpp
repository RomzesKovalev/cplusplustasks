#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> A = {123, 2, 3, 1, 5, 6, 45, 8, 0};
    set<int> B = {4, 0, 55, 6, 1, 123, 82, 9};
    set<int> intersection;

    for (const int& element : A) {
        if (B.find(element) != B.end()) {
            intersection.insert(element);
        }
    }

    cout << "intersection of two sets(A and B): ";
    for (const int& element : intersection) {
        if (element % 2 == 0) {
            cout << element << " ";
        }
    }
    cout << endl;

    return 0;
}