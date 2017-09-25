#include <bits/stdc++.h>
using namespace std;
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define iln() scanf("\n")
#define in(n) scanf("%d",&n)
#define ins(n) scanf("%s",n)
#define inc(n) scanf("%c",&n)
#define inf(n) scanf("%lf",&n)
#define inl(n) scanf("%lld",&n)
#define ot(x) printf("%d", x)
#define sp() printf(" ")
#define ots(x) printf("%s", x)
#define otc(x) printf("%c", x)
#define ln() printf("\n")
#define otl(x) printf("%lld", x)
#define otf(x) printf("%.14lf", x)
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
map<string, string> mpo;
map<string, string> mpn;
map<string, string>::iterator ito;
map<string, string>::iterator itn;
char arr[2000000];
int ptr;

string tackstring(char c, int n) {
	string ret = "";
	while (ptr < n - 1 && arr[ptr] != c) {
		ret += arr[ptr];
		ptr++;
	}
	ptr++;
	return ret;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int t, n;
	string key, value;
	in(t);
	while (t--) {

		//ostringstream mm;
		mpo.clear();
		mpn.clear();
		for (int i = 0; i < 2; i++) {
			ptr = 1;
			ins(arr);
			//ots(arr);
			n = ssz(arr);
			while (ptr < n - 2) {
				key = tackstring(':', n);
				value = tackstring(',', n);
				if (i == 0)
					mpo[key] = value;
				else
					mpn[key] = value;
			}
		}
		int f1 = 0;
		for (itn = mpn.begin(); itn != mpn.end(); itn++) {
			ito = mpo.find(itn->f);
			if (ito == mpo.end()) {
				if (!f1) {
					printf("+");
					cout << itn->f;
					f1 = 1;
				} else {
					printf(",");
					cout << itn->f;
				}
			}

		}
		if (f1)
			printf("\n");
		int f2 = 0;
		for (ito = mpo.begin(); ito != mpo.end(); ito++) {
			itn = mpn.find(ito->f);
			if (itn == mpn.end()) {
				if (!f2) {
					printf("-");
					cout << ito->f;
					f2 = 1;
				} else {
					printf(",");
					cout << ito->f;
				}
			}
		}
		if (f2)
			printf("\n");
		int f3 = 0;
		for (ito = mpo.begin(); ito != mpo.end(); ito++) {
			itn = mpn.find(ito->f);
			if (itn != mpn.end() && itn->s != ito->s) {
				if (!f3) {
					printf("*");
					cout << ito->f;
					f3 = 1;
				} else {
					printf(",");
					cout << ito->f;
				}
			}
		}
		if(f3)
			printf("\n");
		if (!f1 && !f2 && !f3) {
			printf("No changes\n");
		}

		printf("\n");

	}


	return 0;
}
