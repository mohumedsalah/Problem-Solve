#include <bits/stdc++.h>

using namespace std;
int const mx = 1e3 * 5 + 9;
std::priority_queue<int, vector<int>, greater<int> > q;
int main() {

	cout  << (int)'a' << endl;;
	int n, xx;
	while (scanf("%d", &n) && n) {
		while(q.size())
			q.pop();
		for (int i = 0; i < n; i++) {
			scanf("%d", &xx);
			q.push(xx);
		}

		long long b  = 0, ret = 0;
		while(q.size() > 1){
			b = q.top();
			q.pop();
			b += q.top();
			q.pop();
			q.push(b);
			ret += b;
		}
		printf("%lld\n", ret );
	}
	return 0;
}
