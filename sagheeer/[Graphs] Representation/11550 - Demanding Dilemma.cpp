#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;

int matrix [8 + 3] [30 + 3];

int main ()
{
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int n, m;
        scanf ("%d %d", &n, &m);

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ )
                scanf ("%d", &matrix [i] [j]);
        }

        bool output = true;

        for ( int i = 0; i < m; i++ ) {
            int sum = 0;
            for ( int j = 0; j < n; j++ )
                sum += matrix [j] [i];
            if ( sum != 2 ) output = false;
        }

        bool vertex [8 + 3] [8 + 3];
        memset (vertex, false, sizeof (vertex));

        if ( output ) {
            for ( int i = 0; i < m; i++ ) {
                int first, second, j = 0;
                while ( matrix [j++] [i] != 1 );
                first = j - 1;
                while ( matrix [j++] [i] != 1 );
                second = j - 1;

                if ( !vertex [first] [second] ) vertex [first] [second] = vertex [second] [first] = true;
                else output = false;
            }
        }

        if ( output ) printf ("Yes\n");
        else printf ("No\n");
    }

    return 0;
}
