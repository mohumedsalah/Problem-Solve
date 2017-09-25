#include <bits/stdc++.h>

using namespace std;
int main() {

	string arr;
	int s;
	cin >> arr >> s;
	for (int i = 0; i < arr.size(); i++) {
		int cur = arr[i] - '0';
		int npos = -1;
		int mx = cur;
		for (int j = i + 1; j < arr.size(); j++) {
			int curj = arr[j] - '0';
			if (curj > mx && j - i <= s){
				npos = j;
				mx = curj;
			}
		}
		if (npos != -1) {

			char e = arr[i];
			arr[i] = arr[npos];
			for (int k = i + 1; k <= npos; k++) {
				char tt = arr[k];
				arr[k] = e;
				e = tt;
			}

			s -= npos-i;
		}
	}
	cout << arr << endl;
	return 0;
}
