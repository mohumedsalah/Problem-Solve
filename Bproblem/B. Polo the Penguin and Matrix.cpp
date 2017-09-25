#include <bits/stdc++.h>

using namespace std;
int n, m, d;
int arr[10010];
int main() {

	cin >> n >> m >> d;
	for (int i = 0; i < n * m; i++) {
		cin >> arr[i];
	}
	n = n * m;
	long long ret = 1e16;
	int temp;
	for (int i = 0; i < n; i++) {
		long long ans = 0;
		for (int j = 0; j < n; j++) {
			temp = arr[i];
			if (temp == arr[j])
				continue;
			if (temp < arr[j]) {
				if ((arr[j] - temp) % d == 0) {
					ans += (arr[j] - temp) / d;
				} else {
					ans += 1e6;
					break;
				}
			} else {
				if ((temp - arr[j]) % d == 0) {
					ans += (temp - arr[j]) / d;
				} else {
					ans += 1e6;
					break;
				}
			}

		}
		ret = min(ret,ans);
	}
	if(ret >= 1e16)
		cout << -1 << endl;
	else
		cout << ret<<endl;
	return 0;
}
