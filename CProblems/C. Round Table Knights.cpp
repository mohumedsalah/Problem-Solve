#include <bits/stdc++.h>
using namespace std;
int const mx = 1e5 + 6;
char arr[mx];
vector<int> vv;
int n;
bool che(int x) {
	for (int i = 1; i <= x; i++) {
		int f = 1;
		for (int j = i; j <= n; j += x) {
			if (arr[j] == '0')
				f = 0;
		}
		if (f)
			return 1;
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	vv.push_back(1);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 1; i * 2 < n; i++) {
		if (ceil(double(n) / i) != floor(double(n) / i))
			continue;
		else {
			if (che(i)) {
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}
