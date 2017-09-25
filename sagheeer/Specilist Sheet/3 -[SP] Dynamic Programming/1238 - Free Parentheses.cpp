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

int visited[35][2][10000], N, sig[35], num[35], used[10000];
void rec(int idx, int open, int val){
	if (visited[idx][open][val + 4000])
		return;
	visited[idx][open][val + 4000] = 1;
	if (idx == N) {
		used[val + 4000] = 1;
		return;
	}
	int nval = val + num[idx] * sig[idx] * ((open % 2 == 0) ? 1 : -1);
	if (sig[idx] == -1)
		rec(idx + 1, open + 1, nval);
	if (open > 0)
		rec(idx + 1, open - 1, nval);
	rec(idx + 1, open, nval);
}
int main() {
	freopen("in.txt","r", stdin);
	string xx;
	char rr;
	while(getline(cin , xx)){
		memset(visited,0, sizeof visited);
		memset(used,0, sizeof used);
		memset(num,0, sizeof num);
		stringstream sin(xx);
		N = 0;
		sig[0] = 1;
		while(true){
			sin >> num[N];
			if(sin >> rr){
				N++;
				sig[N] = (rr == '+')?1:-1;
			}else{
				break;
			}
		}
		rec(0,0,0);
		int ans = 0;
		repi(i,0,10000){
			if(used[i] > 0)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
