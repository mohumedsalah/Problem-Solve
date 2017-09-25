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
string anss = "";
int main() {
	int n;
	string s, ansr = "";
	rint(n);
	getchar();
	while (n--) {
		ansr = "";
		anss = "";
		getline(cin, s);
		if (s[0] >= 'A' && s[0] <= 'Z') {
			int n = sz(s);
			int cnt = 0;
			int nc = 0;
			while (s[cnt] >= 'A' && s[cnt] <= 'Z') {
				cnt++;
			}
			int Po = 0;
			for (int i = cnt - 1; i >= 0; i--) {
				nc = nc + pow(26, Po) * (s[i] - 'A' + 1);
				Po++;
			}
			cout << 'R' ;
			repi(i,cnt,n)
			{
				cout << s[i];
			}
			cout<<'C' << nc;

			pnl();
		} else {
			int n = sz(s);
			int cnt = 1;
			repi(i,1,n)
			{
				cnt++;
				if (s[i] == 'C')
					break;
				ansr += s[i];
			}
			int nc = 0;
			for (int i = n - 1; i >= cnt; i--) {
				nc = (nc * 10) + (s[i] - '0');
			}
			while(nc != 0){
				int tt = nc / 26;
				int rt = nc % 26;
				anss+=('A' + rt - 1);
				nc = tt;
			}
			reverse(anss.begin(),anss.end());
			cout << anss << ansr << endl;
		}
	}

	return 0;
}
