#include <bits/stdc++.h>

using namespace std;
int main() {
	//freopen("unit.in","r",stdin);
	int t;
	cin >> t;
	long long  arr[52];
	arr[0] = 0;
	arr[1] = 0;
	for(int i = 2 ; i <= 50;i++){
		arr[i] = arr[i-1] + pow(2,i-2);
	}
	while (t--) {
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}
	return 0;
}
