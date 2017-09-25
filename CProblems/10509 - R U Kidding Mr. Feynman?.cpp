#include <bits/stdc++.h>
using namespace std;
int main() {

	double n;
	while (cin >> n && n != 0) {
		long long a = cbrt(n);
		//cout << a << endl;
		double ret = (double)a + (n - (a * a * a)) / (3 * a * a);
		cout <<fixed<< setprecision(4) << ret << endl;
	}
	return 0;
}
