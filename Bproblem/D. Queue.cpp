#include <bits/stdc++.h>

using namespace std;
int arr[10][10];
int v[10];
int main() {

	int t;
	cin >> t;
	while (t--) {
		//memset(vis, -1, sizeof vis);
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			v[i] = i + 1;
		}
		int ans = 1e8;
		do {
			int ret = 0;

			for (int i = 0; i < n-1; i++) {
				if(arr[v[i]][v[i+1]] == 0 )
					ret++;
			}
			ans = min(ret, ans);
		} while (next_permutation(v, v + n));
		cout << ans<< endl;
	}

	return 0;
}
