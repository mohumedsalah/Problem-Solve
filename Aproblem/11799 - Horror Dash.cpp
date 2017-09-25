#include <bits/stdc++.h>

using namespace std;
string s;
int mx = -1;
int v;
int main(){

	int t;
	scanf("%d",&t);
	getchar();
	int cnt = 0;
	while(t--){
		stringstream sin;
		getline(cin , s);
		sin << s;
		mx = -1;
		while(sin >> v){
			mx = max(mx,v);
		}
		printf("Case %d: %d\n",++cnt,mx);
	}


	return 0;
}
