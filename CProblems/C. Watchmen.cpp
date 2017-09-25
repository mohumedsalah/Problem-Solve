#include <bits/stdc++.h>

using namespace std;
map<long long, int> a;
map<long long, int> b;
map<long long, int>::iterator ita;
map<long long, int>::iterator itb;
map<pair<long long, long long>, int> mp;
map<pair<long long, long long>, int>::iterator it;
int main() {
	int n;
	cin >> n;
	long long xx, yy;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> xx >> yy;
		ita = a.find(xx);
		itb = b.find(yy);
		it = mp.find(make_pair(xx, yy));
		if (it != mp.end()) {
			mp[make_pair(xx, yy)]++;
		} else {
			mp[make_pair(xx, yy)] = 1;
		}
		if (ita == a.end()) {
			a[xx] = 1;
		} else {
			a[xx]++;
		}

		if (itb == b.end()) {
			b[yy] = 1;
		} else {
			b[yy]++;
		}
	}
	for (it = mp.begin(); it != mp.end(); it++) {
		ans -= (long long)it->second * (it->second - 1) / 2;
	}
	for (map<long long, int>::iterator ta = a.begin(); ta != a.end(); ta++) {
		//cout << ta->second << endl;
		ans += (long long)ta->second * (ta->second - 1) / 2;
	}
	//cout << ans << endl;
	for (map<long long, int>::iterator tb = b.begin(); tb != b.end(); tb++) {
		//cout << tb->second << endl;
		ans += (long long)tb->second * (tb->second - 1) / 2;
	}
	if(ans < 0)
		puts("0");
	else
		cout << ans << endl;
	return 0;
}
