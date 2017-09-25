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
struct sell {
	int st;
	int ed;
	string md;
};
vector<sell> vv;
char strr[50];
bool cmp(sell a, sell b) {
	if (a.st == a.st)
		return a.ed < a.ed;
	return a.st < b.st;
}
int main() {
	//freopen("in.txt", "r", stdin);
	sell one;
	int T, N, Q, C;
	rint(T);
	while (T--) {
		vv.clear();
		rint(N);
		repi(i,0,N)
		{
			rs(strr);
			rint(one.st);
			rint(one.ed);
			one.md = strr;
			vv.push_back(one);
		}
		//sort(vv.begin(), vv.end(), cmp);
		rint(Q);
		while (Q--) {
			rint(C);
			int cc = vv.size();
			int ans = -1;
			for(int i = 0; i < cc;i++){
				if(C >= vv[i].st && C <= vv[i].ed){
					if(ans != -1){
						ans = -1;
						break;
					}
					ans = i;
				}
			}
			if(ans == -1)
				puts("UNDETERMINED");
			else
				cout << vv[ans].md << "\n";
		}
		if(T != 0)
			pnl();
	}

	return 0;
}
