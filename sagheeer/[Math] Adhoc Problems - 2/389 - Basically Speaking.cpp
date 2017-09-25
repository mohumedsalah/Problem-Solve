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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;

char ch[] = "0123456789ABCDEF";
map<char, int> mp;
string convfromdecimal(int ns, int v) {
	if(v == 0)
		return "0";
	string ret = "";
	while (v) {
		int t = v % ns;
		ret += ch[t];
		v /= ns;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int convtodecimal(int ns, string v) {
	int ans = 0;
	int pw = 1;
	for (int i = sz(v) - 1; i >= 0; i--) {
		ans += pw * mp[v[i]];
		pw *= ns;
	}
	return ans;
}
int main() {
	//freopen("in.txt", "r", stdin);
	repi(i,0,17)
	{
		mp[ch[i]] = i;
	}
	string ss;
	int a, b;
	while (cin >> ss) {
		rint(a), rint(b);
		int temp = convtodecimal(a, ss);
		string ss = convfromdecimal(b, temp);
		//cout << ss << endl;
		if (sz(ss) > 7)
			ss = "ERROR";
		printf("%7s\n", ss.c_str());
	}
	return 0;
}
