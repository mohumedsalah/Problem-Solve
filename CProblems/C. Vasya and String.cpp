#include <bits/stdc++.h>
using namespace std;
int const mx = 1e5 + 6;
char arr[mx];
int k, n;
int solve(char b){
	int  tret = 0, mret = 0,conv = 0;
	int p = 0;
	for(int i = 0; i < n;i++){
		if(arr[i] == b){
			tret++;
			continue;
		}
		conv++;
		mret = max (tret, mret);
		while(conv > k){
			if(arr[p] != b)
				conv--;
			tret--;
			p++;
		}
		tret++;
	}
	return max(mret, tret);
}
int main() {

	scanf("%d%d", &n, &k);
	scanf("%s", arr);
	int ret = max(solve('a'), solve('b'));
	printf("%d", ret);
	return 0;
}
