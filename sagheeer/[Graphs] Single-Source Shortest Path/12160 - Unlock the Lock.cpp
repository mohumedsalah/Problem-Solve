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
queue<ii> q;
int arr[15];
int vis[10010];
int move(int from, int so) {
	if (from + so <= 9999)
		return from + so;
	return (from + so) % 10000;
}
int main() {
	//freopen("in.txt","r", stdin);
	int sur, dest, m,cnt = 0;
	while (rint(sur) && rint(dest) && rint(m) && (sur || dest || m)) {
		while(q.size())
			q.pop();
		memset(vis, -1 , sizeof vis);
		repi(i,0, m)
		{
			rint(arr[i]);
		}
		q.push(ii(0, sur));
		vis[sur] = 1;
		ii cur;
		int fl = 0;
		while(q.size()){
			cur = q.front();
			q.pop();
			if(cur.s == dest){
				printf("Case %d: %d\n",++cnt,cur.f);
				fl = 1;
				break;
			}
			repi(i,0,m){
				int nxt = move(cur.s,arr[i]);
				if(vis[nxt] == -1)
					vis[nxt] = 1,q.push(ii(cur.f+1,nxt));
			}
		}
		if(!fl)
			printf("Case %d: Permanently Locked\n",++cnt);
	}
	return 0;
}
