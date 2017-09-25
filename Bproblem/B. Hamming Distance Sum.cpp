#include <bits/stdc++.h>

using namespace std;
int ones[200005];
int zeros[200005];
int main() {

	string a;
	string b;
	cin >> a >> b;
	for (int i = b.size() - 1; i >= 0; i--) {
		zeros[i] = zeros[i + 1];
		ones[i] = ones[i + 1];
		if (b[i] == '0')
			zeros[i]++;
		else
			ones[i]++;
	}
	long long ret = 0;
	int sz = b.size() - a.size() + 1;
	for (int i = 0; i < (int) a.size(); i++) {
		if (a[i] == '0') {
			if (sz <= 200004)
				ret += ones[i] - ones[sz];
			else
				ret += ones[i];
		} else {
			if (sz <= 200004)
				ret += zeros[i] - zeros[sz];
			else
				ret += zeros[i];
		}
		sz++;
	}
	cout << ret << endl;

	return 0;
}
