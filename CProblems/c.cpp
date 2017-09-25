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
vi arr[100010];
queue<int> q;
int ret[100010];
int t, n,xx;
int main() {
	freopen("jumping.in", "r", stdin);

	rint(t);
	while (t--) {
		rint(n);
		repi(i,1,n+1)
			ret[i] = INF, arr[i].clear();
		repi(i,1, n + 1)
		{
			rint(xx);
			if (i + xx <= n)
				arr[i + xx].push_back(i);
			if (i - xx >= 1)
				arr[i - xx].push_back(i);
		}
		q.push(n);
		ret[n] = 0;
		int cur;
		while (q.size()) {
			cur = q.front();
			q.pop();
			repi(i,0,sz(arr[cur]))
			{
				int ch = arr[cur][i];
				if (ret[ch] > ret[cur] + 1) {
					ret[ch] = ret[cur] + 1;
					q.push(ch);
				}
			}
		}
		repi(i,1,n+1)
			if(ret[i] == INF){
				printf("-1\n");
			}else{
				printf("%d\n", ret[i]);
			}

	}

	return 0;
}
