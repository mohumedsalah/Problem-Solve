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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char str[110][55];
map<string, int> mp;
map<string, int>::iterator it;
int dep[110], vis[110];
int n, m;
vector<int> arr[110], vv;
char xx[55], yy[55];
priority_queue<int,vector<int>, greater<int> > q;
string ss;
int main() {
	//freopen("in.txt","r", stdin);
	int cnt = 0;
	while (cin >> n) {
		cnt++;
		vv.clear();
		mp.clear();
		repi(i,1, n+1)
			arr[i].clear();

		repi(i,0,n)
		{
			rs(str[i + 1]);
			ss = str[i + 1];
			mp[ss] = i + 1;
		}
		memset(dep, 0, sizeof dep);
		memset(vis, 0, sizeof vis);
		rint(m);
		while (m--) {
			rs(xx), rs(yy);
			arr[mp[xx]].pb(mp[yy]);
			dep[mp[yy]]++;
		}

		repi(i,0,n)
			if(dep[i+1] == 0)
				q.push(i+1),vis[i+1] = 1;
		while(q.size()){
			int cur = q.top();
			q.pop();
			vv.pb(cur);
			repi(i,0,sz(arr[cur])){
				dep[arr[cur][i]] --;
				if(dep[arr[cur][i]] == 0 && vis[arr[cur][i]] == 0 ){
					q.push(arr[cur][i]);
					vis[arr[cur][i]] = 1;
				}
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order: ",cnt);
		repi(i,0,n)
			if (i != n - 1)
				ps(str[vv[i]]), psp();
			else
				ps(str[vv[i]]);
		printf(".\n");
		pnl();
	}
	return 0;
}





// or using adjmax like this






/*
 *
 *
 * #include <bits/stdc++.h>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char str[110][55];
map<string, int> mp;
map<string, int>::iterator it;
int dep[110], vis[110];
int n, m;
vector<int> vv;
int arr[110][110];
char xx[55], yy[55];
set<int> q;
string ss;
int main() {
	freopen("in.txt", "r", stdin);
	int cnt = 0;
	while (cin >> n) {
		cnt++;
		mp.clear();
		ss.clear();
		vv.clear();
		memset(dep, 0, sizeof dep);
		memset(vis, 0, sizeof vis);
		memset(arr, 0, sizeof arr);
		repi(i,0,n)
		{
			rs(str[i + 1]);
			ss = str[i + 1];
			mp[ss] = i + 1;
		}
		rint(m);
		while (m--) {
			rs(xx), rs(yy);
			int ix = mp[xx], iy = mp[xx];
			if (ix == iy || arr[ix][iy])
				continue;
			arr[ix][iy] = 1;
			dep[iy]++;
		}

		repi(i,0,n)
			if (dep[i + 1] == 0)
				q.insert(i + 1);
		while (q.size()) {
			int cur = *q.begin();
			q.erase(cur);
			vv.pb(cur);
			repi(i,1,n+1)
			{
				if (arr[cur][i] == 1) {
					arr[cur][i] = false;
					dep[i]--;
					if (dep[i] == 0)
						q.insert(i);
				}
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order: ", cnt);
		//cout << endl;
		//cout << n << " " << sz(vv) << endl;
		repi(i,0,n)
			if (i != n - 1)
				ps(str[vv[i]]), psp();
			else
				ps(str[vv[i]]);
		printf(".\n\n");
	}
	return 0;
}
 * */
