#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<string, int> mp1;
map<string, int>::iterator it;
int main() {

	//freopen("in.txt", "r", stdin);
	//vector<int> vv;
	string in;
	int n, m, cnt = 0;
	while (cin >> n) {
		mp1.clear();
		mp.clear();
		cin >> m;
		getchar();
		for (int i = 0; i < n; i++) {
			getline(cin, in);
			mp[in]++;
		}
		int mx = 0;
		for (int i = 0; i < m; i++) {
			getline(cin, in);
			string tt = in;
			stringstream sin(in);
			int temp = 0;
			while (sin >> in) {
				//in = solve(in);
				string ret = "";
				for (int i = 0; i < in.size(); i++) {
					in[i] = tolower(in[i]);
					if (in[i] <= 'z' && in[i] >= 'a') {
						ret += in[i];
						continue;
					}
					it = mp.find(ret);
					if (it != mp.end()) {
						temp++;
					}
					ret = "";
				}
				it = mp.find(ret);
				if (it != mp.end()) {
					temp++;
				}
				//ret = "";

			}
			mp1[tt] += temp;
			mx = max(mx, temp);
		}
		printf("Excuse Set #%d\n", ++cnt);
		for (it = mp1.begin(); it != mp1.end(); it++) {
			//cout << it->second << endl;
			if (it->second == mx) {
				cout << it->first << endl;
			}
		}
		cout << endl;
	}
}
