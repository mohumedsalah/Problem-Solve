//============================================================================
// Name        : c.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, int> mp;
map<int, int>::iterator it;
map<int, int>::iterator it1;
int main() {
	int n, xx;
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &xx);
		mp[xx]++;
		for (int j = 1; j <= 31; j++) {
			ll b = (ll)pow(2, j) - xx;
			it1 = mp.find(b);
			if (it1 == mp.end())
				continue;
			if(b == xx){
				ans += (ll)mp[b] * (ll)(mp[b] - 1) / 2 - (ll)(mp[b] - 1) * (ll)(mp[b] - 2) / 2 ;
				//cout << xx <<" " << b << " "<< ans << endl;
				continue;
			}
			ans += (ll)mp[b];

		}

	}
	cout << ans;
	return 0;
}
