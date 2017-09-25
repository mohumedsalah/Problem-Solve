#include <bits/stdc++.h>

using namespace std;

int pret[1010];
int a[1010];
int b[1010];
int difinx[1010];
int vis[101];
int n;
int main() {
	memset(vis, 0, sizeof vis);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	//sort(a, a+n);
	//fsort(b, b+n);
	int at = -1, bt = -1, dif = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			pret[i] = a[i];
			vis[pret[i]] = 1;
		} else {
			dif++;
			if (dif == 1) {
				at = i;
			} else {
				bt = i;
			}
		}
	}
	if (dif == 1) {
		for (int i = 1; i < 1010; i++) {
			if (i != a[at] && i != b[at] && vis[i] == 0) {
				pret[at] = i;
				break;
			}
		}
	}
	if (dif == 2) {
		if (vis[a[at]] == 0 && vis[b[bt]] == 0) {
			pret[at] = a[at];
			pret[bt] = b[bt];
		} else {
			pret[at] = b[at];
			pret[bt] = a[bt];
		}
	}
	for (int i = 0; i < n; i++)
		cout << pret[i] << " ";
	cout << endl;
	return 0;
}
