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
map<string, int > mpp;
string arr[150];
bool adj[150][150];
bool res[150][150];
map<string,set<string> > ret;
set<string> vv;
string in, in2;
int main(){
	//freopen("in.txt","r", stdin);
	int n, t, nm,m ;
	rint(t);
	while(t--){
		vv.clear();
		ret.clear();
		mpp.clear();
		memset(adj,0,sizeof adj);
		memset(res,0,sizeof res);
		rint(n);
		repi(i,0, n){
			cin >> in;
			arr[i + 1] = in;
			mpp[in] = i + 1;
		}
		rint(m);
		repi(i,0, m){
			cin >> in;
			rint(nm);
			int temp = mpp[in];
			while(nm--){
				cin >> in2;
				adj[mpp[in2]][temp] = 1;
				res[mpp[in2]][temp] = 1;
			}
		}
		repi(k,1,n + 1)repi(i,1,n + 1)repi(j,1,n+1){
			if(adj[i][k] && adj[k][j]){
				adj[i][j] = 1;
			}
		}

		repi(k,1,n + 1)repi(i,1,n + 1)repi(j,1,n+1){
			if(adj[i][j]){
				if(adj[i][k] && adj[k][j]){
					res[i][j] = 0;
				}
			}
		}
		repi(i,1,n + 1)repi(j,1, n+1){
			if(res[i][j]){
				vv.insert(arr[j]);
				ret[arr[j]].insert(arr[i]);
			}
		}
		while(vv.size()){
			string cur =  *vv.begin();
			vv.erase(cur);
			int rr = ret[cur].size();
			cout << cur << " " << rr << " ";
			vector<string> it;
 			for(auto i : ret[cur]){
				it.pb(i);
			}
 			repi(i,0, sz(it)){
 				if(i == sz(it) - 1)
 					cout << it[i];
 				else
 					cout <<it[i] << " ";
 			}
			pnl();

		}


	}
	return 0;
}
