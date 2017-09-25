#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a2, b2, a3, b3, a5, b5;
int main() {

	int a, b;
	scanf("%d%d", &a, &b);

	while (a % 2 == 0 || b % 2 == 0) {
		if (a % 2 == 0)
			a /= 2, a2++;
		if (b % 2 == 0)
			b /= 2, b2++;
	}
	while (a % 3 == 0 || b % 3 == 0) {
		if (a % 3 == 0)
			a /= 3, a3++;
		if (b % 3 == 0)
			b /= 3, b3++;
	}
	while (a % 5 == 0 || b % 5 == 0) {
		if (a % 5 == 0)
			a /= 5, a5++;
		if (b % 5 == 0)
			b /= 5, b5++;
	}
	if(a != b)puts("-1");
	else
		cout << abs(a2- b2) +abs( a3- b3)+abs(a5-b5);
	return 0;
}
