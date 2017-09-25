#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll t, n;
int main() {
	freopen("cake.in", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		ll ans = 0;
		ll s = 0  , e = 10005;
		while(s <= e){
			int m =(s+e)/2;
			ans = (pow(m , 2) + m + 2)/2;
			if(ans < n ){
				s = m + 1;
			}
			else
				e = m-1;
		}

		cout << s << endl;
	}

	return 0;
}
