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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int const mx = 1e5 + 6;
int arr[mx];
int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while (cin >> n) {
		repi(i,0,n)
			rint(arr[i]);
		sort(arr, arr + n);
		int sum;
		int ans1 = -1, ans2 = -1;
		rint(sum);
		int mxdif = -1;
		repi(i,0,n)
		{
			int target = sum - arr[i];
			if (target < 0)
				continue;
			int lo = i + 1, hi = n - 1, ans = -1;
			while (lo - 1 < hi) {
				int m = (lo + hi) / 2;
				if (target == arr[m]) {
					ans = m;
					break;
				} else if (target > arr[m]) {
					lo = m + 1;
				} else {
					hi = m - 1;
				}
			}
			if (ans == -1)
				continue;
			if (mxdif <=  arr[ans] - arr[i]) {
				ans1 = arr[i], ans2 = arr[ans];
				mxdif = arr[i] - arr[ans];
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", ans1,
				ans2);
	}

	return 0;
}
