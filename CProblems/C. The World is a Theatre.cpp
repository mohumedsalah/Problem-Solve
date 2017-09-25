#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll C(int n, int m) {
	int temp1 = max(m, n - m);
	int temp2 = min(m, n - m);
	vector<int> a, b;
	for (int i = 1; i <= temp2; i++)
		b.push_back(i);
	for (int i = temp1 + 1; i <= n; i++)
		a.push_back(i);
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			int g = __gcd(b[i], a[j]);
			b[i] /= g;
			a[j] /= g;
			if (b[i] == 1)
				break;
		}
	}
	ll ret = 1;
	for (int i = 0; i < a.size(); i++)
		ret *= a[i];
	return ret;

}

int main() {

	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);
	ll ret = 0;
	for (int i = 4; i <= n; i++) {
		if (i + m >= t && t-i >= 1) {
			ret += C(n,i) * C(m,t-i);
			//cout << ret << endl;
		}
	}
	cout << ret << endl;

	return 0;
}
