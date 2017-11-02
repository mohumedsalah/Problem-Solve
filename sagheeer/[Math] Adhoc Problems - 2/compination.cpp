//============================================================================
// Name        : mm.cpp

// Author      : fff

// Version     :

// Copyright   : Your copyright notice

// Description : Hello World in C++, Ansi-style

//============================================================================

#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
long long unsigned solve(int n, int k) {

	vector<int> a;
	vector<int> b;
	int ln = (k < n - k) ? (n - k) : k;
	int ld = (k < n - k) ? k : n - k;
	for (int i = ln + 1; i <= n; i++)
		a.push_back(i);
	for (int i = 1; i <= ld; i++)
		b.push_back(i);
	for (int i = 0; i < ld; i++)
		for (int j = 0; j < a.size(); j++) {
			int g = gcd(b[i], a[j]);
			b[i] /= g;
			a[j] /= g;
			if (b[i] == 1)
				break;
		}
	long long unsigned ret = 1;
	for (int i = 0; i < a.size(); i++) {
		ret *= a[i];
	}
	return ret;

}

int main() {

	int m, n;
	while (cin >> m >> n && (n | m)) {
		long long unsigned ret = solve(m, n);

		cout << m << " things taken " << n << " at a time is " << ret
				<< " exactly." << endl;

	}
	return 0;

}

