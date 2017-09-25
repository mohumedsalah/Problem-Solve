#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {

	int a, b;
	cin >> a >> b;
	int g = __gcd(a, b);
	a /= g, b /= g;
	if (abs(a - b) > 1) {
		cout << (a > b ? "Masha" : "Dasha");
	} else {
		cout << "Equal";
	}

	return 0;
}
