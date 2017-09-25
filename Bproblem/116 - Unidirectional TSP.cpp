#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 2000000000
#define MOD 1000000007


LL memo[110][110],cost[110][110],m,n,parent[110][110];
LL func(LL r,LL c)
{
    if(c==n)    return cost[r][c];
    if(memo[r][c]!=-1)      return memo[r][c];

    LL ret=cost[r][c];
    LL mn;

    if(m==1)
    {
        ret+=func(r,c+1);
        parent[r][c]=r;
    }
    else if(m==2)
    {
        mn=min(func(1,c+1),func(2,c+1));
        ret+=mn;
        if(mn==func(1,c+1))
            parent[r][c]=1;
        else
            parent[r][c]=2;
    }
    else if(r==m)
        {
            mn=min3(func(r-1,c+1),func(r,c+1),func(1,c+1));
            ret+=mn;
            if(mn==func(1,c+1))
                parent[r][c]=1;
            else if(mn==func(r-1,c+1))
                parent[r][c]=r-1;
            else
                parent[r][c]=r;
        }

    else if(r==1)
        {
            mn=min3(func(m,c+1),func(r,c+1),func(r+1,c+1));
            ret+=mn;
            if(mn==func(r,c+1))
                parent[r][c]=r;
            else if(mn==func(r+1,c+1))
                parent[r][c]=r+1;
            else
                parent[r][c]=m;
        }
    else
    {
        mn=min3(func(r-1,c+1),func(r,c+1),func(r+1,c+1));
        ret+=mn;
        if(mn==func(r-1,c+1))
            parent[r][c]=r-1;
        else if(mn==func(r,c+1))
            parent[r][c]=r;
        else
            parent[r][c]=r+1;
    }

    return memo[r][c]=ret;
}

int main()
{
    //READ;
    //WRITE;
    while(cin>>m>>n)
    {
        SET(memo);
        CLR(cost);
        CLR(parent);

        for(LL i=1;i<=m;i++)
            for(LL j=1;j<=n;j++)
                cin>>cost[i][j];

        LL mn;
        mn=func(1,1);
        LL st=1;
        for(LL i=2;i<=m;i++)
            if(func(i,1)<mn)
            {
                mn=func(i,1);
                st=i;
            }

        cout<<st;
        LL x=parent[st][1];
        for(LL i=2;i<=n;i++)
            {
                cout<<" "<<x;
                x=parent[x][i];
            }
        cout<<endl<<mn<<endl;

    }
}
