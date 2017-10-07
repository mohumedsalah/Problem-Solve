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
bitset<10000100> bs;
vi primes;
map<int, int> mpp;
map<int, int>::iterator it;
void seive() {
	bs.set();
	bs[0] = bs[1] = 1;
	for (ll i = 2; i < 1e6 + 1000; i++) {
		if (bs[i]) {
			primes.pb(i);
			for (ll j = i * i; j < 1e6 + 1000; j += i) {
				bs[j] = 0;
			}
		}
	}
}
int main() {
	//freopen("in.txt","r", stdin);
	//freopen("out.txt","w", stdout);
	seive();
	int t, a, b;
	rint(t);
	while (t--) {
		mpp.clear();
		rint(a), rint(b);
		int fpos = lower_bound(primes.begin(), primes.end(), a)
				- primes.begin();
		//cout << fpos << endl;
		for (int i = fpos;; i++) {
			//cout << b  << endl;
			if (primes[i + 1] > b)
				break;
			mpp[primes[i + 1] - primes[i]]++;
			//cout << primes[i + 1] - primes[i] << endl;
		}
		int mxf = 0;
		int ans = 0;
		for (it = mpp.begin(); it != mpp.end(); it++) {
			if(mxf < it->s){
				ans = it->f;
				mxf = it->s;
			}
		}
		int fl = 0;
		for (it = mpp.begin(); it != mpp.end(); it++) {
			if(mxf == it->s)
				fl++;
		}
		//cout << fl << " " << mxf << endl;
		if(fl >= 2 || mxf == 0){
			puts("No jumping champion");
		}else{
			printf("The jumping champion is %d\n", ans);
		}
	}

	return 0;
}
