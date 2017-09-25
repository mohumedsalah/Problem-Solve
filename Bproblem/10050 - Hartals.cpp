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

set<int> possibleScores;

const int Highest = 181;
const int HighestScore = 65; // Slightly higher
ll combinations[Highest][HighestScore][4];
ll permutations[Highest][4];

// Must use num >= highestThrown
int GetComb(int scoreLeft, int highestThrown, int throwsLeft)
{
    if (scoreLeft == 0 && throwsLeft == 0)
        return 1;
    else if (scoreLeft <= 0 || throwsLeft == 0 || scoreLeft >= Highest)
        return 0;

    ll &combs = combinations[scoreLeft][highestThrown][throwsLeft];
    if (combs == -1)
    {
        combs = 0;
        for (set<int>::iterator score = possibleScores.lower_bound(highestThrown); score != possibleScores.end(); ++score)
        {
            combs += GetComb(scoreLeft - *score, *score, throwsLeft - 1);
        }
    }

    return combs;
}

int GetPerm(int scoreLeft, int throwsLeft)
{
    if (scoreLeft == 0)
        return 1;
    else if (scoreLeft < 0 || throwsLeft == 0 || scoreLeft >= Highest)
        return 0;

    ll &perms = permutations[scoreLeft][throwsLeft];
    if (perms == -1)
    {
        perms = 0;
        for (set<int>::iterator score = possibleScores.begin(); score != possibleScores.end(); ++score)
        {
            perms += GetPerm(scoreLeft - *score, throwsLeft - 1);
        }
    }

    return perms;
}

int main()
{
    int goal;
    for (int i = 0; i <= 20; ++i)
    {
        possibleScores.insert(i);
        possibleScores.insert(i * 2);
        possibleScores.insert(i * 3);
    }
    possibleScores.insert(50);

    for (int i = 0; i < Highest; ++i)
        for (int t = 0; t < 4; ++t)
            permutations[i][t] = -1;

    for (int i = 0; i < Highest; ++i)
        for (int s = 0; s < HighestScore; ++s)
            for (int t = 0; t < 4; ++t)
                combinations[i][s][t] = -1;


    while (cin >> goal, goal > 0)
    {
        int perms = GetPerm(goal, 3);
        if (perms == 0)
            cout << "THE SCORE OF " << goal << " CANNOT BE MADE WITH THREE DARTS.\n";
        else
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << goal << " IS " << GetComb(goal, 0, 3) << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << goal << " IS " << perms << ".\n";

        }
        cout << "**********************************************************************\n";
    }

    cout << "END OF OUTPUT\n";
}
