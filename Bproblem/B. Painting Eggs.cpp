#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef pair<int, int> ii;
ii arr[1000005];
int vis[1000005];
int main() {

	int n, xx, yy;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &xx, &yy);
		arr[i] = ii(xx, yy);
	}
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int t = a + arr[i].f;
		int t1 = b + arr[i].s;
		int tt = abs(t - b);
		int tt1 = abs(t1 - a);
		if (tt <= 500) {
			vis[i] = 1;
			a = t;
		} else if (tt1 <= 500) {
			vis[i] = 2;
			b = t1;
		} else {
			if (tt < tt1) {
				vis[i] = 1;
				a = t;
			} else {
				vis[i] = 2;
				b = t1;
			}
		}

	}
	if(abs(a - b) > 500){
		printf("-1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (vis[i] == 1)
			printf("A");
		else
			printf("G");
	}

	return 0;
}
