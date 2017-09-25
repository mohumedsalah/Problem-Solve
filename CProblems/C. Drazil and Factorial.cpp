#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n;
ll num = 1;
char arrp[100];
ll f[10];
int main() {

	f[1] = 1;
	for (int i = 2; i <= 9; i++) {
		f[i] = f[i - 1] * i;
	}
	cin >> n;
	char arr[100];
	scanf("%s", arr);
	vector<int> ret;
	for (int i = 0; i < n; i++) {
		if (arr[i] == '0' || arr[i] == '1')
			continue;
		else if (arr[i] == '4') {
			ret.push_back(3);
			ret.push_back(2);
			ret.push_back(2);
		} else if (arr[i] == '6') {
			ret.push_back(3);
			ret.push_back(5);
		} else if (arr[i] == '8') {
			ret.push_back(7);
			ret.push_back(2);
			ret.push_back(2);
			ret.push_back(2);
		} else if (arr[i] == '9') {
			ret.push_back(7);
			ret.push_back(3);
			ret.push_back(3);
			ret.push_back(2);
		} else {
			ret.push_back(arr[i] - '0');
		}

	}
	sort(ret.begin(), ret.end());
	for (int i = ret.size() - 1; i >= 0; i--) {
		printf("%d", ret[i]);
	}

	return 0;
}
