#include <bits/stdc++.h>
using namespace std;
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define rln() getchar()
#define rint(n) scanf("%d",&n)
#define rs(n) scanf("%s",n)
#define rc(n) scanf("%c",&n)
#define rf(n) scanf("%lf",&n)
#define rl(n) scanf("%I64",&n)
#define pint(x) printf("%d", x)
#define psp() printf(" ")
#define ps(x) printf("%s", x)
#define pc(x) printf("%c", x)
#define pnl() printf("\n")
#define pl(x) printf("%I64", x)
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
char arr[10][10];
char sh[] = { 'q', 'r', 'b', 'n', 'p', 'k' };
int vsh[] = { 9, 5, 3, 3, 1, 0 };
int main() {

	repi(i,0,8)
	{
		rs(arr[i]);
	}
	int fk1 = 0, fk2 = 0;
	int b = 0, w = 0;
	repi(i,0,8)
	{
		repi(j,0,8)
		{
			if ('a' <= arr[i][j] && arr[i][j] <= 'z') {
				if (arr[i][j] == 'k')
					fk1 = 1;
				repi(k,0,6)
				{
					if (arr[i][j] == sh[k]) {
						b += vsh[k];
					}
				}
			} else {
				arr[i][j] = tolower(arr[i][j]);
				if (arr[i][j] == 'k')
					fk1 = 1;
				repi(k,0,6)
				{
					if (arr[i][j] == sh[k]) {
						w += vsh[k];
					}
				}
			}
		}
	}
	//cout <<  w << " " << b << endl;
	if(w > b){
		puts("White");
	}else if (b > w){
		puts("Black");
	}else{
		puts("Draw");
	}

	return 0;
}
