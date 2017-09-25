#include <bits/stdc++.h>

using namespace std;
int vis[11][11];
queue<int> a;
queue<int> b;
vector<int> vv;
int main() {
	memset(vis, -1, sizeof vis);
	int n, k1, k2, xx;
	scanf("%d %d", &n, &k1);
	for (int i = 0; i < k1; i++) {
		scanf("%d", &xx);
		a.push(xx);
	}

	scanf("%d", &k2);
	for (int i = 0; i < k2; i++) {
		scanf("%d", &xx);
		b.push(xx);
	}

	int ret = 0;
	while(a.size() && b.size()){
		int cura = a.front();
		int curb = b.front();
		a.pop(),b.pop();
		if(vis[cura][curb] == 10){
			puts("-1");
			return 0;
		}
		ret++;
		vis[cura][curb]++;
		if(cura > curb){
			a.push(curb);
			a.push(cura);
		}else{
			b.push(cura);
			b.push(curb);
		}
	}
	printf("%d ",ret);
	if(a.size()){
		puts("1");
	}else{
		puts("2");
	}
	return 0;
}
