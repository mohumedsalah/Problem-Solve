#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
	ll a, b, xx;
	int n;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> xx ;
		cout << ((a * xx) % b ) / a << " ";
	}
	return 0;
}
