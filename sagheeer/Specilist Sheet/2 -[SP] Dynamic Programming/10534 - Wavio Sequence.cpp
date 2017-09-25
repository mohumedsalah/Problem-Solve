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
int arr[10100], l1[10100], l2[10100], ret1[10100], ret2[10100];
int main() {
	//freopen("in.txt","r", stdin);
	int n;
	while (rint(n) == 1) {
		repi(i,0,n)
		{
			rint(arr[i]);
		}
		int lis = 0;
		repi(i,0,n)
		{
			int pos = lower_bound(l1, l1 + lis, arr[i]) - l1;
			l1[pos] = arr[i];
			if (pos + 1 > lis) {
				lis = pos + 1;
			}
			ret1[i] = lis;
		}
		reverse(arr, arr + n);
		lis = 0;
		repi(i,0,n)
		{
			int pos = lower_bound(l2, l2 + lis, arr[i]) - l2;
			l2[pos] = arr[i];
			if (pos + 1 > lis) {
				lis = pos + 1;
			}
			ret2[i] = lis;
		}
		reverse(ret2,ret2 + n);
		int mx = -1;
		repi(i,0,n)
			if(ret1[i]== ret2[i])
				mx = max(mx, ret1[i]);
		pint((mx - 1) * 2 + 1), pnl();
	}
	return 0;
}
