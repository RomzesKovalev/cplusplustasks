#include <iostream>
#include <set>
using namespace std;
int main() {
	set<int> A = {5, 0, 12, 50, 4};
	set<int> B = {5};
	set<int> intersection;
	for (const int& element : A) {
		if (B.find(element) != B.end()) {
			intersection.insert(element);
		}
	}
	if (intersection.empty()) {
		cout <<"No intersection";
	}
	else {
		cout << "intersection of two sets (A and B): ";
		for (const int& element : intersection) {
			if (element % 2 == 0) {
				cout << element << " "; 
			}
			else {
				cout << "None" << endl;
			}
		}
	}
	cout << endl;
	return 0;
}
