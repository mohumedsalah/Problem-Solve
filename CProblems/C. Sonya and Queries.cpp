#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<string, int>::iterator it;
string xx, yy;
char xxx[25], yyy[25];
int main() {
	string t = "0000000000000000000";
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s = t;
		scanf("%s %s",xxx, yyy);
		xx = xxx, yy = yyy;
		if (xx == "+") {
			reverse(yy.begin(), yy.end());
			for (int i = 0; i < (int) yy.size(); i++) {
				if ((yy[i] - '0') % 2 == 0)
					s[i] = '0';
				else
					s[i] = '1';
			}
			//cout << s << endl;
			mp[s]++;
		} else if (xx == "-") {
			reverse(yy.begin(), yy.end());
			for (int i = 0; i < (int) yy.size(); i++) {
				if ((yy[i] - '0') % 2 == 0)
					s[i] = '0';
				else
					s[i] = '1';
			}
			mp[s]--;
		} else {
			int ans = 0;
			reverse(yy.begin(), yy.end());
			for (int i = 0; i < (int) yy.size(); i++) {
				if ((yy[i] - '0') % 2 == 0)
					s[i] = '0';
				else
					s[i] = '1';
			}
			ans += mp[s];
			printf("%d\n", ans);
		}
	}
	return 0;
}
