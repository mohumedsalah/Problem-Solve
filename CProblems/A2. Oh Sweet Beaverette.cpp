#include <bits/stdc++.h>
using namespace std;
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define rln() getchar()
#define rint(n) scanf("%d",&n)
#define rs(n) scanf("%s",n)
#define rc(n) scanf("%c",&n)
#define rf(n) scanf("%lf",&n)
#define rl(n) scanf("%lld",&n)
#define pint(x) printf("%d", x)
#define psp() printf(" ")
#define ps(x) printf("%s", x)
#define pc(x) printf("%c", x)
#define pnl() printf("\n")
#define pl(x) printf("%lld", x)
#define pf(x) printf("%.6lf", x)
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define sz(v) ((int)((v).size()))
#define ssz(s) ((int)strlen(s))
#define f first
#define s second
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 2000000000000000000LL
#define INF 1000000000
#define EPS 1e-8
#define mod 1000000007
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ii> vii;
ii arr[123456];
ll nn[123456];
ll mxsum[123456];
vi ret;
bool cmp(ii a, ii b) {
	if (a.f == b.f)
		return a.s < b.s;
	return a.f > b.f;
}
int main() {

	int n;
	rint(n);
	repi(i,1, n + 1)
	{
		rl(arr[i].f);
		if (arr[i].f > 0)
			mxsum[i] = mxsum[i - 1] + arr[i].f;
		else
			mxsum[i] = mxsum[i - 1];
		arr[i].s = ll(i);
		nn[i] = arr[i].f;
	}
	sort(arr + 1, arr + n + 1, cmp);
	ll st = 0, ed = 0;
	ll mx = -INF_LL;
	int start = 0, end = 0;
	for (int i = 1; i < n + 1; i++) {
		int tt = i;
		ll b = arr[i].f;
		//cout << 2 * b << endl;
		st = arr[i].s;
		ed = arr[i].s;
		while (i < n && b == arr[i + 1].f) {

			i++;
			ed = arr[i].s;
		}
		if (i > tt) {
			if (arr[i].f > 0) {
				if (mx < mxsum[ed] - mxsum[st - 1]) {
					mx = mxsum[ed] - mxsum[st - 1];
					start = st;
					end = ed;
				}
			} else {
				if (mx < mxsum[ed] - mxsum[st - 1] + b + b) {
					mx = mxsum[ed] - mxsum[st - 1] + b + b;
					start = st;
					end = ed;
				}
			}
		}
	}
	int tt = 0;
	vi ret;
	repi(i,1,n + 1)
	{
		if (nn[i] < 0 && i != start && i != end) {
			ret.pb(i);
			continue;
		}
		if (i >= start && i <= end) {
			continue;
		}
		ret.pb(i);
	}
	tt = sz(ret);
	cout << mx << " " << tt << endl;
	repi(i,0, tt)
		pl(ret[i]), psp();

	return 0;
}
