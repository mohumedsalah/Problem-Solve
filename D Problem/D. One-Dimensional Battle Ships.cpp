#include <bits/stdc++.h>

using namespace std;

// Input macros
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define si(n) scanf("%d",&n)
#define sii(n, m) scanf("%d%d",&n,&m)
#define siii(n, m, x) scanf("%d%d%d",&n,&m,&x)
#define siiii(n, m, x, y) scanf("%d%d%d%d",&n,&m,&x,&y)
#define sc(n) scanf(" %c",&n)
#define sd(n) scanf("%lf",&n)
#define nextLine(s) getline(cin, s)
#define stringTokenizer(s) istringstream iss(s)
#define nextToken(s) iss >> s
#define read(s) freopen(s, "r", stdin)
#define write(s) freopen(s, "w", stdout);
#define endl '\n'

// Useful constants
#define INF (int)1e9
#define EPS 1e-9

// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd

// Traversal macros
#define forn(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n-1; i >= 0; i--)
#define forall(i, a, b, x) for (int i = a; i < b; i+=x)
#define foreach(v, c) for (typeof(c.begin()) v = c.begin(); v != c.end(); v++)

// Useful container manipulation
#define all(a) a.begin(), a.end()
#define in(a, b) (b.find(a) != b.end())
#define pb push_back
#define fill(a, v) memset(a, v, sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define f first
#define s second
#define parseInt(x) atoi(x.c_str())
#define parseLong(x) atoll(x.c_str())
#define charToInt(x) x - '0'
#define intToChar(x) x + '0'
#define toString(x) dynamic_cast< std::ostringstream & >( \
( std::ostringstream() << std::dec << x ) ).str()

// Printing
#define print(a, s) { forn(_i, s) { if (_i > 0) cout << " "; cout << a[_i]; } puts(""); }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef pair<double, int> di;
typedef pair<long long, long long> llll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int> > vii;
typedef vector<pair<char, char> > vcc;
typedef vector<pair<int, char> > vic;
typedef vector<pair<long long, long long> > vll;
typedef map<int, int> mii;
typedef map<string, int> msi;

int n, k, a, m;
int moves[200005];
bool field[200005];

bool valid(int current)
{
    fill(field, 0);
    forn(i, current+1)
        field[moves[i]] = 1;

    int ships = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if (field[i])
            cur = 0;
        else
            cur++;

        if (cur == a)
        {
            ships++;
            i++;
            cur = 0;
        }
    }

    return ships < k;
}

int main()
{
    siiii(n, k, a, m);
    forn(i, m)
        si(moves[i]);

    int low = 0, high = m-1, ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if (valid(mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }

    printf("%d\n", ans == -1 ? -1 : ans+1);
}
