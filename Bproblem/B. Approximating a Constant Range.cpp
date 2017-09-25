#include <bits/stdc++.h>

using namespace std;
int main() {
	int xx, n;
	cin >> n;
	int l = 1e7, h = -1, last = -1, cnt = 0, ans = -1, rlast = 0;
	for (int i = 0; i < n; i++) {
		cin >> xx;
		if (l == 1e7) {
			cnt++;
			l = min(l, xx);
		}
		else if (h == -1 && xx != l) {
			cnt++;
			h = max(h, xx);
			if(l > h){
				swap(h,l);
			}
		}
		else if (xx == l || xx == h) {
			cnt++;
		} else {
			ans = max(cnt, ans);
			cnt = 1;
			if (xx > h && last == h) {
				l = h, h = xx;
				cnt += rlast;
			} else if (xx < l && last == l) {
				h = l, l = xx;
				cnt += rlast;
			}
		}
		if (last == xx)
			rlast++;
		else {
			last = xx;
			rlast = 1;
		}
	}
	cout << max(ans, cnt) << endl;
	return 0;
}
