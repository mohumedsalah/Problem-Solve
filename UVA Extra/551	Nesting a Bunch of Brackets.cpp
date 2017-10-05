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


stack<char> checker;
map<char, char> mpp;
bool isOpening(char c) {
	if (c == '(' || c == '[' || c == '<' || c == '{')
		return true;
	return false;
}

bool isClosing(char c) {
	if (c == ')' || c == ']' || c == '>' || c == '}')
		return true;
	return false;
}

int main() {
	mpp['>'] = '<';
	mpp[')'] = '(';
	mpp[']'] = '[';
	mpp['}'] = '{';
	char s[3001];
	while (gets(s)) {
		int count = 0;
		int len = strlen(s), i;
		for (i = 0; i < len; i++) {
			count++;
			if (isOpening(s[i])) {
				if (s[i] == '(' && s[i + 1] == '*') {
					checker.push('*');
					i++;
				} else {
					checker.push(s[i]);
				}
			} else if (isClosing(s[i]) || (s[i] == '*' && s[i + 1] == ')')) {
				if (checker.empty())
					break;
				if (s[i] == '*') {
					if (checker.top() != '*') {
						break;
					}
					checker.pop();
					i++;
				} else {
					if (checker.top() != mpp[s[i]]) {
						break;
					}
					checker.pop();
				}
			}
		}

		if (i < len || !checker.empty()) {
			if (i >= len && !checker.empty())
				count++;
			printf("NO %d\n", count);
		} else
			printf("YES\n");

		while (!checker.empty())
			checker.pop();
	}

	return 0;
}
