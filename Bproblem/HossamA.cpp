#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("balalance.in", "r", stdin);
	string str;
	stack<char> s;

	int t;
	cin >> t;
	while (t--) {
		int cnt = 0;
		while (s.size())
			s.pop();
		cin >> str;
		int ret = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
				continue;
			}
			if (s.size() == 0) {
				cnt++;
				continue;
			}
			char cur = s.top();
			s.pop();
			if (str[i] == ')' && cur != '(') {
				ret++;
			} else if (str[i] == ']' && cur != '[')
				ret++;
		}
		int temp = cnt + s.size();
		if (temp != 0){
			if(temp % 2 == 0){
				ret += (temp/2);
				cout << ret << endl;
				continue;
			}else{
				cout << -1 << endl;
			}

		}
		else
			cout << ret << endl;
	}

	return 0;
}
