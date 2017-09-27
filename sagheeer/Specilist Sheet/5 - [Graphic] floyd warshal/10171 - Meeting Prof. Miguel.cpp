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

void AddEdge(char direction, char X, char Y, int cost, int array[30][30])
{
    array[X - 'A'][Y - 'A'] = min(cost, array[X - 'A'][Y - 'A']);
    if (direction == 'B')
        array[Y - 'A'][X - 'A'] = min(cost, array[Y - 'A'][X - 'A']);

}
int main() {
	freopen("in.txt", "r", stdin);
	int arr1[30][30];
	int arr2[30][30];
	int n, v;
	char fm, to, s, tp;
	while (rint(n) && n) {
		repi(i,0,30)
			repi(j,0,30)
				arr1[i][j] = arr2[i][j] = INF;

		repi(i,0,n)
		{

			cin >> tp >> s >> fm >> to >> v;
			if(tp == 'Y')
				AddEdge(s, fm, to , v, arr1);
			else
				AddEdge(s, fm, to , v, arr2);
		}
		repi(i,0,27)
					arr1[i][i] = arr2[i][i] = 0;
		repi(k,0, 27)
			repi(i,0, 27)
				repi(j,0, 27)
				{
					if (arr1[i][k] < INF && arr1[k][j] < INF) {
						arr1[i][j] = min(arr1[i][j], arr1[i][k] + arr1[k][j]);
					}
				}
		repi(k,0, 27)
			repi(i,0, 27)
				repi(j,0, 27)
				{
					if (arr2[i][k] < INF && arr2[k][j] < INF) {
						arr2[i][j] = min(arr2[i][j], arr2[i][k] + arr2[k][j]);
					}
				}

		cin >> fm >> to;

		int ans = INF;
		repi(i,0,27)
		{
			ans = min(ans,arr1[fm - 'A'][i] + arr2[to - 'A'][i]);
		}

		if (ans != INF) {
			pint(ans);
			repi(i,0,27)
					{
						if(ans ==arr1[fm - 'A'][i] + arr2[to - 'A'][i]){
							psp(),pc(i+'A');
						}
					}
			pnl();
		} else {
			puts("You will never meet.");
		}
	}

	return 0;
}
