#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int N, M;
int memo[110][(1 << 10) + 100][30];

int solve(int inx, int btm, int ld) {
	if (inx > M)
		return 0;

	if (memo[inx][btm][ld] != -1)
		return memo[inx][btm][ld];

	int ret = 0;
	if (btm == ((1 << N) - 1))
		++ret;

	for (int nextDigit = ld - 1; nextDigit <= ld + 1; nextDigit +=
			2) {
		if (nextDigit < 0 || nextDigit >= N)
			continue;

		ret += solve(inx + 1, btm | (1 << nextDigit),
				nextDigit);
		ret %= MOD;
	}

	return memo[inx][btm][ld] = ret;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		memset(memo, -1, sizeof(memo));
		int ret = 0;
		for (int firstDigit = 1; firstDigit <= N - 1; ++firstDigit) {
			ret += solve(1, 1 << firstDigit, firstDigit);
			ret %= MOD;
		}
		cout <<ret << endl;
	}
	return 0;
}
