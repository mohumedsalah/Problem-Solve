#include<bits/stdc++.h>
using namespace std;
int memo[110][4];
int arr[110];
int n;
int solve(int inx, int b) {
	if(inx  == n)
		return 0;
	int &ret = memo[inx][b];
	if (ret != -1)
		return ret;
	if (arr[inx] == 0) {
		return ret = 1 + solve(inx + 1, 0);
	}
	if (arr[inx] == 1) {
		if (b == 2 || b == 0)
			ret = solve(inx + 1, 1);
		else
			ret = 1 + solve(inx + 1, 0);
		return ret;
	}
	if (arr[inx] == 2) {
		if (b == 1 || b == 0)
			ret = solve(inx + 1, 2);
		else
			ret = 1 + solve(inx + 1, 0);
		return ret;
	}
	if (b == 0) {
		return ret = min(solve(inx + 1, 1), solve(inx + 1, 2));
	}
	if (b == 1) {
		return ret = solve(inx + 1, 2);
	}
	return ret = solve(inx + 1, 1);
}
int main() {
	memset(memo, -1, sizeof memo);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ret = solve(0,0);
	cout <<ret << endl;


	return 0;
}
