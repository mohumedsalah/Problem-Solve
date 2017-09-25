#include <bits/stdc++.h>
using namespace std;
vector<string> vv;
vector<string> ret;
vector<bool> vis;
char arr[100];
string xx;
bool che(string a, string b) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		int f = 0;
		for (int j = 0; j < n; j++) {
			if (tolower(a[i]) == tolower(b[j])) {
				f = 1;
				b[j] = '?';
				break;
			}
		}
		if (!f)
			return false;
	}
	return true;
}
int main() {
	while (true) {

		scanf("%s", arr);
		if (arr[0] == '#')
			break;
		xx = arr;
		vv.push_back(xx);
		vis.push_back(1);
	}
	int n = vv.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || vv[i].size() != vv[j].size() || vis[j] == 0)
				continue;
			if (che(vv[i], vv[j])) {
				vis[i] = 0;
				vis[j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if(vis[i]){
			ret.push_back(vv[i]);
		}
	}
	n = ret.size();
	sort(ret.begin(), ret.end());
	for(int i = 0; i < n ;i++)
		printf("%s\n",ret[i].c_str());
	return 0;
}
