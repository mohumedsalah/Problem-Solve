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
int f[26], t[26], n[26];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w", stdout);
	string sf , st;
	cin >> sf >> st;
	for(auto c : sf)
		f[c - 'A']++;
	for(auto c : st)
		t[c - 'A']++;
	int ans=  0;
	repi(i,0,26){
		if(t[i] > f[i])
			ans += (t[i] - f[i]);
	}
	pint(ans), pnl();
	int mn = 0;
	for(auto ch : sf){
		if(f[ch - 'A'] > t[ch - 'A']){
			while(t[mn] - f[mn] <= 0){
				mn++;
			}
			if (t[ch - 'A'] == 0 || mn < (ch - 'A') )  {
				pc((mn + 'A'));
				t[mn]--;
			}else{
				pc(ch);
				t[ch - 'A']--;
			}
		}else{
			pc(ch);
			t[ch - 'A']--;
		}
		f[ch - 'A']--;
	}


	return 0;
}
