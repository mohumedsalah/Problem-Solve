#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll d[1000005];
void divconstruct(){
	memset(d, 0, sizeof d);
	for(int i = 1 ; i <= 1e6 ;i++){
		for(int j = i ; j <= 1e6;j+=i){
			d[j] = (d[j] % 1073741824)+ 1;
		}
	}
}

int main(){
	divconstruct();
	int a, b, c;
	scanf("%d%d%d", &a , &b , &c);
	ll ret = 0;
	for(int i = 1 ;i <= a; i++){
		for(int j = 1; j <= b;j++){
			for(int k = 1 ; k<= c;k++){
				ret +=  d[i*j*k];
			}
		}
	}
	cout << ret << endl;
	return 0;
}
