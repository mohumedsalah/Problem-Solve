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
string vol = "aeiou";
string keys = "bcdfghjklmnpqrstvwxyz";
double pro[26] = { 12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.7, 6.25, 0.44,
		0, 4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.9,
		0.02, 0.22, 0.9, 0.52 };
int vis[26];
double ans;
int inc;
int n;
char arrin[10];
void solve(int inx, double un) {
	if (inx == n + 1) {
		inc++;
		ans += un;
		return;
	}
	if (inx % 2 == 0) {
		repi(i,0,5)
		{
			if (vis[vol[i] - 'a'] <= 1) {
				vis[vol[i] - 'a']++;
				solve(inx + 1, un + inx * pro[vol[i] - 'a']);
				vis[vol[i] - 'a']--;
			}
		}
	}else{
		repi(i,0,21){
			if(vis[keys[i] - 'a'] <= 1){
				vis[keys[i] - 'a']++;
				solve(inx + 1 , un + inx * pro[keys[i] - 'a']);
				vis[keys[i] - 'a']--;
			}
		}
	}
}
int main() {
	//freopen("in.txt","r", stdin);
	int T;
	rint(T);
	while(T--){
		memset(vis,0, sizeof vis);
		ans = 0;
		inc = 0;
		rs(arrin);
		n = ssz(arrin);
		solve(2,pro[arrin[0]-'a']);
		ans /= inc;
		double r = 0;
		repi(i,0,n){
			r += (i+1) * (pro[arrin[i] - 'a']);
		}
		if(r >= ans){
			puts("above or equal");
		}else{
			puts("below");
		}
	}
	return 0;
}
