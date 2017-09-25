#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("unit.in","r",stdin);
	int t;
	cin >> t;
	while (t--) {
		long long a, b, c, ret;
		cin >> a >> b >> c;
		ret = solve(a,b,c);
		cout << ret << endl;
	}

	return 0;
}
