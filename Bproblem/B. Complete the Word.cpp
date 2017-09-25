#include <bits/stdc++.h>

using namespace std;
int arr[26];
int main() {

	//cout << (int) 'A' << endl;
	string s;
	getline(cin, s);
	string temp = s;
	for (int k = 0; k < temp.size(); k++) {
		memset(arr, 0, sizeof arr);
		s = temp.substr(k, 26);
		//cout << s << endl;
		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] == '?')
				continue;
			arr[s[i] - 65]++;
		}
		int j;
		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] == '?') {
				int f = 0;
				for (j = 0; j <= 25; j++) {
					if (arr[j] == 0) {
						s[i] = 65 + j;
						arr[j]++;
						f = 1;
						break;
					}
				}
				if (f == 0)
					s[i] = j + 65 - 1;
			}
		}
		int flag = 1;
		for (int i = 0; i < 26; i++) {
			if (arr[i] == 0) {
				flag = 0;
				break;;
			}
		}
		if (flag == 0)
			continue;
		for (int i = 0; i < temp.size(); i++) {
			if (i == k) {
				cout << s;
				i += 25;
				continue;
			}
			if(temp[i] == '?')
				cout << 'S';
			else
				cout << temp[i];
		}
		cout << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}
