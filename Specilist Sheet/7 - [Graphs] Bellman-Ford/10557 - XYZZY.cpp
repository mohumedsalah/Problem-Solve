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


int en[100];
vector<int> adjList[100];
int dist[100];
bool been[100];
int n;

bool dfs(int v)
{
    been[v] = true;
    for(int i = 0; i < (int)adjList[v].size(); i++)
    {
        int o = adjList[v][i];
        if(o == n-1)
        {
            return true;
        }
        if(!been[o] && dfs(o))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    while(scanf("%d", &n) != EOF && n != -1)
    {
        for(int i = 0; i < n; i++)
        {
            int adj;
            adjList[i].clear();
            scanf("%d %d", &en[i], &adj);
            en[i] /= -1;
            int a;
            while(adj--)
            {
                scanf("%d", &a);
                a--;
                adjList[i].push_back(a);
            }
            dist[i] = 1000000;
        }
        dist[0] = -100;
        for(int i = 0; i < n-1; i++)
        {
            for(int r = 0; r < n; r++)
            {
                for(int a = 0; a < (int)adjList[r].size(); a++)
                {
                    int o = adjList[r][a];
                    if(dist[r] + en[o] < 0)
                    {
                        dist[o] = min(dist[o], dist[r] + en[o]);
                    }

                }
            }
        }

        if(dist[n-1] <= 0)
        {
            goto win;
        }
        else
        {
            // detect negative cycle
            for(int i = 0; i < n; i++)
            {
                for(int a = 0; a < (int)adjList[i].size(); a++)
                {
                    int o = adjList[i][a];
                    if(dist[i] + en[o] < 0 && dist[i] + en[o] < dist[o])
                    {
                        memset(been, 0, sizeof(been));
                        if(dfs(i))
                        {
                            goto win;
                        }
                    }
                }
            }
            goto lose;
        }
win:
        printf("winnable\n");
        continue;
lose:
        printf("hopeless\n");
        continue;
    }

    return 0;
}
