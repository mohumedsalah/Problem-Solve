#include <bits/stdc++.h>
using namespace std;
struct Node {
	string s;
	int n;
};
bool cmp(Node i, Node j) {
	if (i.n != j.n)
		return i.n > j.n;
	return i.s.compare(j.s) < 0;
}
int main() {
	//freopen("coaches.in", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		string proj, name;
		map<string, string> stu;
		map<string, set<string> > coat;
		int n;
		cin >> n;

		stu[""] = "-1";
		getchar();
		getline(cin, proj);

		n--;
		while (n-- && getline(cin, name)) {
			coat[proj].insert("");
			int f = 0;
			for (int i = 0; i < name.size(); i++) {
				if(name[i] == ' ')
					continue;
				if (name[i] >= 'A' && name[i] <= 'Z') {
					proj = name;
					f = 1;
					break;
				}else{
					break;
				}
			}
			if(f)
				continue;
			if (stu[name] == "" || stu[name] == proj) {
				stu[name] = proj;
				coat[proj].insert(name);
			} else {
				stu[name] = "-1";
			}

		}
		int idx = 0;
		Node ans[10010];
		for (map<string, set<string> >::iterator i = coat.begin();
				i != coat.end(); i++) {
			int cnt = 0;
			for (set<string>::iterator j = i->second.begin();
					j != i->second.end(); j++) {
				if (stu[*j] != "-1")
					cnt++;
			}
			ans[idx].s = i->first;
			ans[idx].n = cnt;
			idx++;
		}
		sort(ans, ans + idx, cmp);
		for (int i = 0; i < idx; i++)
			cout << ans[i].s << " " << ans[i].n << endl;
	}
	return 0;
}
