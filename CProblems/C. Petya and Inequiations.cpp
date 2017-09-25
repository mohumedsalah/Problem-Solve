#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	long long x, y;
	cin >> n >> x >> y;
	if((y - (long long)n + 1) <= 0 || ((y - (long long)n + 1) * (y - (long long)n + 1)) + (n - 1) < x){
		cout << -1 ;
	}else{
		cout << y - n + 1 << endl;
		for(int i = 1 ; i < n ;i++){
			puts("1");
		}
	}
	return 0;
}
