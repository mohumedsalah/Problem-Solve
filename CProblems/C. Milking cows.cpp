#include <bits/stdc++.h>

using namespace std;
int const mx = 1e5 * 2 + 5;
char arr[mx];
int s[mx];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] == '1') {
			s[i] = s[i - 1] + 1;
		} else {
			s[i] = s[i - 1];
		}
	}
	long long ret = 0;
	for (int i = n; i >= 1; i--) {
		if(arr[i] == '0')
			ret += s[i];
	}
	cout << ret;
	return 0;
}
