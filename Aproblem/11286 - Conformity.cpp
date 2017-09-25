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

map<string, int> q;
map<string, int>::iterator it;
string arr[10010];
int main() {
	//freopen("in.txt","r", stdin);
	int xx, t;
	while (rint(t) && t != 0) {
		q.clear();
		priority_queue<int> qq;
		repi(j,0,t)
		{
			for (int i = 0; i < 5; i++) {
				rint(xx);
				qq.push(xx);
			}
			stringstream sin;
			while(qq.size()){
				int cur = qq.top();
				qq.pop();
				sin << cur;
			}
			arr[j] = sin.str();
			q[arr[j]]++;
		}

		int mx = -1;
		for (it = q.begin(); it != q.end(); it++) {
			mx = max(it->s, mx);
		}
		int ret = 0;
		repi(i,0,t){
			it = q.find(arr[i]);
			if(it->s >= mx)
				ret++;
		}
		pint(ret);
		pnl();
	}
	return 0;
}
