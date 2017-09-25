#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	while ((!(n % 3)) && n != 0)
		n /= 3;
	printf("%I64d\n", n / 3 + 1);
	return 0;
}
