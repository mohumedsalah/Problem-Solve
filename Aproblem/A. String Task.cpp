#include <bits/stdc++.h>

using namespace std;
bool vis[110];
int main() {
	//cout << 97 - 65 << endl;
	string n;
	cin >> n;
	int x = n.size();
	char vol[] = { 'a', 'o', 'y', 'e', 'u', 'i' };
	for (int j = 0; j < x; j++) {
		n[j] = tolower(n[j]);
		int f = 1;
		for (int i = 0; i <= 5; i++) {
			if (n[j] == vol[i]) {
				f = 0;
				break;
			}
		}
		vis[j] = f;
	}
	for (int i = 0; i < x; i++)
		if (vis[i] == 1)
			cout << '.' << n[i];
	return 0;
}
