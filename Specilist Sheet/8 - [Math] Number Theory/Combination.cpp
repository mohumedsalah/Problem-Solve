#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
long long unsigned solve(int n , int m){
	int temp1 = max(m,n-m);
	int temp2 = min(m , n - m);
	vector<int> a, b;
	for (int i = 1; i <= temp2 ; i++)
		b.push_back(i);
	for(int i = temp1 + 1  ; i <= n  ; i++)
		a.push_back(i);
	for(int i  = 0 ; i < b.size(); i++){
		for(int j = 0 ; j < a.size(); j++){
			int g = gcd(b[i], a[j]);
			b[i] /= g;
			a[j] /= g;
			if(b[i] == 1)
				break;
		}
	}
	long long unsigned ret = 1;
	for(int i = 0; i < a.size(); i++)
		ret *= a[i];
	return ret;

}
int main(){

	int n , m ;
	cin >> n >> m ;
	cout << solve(n , m) << endl;

	return 0;
}
