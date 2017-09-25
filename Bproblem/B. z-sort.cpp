#include <bits/stdc++.h>
using namespace std;
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define rln() getchar()
#define rint(n) scanf("%d",&n)
#define rs(n) scanf("%s",n)
#define rc(n) scanf("%c",&n)
#define rf(n) scanf("%lf",&n)
#define rl(n) scanf("%I64d",&n)
#define pint(x) printf("%d", x)
#define psp() printf(" ")
#define ps(x) printf("%s", x)
#define pc(x) printf("%c", x)
#define pnl() printf("\n")
#define pl(x) printf("%I64d", x)
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
priority_queue<ll> q;
priority_queue<ll> qm;
priority_queue<ll> ql;
int main() {
	int n;
	rint(n);
	ll xx;
	repi(i,0,n)
	{
		rl(xx);
		q.push(xx);
	}
	int nl, ns;
	if (n % 2 == 0) {
		nl = ns = n / 2;
	} else {
		nl = n / 2;
		ns = n - nl;
	}
	while(nl--){
		ql.push(q.top());
		q.pop();
	}
	while(ns--){
		qm.push(q.top());
		q.pop();
	}
	while(qm.size() || ql.size()){
		if(qm.size()){
			pl(qm.top());
			psp();
			qm.pop();
		}
		if(ql.size()){
			pl(ql.top());
			psp();
			ql.pop();
		}
	}
	return 0;
}
