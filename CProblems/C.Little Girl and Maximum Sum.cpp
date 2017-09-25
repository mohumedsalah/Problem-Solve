#include <bits/stdc++.h>
using namespace std;
int const m = (1e6 * 2) + 5;
int v[m];
int reps[m], rep[m], repe[m];
bool cmp(int a, int b) {
	return a > b;
}
int main() {

	int n, q, xx, yy;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v + n, cmp);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &xx, &yy);
		reps[--xx]++;
		repe[yy]++;
	}
	int ns = 0, ne = 0;
	for (int i = 0; i < n; i++) {
		ns += reps[i];
		ne += repe[i];
		rep[i] = ns - ne;
	}
	sort(rep, rep + n, cmp);
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		//cout << rep[i] << " " << v[i] << endl;
		mx += (long long) rep[i] * v[i];
	}
	printf("%lld", mx);
	return 0;
}
