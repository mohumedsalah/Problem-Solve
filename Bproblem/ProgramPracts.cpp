#include <bits/stdc++.h>

using namespace std;
//salahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
//Maxxxeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
int main() {
	bool r[5], l[5], sr[5], p[5];
	for (int i = 1; i <= 4; i++) {
		cin >> l[i] >> sr[i] >> r[i] >> p[i];
	}
	for (int i = 1; i <= 4; i++) {
		if (p[i]) {
			int a = (i + 2) % 4 == 0 ? 4 : (i + 2) % 4;
			int b = (i + 1) % 4 == 0 ? 4 : (i + 1) % 4;
			int c = (i + 3) % 4 == 0 ? 4 : (i + 3) % 4;
			if (l[i] || r[i] || sr[i] || sr[a] || l[b] || r[c]) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
