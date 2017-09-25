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
//#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
string a, b;
pss dic[20];
char instr[20];
map<string, int> mp;
map<string, int>::iterator it;
string conv(string a, string from, string to) {
	int cons = to.size() - from.size();
	string oa = a;
	int cnt = 0;
	size_t found = oa.find(from, cnt);
	cnt = 0;
	while (found != string::npos) {
		a.replace(found + cons * cnt, from.size(), to);
		found = oa.find(from, found + from.size());
		cnt++;
	}
	return a;
}
queue<pair<string, int> > q;
int main() {
	//string a = conv("xxaxxx","xx","acb");
	//cout << a << endl;
	int t;
	string xx;
	while (rint(t) && t) {
		mp.clear();
		while (q.size())
			q.pop();
		repi(i,0,t)
		{
			rs(instr);
			xx = instr;
			dic[i].f = xx;
			rs(instr);
			xx = instr;
			dic[i].s = xx;
		}
		rs(instr);
		a = instr;
		//cout << a << endl;
		rs(instr);
		b = instr;
		q.push(psi(a, 0));
		int flag = 1;
		while (q.size()) {
			psi cur = q.front();
			q.pop();
			if (cur.f == b) {
				pint(cur.s);
				pnl();
				flag = 0;
				break;
			}
			if (cur.f.size() > 15)
				continue;
			for (int i = 0; i < t; i++) {
				string neww = conv(cur.f, dic[i].f, dic[i].s);
				it = mp.find(neww);
				if (it != mp.end())
					continue;
				mp[neww] = 1;
				q.push(psi(neww, cur.s + 1));
			}
		}
		if (flag)
			puts("-1");
	}

	return 0;
}

