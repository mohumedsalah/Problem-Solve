#include <bits/stdc++.h>

using namespace std;
int B[26];
int A[26];
int main() {
	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);
	string a, b, temp;
	getline(cin, a);
	getline(cin, b);

	if (a == b) {
		cout << "both" << endl;
		return 0;
	}
	if (b.size() <= a.size()) {
		int j = 0;
		int f = 1;
		for (int i = 0; i < b.size(); i++) {
			if (j >= a.size()) {
				f = 0;
				break;
			}
			while (j < a.size() && a[j] != b[i]) {
				j++;
			}
			if (a[j] != b[i]) {
				f = 0;
				break;
			}
			j++;
		}
		if (f) {
			cout << "automaton" << endl;
			return 0;;
		}
	}
	for (int i = 0; i < b.size(); i++) {
		B[b[i] - 97]++;
	}
	for (int i = 0; i < a.size(); i++) {
		A[a[i] - 97]++;
	}
	if (b.size() == a.size()) {
		int f = 1;
		for (int i = 0; i < 26; i++) {
			if (A[i] != B[i]) {
				f = 0;
				break;
			}
		}
		if (f) {
			cout << "array" << endl;
			return 0;
		}
	} else {

		int f = 1;
		for (int i = 0; i < 26; i++) {
			if (A[i] >= B[i])
				continue;
			f = 0;
			break;
		}
		if (f) {
			cout << "both" << endl;
			return 0;
		}
	}
	cout << "need tree" << endl;
	return 0;
}
