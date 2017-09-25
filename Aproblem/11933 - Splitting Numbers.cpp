#include <bits/stdc++.h>

using namespace std;
vector<bool> vv;
int main() {
	//freopen("in.txt", "r", stdin);
	long long a, x, y;
	int cnt;
	bool f;
	while (scanf("%lld", &a) && a ) {
		vv.clear();
		cnt = 0;
		x = 0, y = 0;
		f = 1;
		while(a){
			 vv.push_back(a%2);
			 a /= 2;
		}
		int f = 1;
		for(int i = 0 ; i < vv.size();i++){
			//cout << vv[i] ;
			if(vv[i]){
				if(f){
					x += pow(2,i);
					f = 0;
				}else{
					y += pow(2,i);
					f = 1;
				}
			}
		}
		printf("%lld %lld\n", x, y);
	}

	return 0;
}
