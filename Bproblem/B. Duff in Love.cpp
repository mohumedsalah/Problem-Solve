#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> b;
bool che(int inx){
	ll num = b[inx];
	for(ll i = 2 ; i*i<= num ;i++){
		ll f = i * i;
		if(num % f == 0)
			return 0;
	}
	return 1;
}
int main(){

	ll n;
	cin >>n;

	ll i;
	for(i = 1 ; i*i < n;i++){
		if(n % i == 0)
			b.push_back(i),b.push_back(n/i);
	}
	if(i * i == n)
		b.push_back(i);
	sort(b.begin(),b.end());
	//int s = 0, e =(int) b.size() - 1;
	for(int i = b.size() - 1  ; i >=0;i--){
		if(che(i)){
			cout << b[i] << endl;
			return 0;
		}
	}
	return 0;
}
