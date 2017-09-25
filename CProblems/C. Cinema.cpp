#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
map<ll, int> mp;
map<ll, int>::iterator it;
map<ll, int>::iterator it1;
ll temp[200005];
int main() {
	int n, m;
	scanf("%d", &n);
	ll xx;
	for (int i = 0; i < n; i++) {
		cin >> xx;
		it = mp.find(xx);
		if (it == mp.end()) {
			mp[xx] = 1;
		} else {
			mp[xx]++;
		}
	}
	scanf("%d", &m);
	vector<int> inxes;
	int temp1 = -1e6;
	for (int i = 0; i < m; i++) {
		cin >> temp[i];
		it = mp.find(temp[i]);
		int A = it == mp.end() ? 0 : it->s;
		temp1 = max(A,temp1);
	}
	for (int i = 0; i < m; i++) {
		it = mp.find(temp[i]);
		int A = it == mp.end() ? 0 : it->s;
		if (temp1 == A)
			inxes.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> temp[i];
	}
	int linx = inxes[0];
	for (int i = 0; i < (int) inxes.size(); i++) {
		it = mp.find(temp[linx]);
		it1 = mp.find(temp[inxes[i]]);
		int A = it == mp.end() ? 0 : it->s;
		int B = it1 == mp.end() ? 0 : it1->s;
		if (B > A) {
			linx = inxes[i];
		}

	}
	cout << linx + 1 << endl;
	return 0;
}
