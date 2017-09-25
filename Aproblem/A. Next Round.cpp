#include <bits/stdc++.h>

using namespace std;
int arr[110];
int main() {

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if(arr[i] >= arr[k-1] && arr[i] > 0){
			ret++;
		}
	}
	cout << ret << endl;

	return 0;
}
