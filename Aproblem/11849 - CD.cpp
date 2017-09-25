#include <bits/stdc++.h>

using namespace std;
int const mx = 1e6 + 9;
map<long long, bool> mp;
map<long long, bool>::iterator it;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, ret;
	long long xx;
	while (cin >> n >> m && (n || m)) {
		ret = 0;
		mp.clear();
		for (int i = 0; i < n + m; i++) {
			scanf("%lld", &xx);
			it = mp.find(xx);
			if (it == mp.end())
				mp[xx] = 1;
			else
				ret++;
		}
		printf("%d\n", ret);
	}

	return 0;
}
