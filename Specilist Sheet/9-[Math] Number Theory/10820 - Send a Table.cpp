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
ll _sieve_size;
bitset<10000010> bs;
vi primes;
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
ll EulerPhi(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = N;
	while (PF * PF <= N) {
		if (N % PF == 0)
			ans -= ans / PF;
		while (N % PF == 0)
			N /= PF;
		PF = primes[++PF_idx];
	}
	if (N != 1)
		ans -= ans / N;
	return ans;
}
ll ans[600000];
ll solve(ll inx){
	ll &ret = ans[inx];
	if(ret != -1)
		return ret;
	if(inx == 1)
		return ans[inx] = 1ll;
	return ret = solve(inx - 1) + 2ll * EulerPhi(inx);
}
int main() {
	freopen("in.txt", "r" , stdin);
	memset(ans , -1 , sizeof ans);
	sieve(10000000ll);
	ll n;
	while(rl(n) && n){
		pl(solve(ll(n)));
		pnl();
	}
	return 0;
}
