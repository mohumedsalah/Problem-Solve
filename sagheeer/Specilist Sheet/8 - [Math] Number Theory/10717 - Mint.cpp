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
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}
int arr[60], l[15], ret1[15], ret2[15];
int main() {
	freopen("in.txt", "r", stdin);
	int n, m;
	while (rint(n), rint(m) && n && m) {
		repi(i,0, n)
		{
			rint(arr[i]);
		}
		repi(i,0, m)
		{
			rint(l[i]);
		}
		memset(ret1, -1, sizeof ret1);
		memset(ret2, -1, sizeof ret2);
		repi(r, 0, n)
		{
			repi(r1, r + 1, n)
			{
				repi(r2, r1 + 1, n)
				{
					repi(r3, r2 + 1, n)
					{
						int ans = lcm(lcm(arr[r], arr[r1]),
								lcm(arr[r2], arr[r3]));
						repi(i,0, m)
						{
							int tt = ceil(l[i] / double(ans));
							int rr = floor(l[i] / double(ans));
							//cout << tt << " " << rr <<endl;
							if (ret1[i] == -1 || ret1[i] > tt * ans) {
								ret1[i] = tt * ans;
							}
							if (ret2[i] == -1 || ret2[i] < rr * ans) {
								ret2[i] = rr * ans;
							}
						}

					}
				}
			}
		}
		repi(i,0, m)
		{
			pint(ret2[i]), psp(), pint(ret1[i]), pnl();
		}
	}

	return 0;
}
