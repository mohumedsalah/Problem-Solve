#include <bits/stdc++.h>

using namespace std;
int const mx = 1e6 + 9;
bool np[mx];
vector<int> vp;
int a, b, k;
void sevie() {
	np[0] = 1, np[1] = 1;
	for (int i = 2; i <= 1e6; i++) {
		if (np[i] == 0) {
			vp.push_back(i);
			for (int j = 2 * i; j <= 1e6; j += i) {
				np[j] = 1;
			}
		}
	}
}
int count_p(int s, int e) {
	vector<int>::iterator low = lower_bound(vp.begin(), vp.end(), s);
	vector<int>::iterator up = lower_bound(vp.begin(), vp.end(), e);
	int ret = up - low;
	if (np[e] == 0) {
		ret++;
	}
	return ret;
}
int che(int l){
	for(int i = a; i <= b - l + 1 ;i++ ){
		if(count_p(i,i+l-1) < k){
			return 0;
		}
	}
	return 1;
}
int main() {
	sevie();
	scanf("%d %d %d", &a, &b, &k);
	int s = 1, e = b - a + 1, ans = -1;
	while (s - 1 < e) {
		int m = (s + e) / 2;
		if ( che(m) ) {
			ans = m;
			e = m - 1;
		} else
			s = m + 1;
	}
	cout << ans;
	return 0;
}
