#include <bits/stdc++.h>
using namespace std;
bool solve(int &a, int &b) {
	if (ceil(double(b) / 2) - 1 != a)
		return 0;
	while (a || b) {
		if (b) {
			cout << "1";
			b--;
		}
		if (b) {
			cout << "1";
			b--;
		}
		if (a) {
			cout << "0";
			a--;
		}
	}
	return 1;
}
int main() {
	int a, b;
	cin >> a >> b;
	int mn = ceil(double(b) / 2) - 1;
	int mx = b + 1;
	if (a > mx || a < mn) {
		cout << -1 << endl;
		return 0;
	}
	if (a > b) {
		while (a || b) {
			if (a) {
				cout << "0";
				a--;
			}
			if (b) {
				cout << "1";
				b--;
			}
		}
		return 0;
	}
	while (a || b) {
		if (!solve(a, b)) {
			if (b) {
				cout << "1";
				b--;
			}
			if (a) {
				cout << "0";
				a--;
			}
		}else{
			break;
		}
	}
	return 0;
}
