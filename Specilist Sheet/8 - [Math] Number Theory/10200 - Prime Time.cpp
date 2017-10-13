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
#define pf(x) printf("%.2lf", x)
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
ll _sieve_size;
bitset<10000010> bs;
vi primes;
int dp[10100];
void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++)
		if (bs[i]) {
			for (ll j = i * i; j <= _sieve_size; j += i)
				bs[j] = 0;
			primes.push_back((int) i);

		}
}
bool isPrime(ll N) {
	if (N <= _sieve_size)
		return bs[N];
	for (int i = 0; i < (int) primes.size(); i++)
		if (N % primes[i] == 0)
			return false;
	return true;
}

int main() {
	//pf(4.550);
	//cout << sqrt(100000000ll) << endl;
	freopen("in.txt", "r", stdin);
	sieve(10010);
	repi(i,0, 10000 + 1)
	{
		ll tt = ll(i) * ll(i) + ll(i) + 41ll;
		//cout << tt << endl;
		if (isPrime(tt))
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = dp[i - 1];
	}
	int a, b;
	while (cin >> a) {
		rint(b);
		double ret;
		if(a > 0)
			ret =double(dp[b]) - double(dp[a - 1]) ;
		else
			ret =double( dp[b]);
		//cout << ret << " " << (double(b) - a + 1.0)  << endl;
		double ans = ret / (double(b) - double(a) + double(1.0)) * double(100.0) + 1e-9;
		pf(ans), pnl();
	}

	return 0;
}
