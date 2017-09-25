#include <bits/stdc++.h>
using namespace std;
int b, m;
long long solve(long long ansy) {
	long long ansx = (b - ansy) * m;
	if(ansx < 0)
		return -1;
	long long ret = 0;
	long long A = ansy * (ansy + 1) / 2;
	long long B = ansx * (ansx + 1) / 2;
	ret = A * (ansx+1) + B * (ansy+1);
	//cout << ret << endl;
	return ret;
}
int main() {

	scanf("%d%d", &m, &b);
	long long ans = 0;
	for(long long  i = 0; ;i++){
		long long ret = solve(i);
		if(ret == -1)
			break;
		ans = max(ret,ans);

	}

	cout << ans << endl;;
	return 0;
}
