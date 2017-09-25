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
char arr[15][15];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
	//freopen("in.txt","r", stdin);
	int T, n,cnt = 0;
	rint(T);
	while (T--) {
		rint(n);
		repi(i,0,n)
		{
			rs(arr[i]);
		}
		repi(i,0,n)
		{
			repi(j,0,n)
			{
				if (arr[i][j] != '.')
					continue;
				repi(ch,0,26)
				{
					int fl = 1;
					repi(d,0,4)
					{
						int ni = i + dx[d];
						int nj = j + dy[d];
						if(ni < 0 || ni >= n || nj < 0 || nj >= n)
							continue;
						if(arr[ni][nj] == ('A'+ch)){
							fl = 0;
							break;
						}
					}
					if(fl == 0)
						continue;
					else{
						arr[i][j] = 'A'+ch;
						break;
					}
				}
			}
		}
		printf("Case %d:\n",++cnt);
		repi(i,0,n)
			ps(arr[i]),pnl();
	}

	return 0;
}
