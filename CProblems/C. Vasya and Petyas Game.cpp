#include <bits/stdc++.h>
using namespace std;
int p[1010];
vector<int> vv;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n;i++){
		if(p[i] == 1)
			continue;
		for(int j = i+i ; j <= n ;j+=i)
			p[j] = 1;
	}

	for (int i = 2; i <= n; i++) {
		if(p[i] == 1)
			continue;
		for(int j = i ; ; j*=i){
			vv.push_back(j);
			if(j*i > n)
				break;
		}
	}
	int vl = vv.size();
	printf("%d\n", vl);
	for (int i = 0; i < (int)vv.size(); i++)
		printf("%d ", vv[i]);
	return 0;
}
