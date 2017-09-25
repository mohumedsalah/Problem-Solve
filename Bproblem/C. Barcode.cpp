#include <bits/stdc++.h>

using namespace std;
int n, m, x, y;
int memo[1002][1002][2];
char arr[1002][1002];
int v[1002];
int solve(int i, int cnt, int f){
    if(i == m){
        if(cnt >= x && cnt <= y){
            return 0;
        }
        return 1e9;
    }
    int &ret = memo[i][cnt][f];
    if(ret != -1)
        return ret;

    ret = 1e9;
    if(cnt == y){
        ret = min(ret, solve(i, 0, !f));
        return ret;
    }

    if(cnt >= x){
        ret = min(ret, solve(i, 0, !f));
    }

    ret = min(ret, solve(i+1, cnt+1, f)+(f ? v[i] : n-v[i]));

    return ret;
}
int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	for (int j = 0; j < m; j++) {
		int r = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == '#') {
				r++;
			}
		}
		v[j] = r;
	}
	int ret = min(solve(0, 0, 1), solve(0, 0, 0));
	cout << ret << endl;
	return 0;
}
