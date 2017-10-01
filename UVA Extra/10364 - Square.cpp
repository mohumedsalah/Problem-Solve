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
int  arr[50];
int vis[50];
int n;
int memo[50][2234567];
int ch[4];
bool che(int taken) {
	int num = 0, sum = 0;
	repi(i,0, n)
	{
		if (isOn(taken, i)) {
			num++;
			sum += arr[i];
		}
	}
	if (!(num >= 4 && sum % 4 == 0))
		return false;
	int avg = sum / 4;
	memset(ch, 0, sizeof ch);
	repi(i,0, n)
	{
		if (isOn(taken, i)) {
			repi(j,0,4){
				if(ch[j] + arr[i] <= avg){
					ch[j] += arr[i];
					break;
				}
			}
		}
	}
	repi(i,0,4){
		if(ch[i] == avg)
			continue;
		return false;
	}
	return true;

}
int solve(int inx, int taken) {
	int &ret = memo[inx][taken];
	if (ret != -1)
		return ret;
	if (inx == n)
		return ret = che(taken);
	if (che(taken))
		return ret = 1;
	ret = 0;
	int tt = taken;
	setBit(taken, inx);
	return ret = (solve(inx + 1, taken) || solve(inx + 1, tt));

}
int main() {
	freopen("in.txt","r", stdin);
	int t;
	rint(t);
	while (t--) {
		memset(vis, 0, sizeof vis);
		memset(memo, -1, sizeof memo);
		rint(n);
		int ss = 0;
		repi(i,0, n)
		{
			rint(arr[i]);
			ss += arr[i];
		}

		if (solve(0,0) && ss % 4 == 0)
			puts("yes");
		else
			puts("no");

	}

	return 0;
}
