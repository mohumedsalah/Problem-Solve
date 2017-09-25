#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
map<ll, pll> mp;
map<ll, pll>::iterator it;
ll mod = 1000000007;
inline ll p(ll x,ll a){
	if(!a)	return 1LL;
	ll b = p(x,a/2LL);
	b = (b * b)%mod;
	if(a % 2LL)
		b = (b * x)%mod;
	return b;
}
int main(){
	ll n;
	cin >> n;
	if(!n)
		cout << 1 << endl;
	else
		cout << (p(2LL,n-1LL) + p(2LL,2LL * n - 1LL))%mod << endl;
}
