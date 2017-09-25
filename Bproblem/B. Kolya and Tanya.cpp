#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int arr[105][105];
int main() {
	memset(arr, 0, sizeof arr);
	int n, k;
	cin >> n >> k;
	int num = 0;
	int f = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (f != 0) {
				if (j % 2 != 0) {
					arr[i][j] = 1;
					num++;
					if (num == k)
						goto ff;
				}
			} else {
				if (j % 2 == 0) {
					arr[i][j] = 1;
					num++;
					if (num == k)
						goto ff;
				}
			}

		}
		f = !f;
	}
	ff: if (num < k)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;

		if (k == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					cout << "S";
				cout << endl;
			}
			return 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j])
					cout << "L";
				else
					cout << "S";
			}
			cout << endl;
		}
	}
	return 0;
}
