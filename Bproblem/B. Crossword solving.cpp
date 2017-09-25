//salahooooooooooooooooooooo
//maxeeeeeeeeeeeeeeeez

#include <bits/stdc++.h>
//sllllllll>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<
using namespace std;
vector<int> v;
int main() {
	//sllllllll>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	string s, t;
	getline(cin, s);
	getline(cin, t);
	string aa;
	int ans = 1e7;
	for (int i = 0; i < m; i++) {
		//sllllllll>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<
		aa = t.substr(i, n);
		//sllllllll>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<
		if (aa.size() == s.size()) {
			int ret = 0;
			for (int j = 0; j < n; j++) {
				if (aa[j] == s[j])
					continue;
				ret++;
			}
			if (ret <= ans) {
				ans = ret;
				v.clear();
				for (int j = 0; j < n; j++) {
					if (aa[j] == s[j])
						continue;
					v.push_back(j + 1);
				}
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < (int)v.size(); i++)
		printf("%d ", v[i]);

	return 0;
}
