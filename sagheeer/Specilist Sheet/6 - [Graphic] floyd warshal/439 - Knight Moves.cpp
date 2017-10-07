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
map<string, int> mpp;
int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
bool inBox(int i, int j) {
	return i >= 1 && j >= 'a' && i <= 8 && j <= 'z';
}
int arr[70][70];
int main() {
	//freopen("in.txt","r", stdin);
	//freopen("out.txt","w", stdout);
	string in, in2;
	int cnt = 0;
	repi(i,1,9)	repi(j,'a', 'i')
		{
			string A = "";
			A += (i + '0');
			A += char(j);
			mpp[A] = ++cnt;

		}
	repi(i,0,70){repi(j,0,70){
			arr[i][j] = INF;
		}
		arr[i][i] = 0;
	}
	repi(i,1,9)repi(j,'a', 'i')repi(d,0,8)
			{
				int ni = i + dx[d], nj = j + dy[d];
				if (inBox(ni, nj)) {
					string A = "";
					A += (i + '0');
					A += char(j);
					string B = "";
					B += (ni + '0');
					B += char(nj);
					arr[mpp[A]][mpp[B]] = 1;
				}
			}
	repi(k,1,70)repi(i,1, 70)repi(j,1,70){
		if(arr[i][k] < INF && arr[k][j] < INF){
			arr[i][j] = min(arr[i][j], arr[i][k] +arr[k][j]);
		}
	}
	while(cin >> in ){
		cin >> in2;
		string tt = in,tt2 = in2;
		reverse(in.begin(), in.end());
		reverse(in2.begin(), in2.end());
		printf("To get from %s to %s takes %d knight moves.\n",tt.c_str(),tt2.c_str(),arr[mpp[in]][mpp[in2]]);
	}

	return 0;
}
