#include <bits/stdc++.h>
using namespace std;

#define FOR( A, B, C ) for ( int A = B, _end_ = C; A <= _end_; A++ )
#define ROF( A, B, C ) for ( int A = B, _end_ = C; A >= _end_; A-- )
#define ll long long
#define OTL "%I64d"

ll pre[1100000], Q;

int n;

int main() {
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		ll t;
		scanf( OTL, &t);
		Q ^= t;
	}

	FOR(i, 1, n)
	{
		pre[i] = pre[i - 1] ^ i;
	}

	FOR(i, 1, n)
	{
		if ((n / i) % 2 == 1)
			Q ^= pre[i - 1];
		Q ^= pre[n % i];
	}

	printf( OTL, Q);
	return 0;
}
