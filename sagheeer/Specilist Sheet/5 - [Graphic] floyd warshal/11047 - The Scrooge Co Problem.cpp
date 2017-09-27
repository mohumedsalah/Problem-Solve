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
map<string, int>::iterator it;
string xx, xx1, temp;
int arr[123][123];
int pth[123][123];
string str[123];
void build_pah(int src, int des) {
	if (pth[src][des] == -1) {
		printf("%s ", str[src].c_str());
		return;
	}
	build_pah(src, pth[src][des]);
	build_pah(pth[src][des], des);

}
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	rint(t);
	while (t--) {
		memset(pth, -1 , sizeof pth);
		mpp.clear();
		int n, yy;
		rint(n);
		repi(i,0, n)
		{
			cin >> xx;
			mpp[xx] = i + 1;
			str[i + 1] = xx;
		}
		repi(i,1, n + 1)
			repi(j,1, n + 1)
				rint(yy), (yy == -1) ? arr[i][j] = INF : arr[i][j] = yy;
		repi(k,1, n + 1)
			repi(i,1, n+1)
				repi(j,1, n+2)
				{
					if (arr[i][j] <= arr[i][k] + arr[k][j]) {
						continue;
					}
					arr[i][j] = arr[i][k] + arr[k][j];
					pth[i][j] = k;
				}
		int q;
		rint(q);
		while (q--) {
			cin >> temp >> xx >> xx1;
			int src = mpp[xx], des = mpp[xx1];
			if (arr[src][des] < INF) {
				printf(
						"Mr %s to go from %s to %s, you will receive %d euros\nPath:",
						temp.c_str(), xx.c_str(), xx1.c_str(), arr[src][des]);
				build_pah(src, des);
				printf("%s", xx1.c_str());
				pnl();
			} else {
				printf("Sorry Mr %s you can not go from %s to %s\n",
						temp.c_str(), xx.c_str(), xx1.c_str());
			}

		}
	}

	return 0;
}
