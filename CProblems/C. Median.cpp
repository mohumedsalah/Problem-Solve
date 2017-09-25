#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef pair<int, int> ii;
vector<int> arr;
vector<ii> vv;
int main() {

	int n, x, xx, f = 0;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &xx);
		arr.push_back(xx);
		if (xx == x)
			f = 1;
	}
	if (!f)
		arr.push_back(x);
	sort(arr.begin(), arr.end());
	int sz = arr.size() - 1;
	for (int i = 0; i <= sz; i++) {
		if(arr[i] == x){
			vv.push_back(ii(i ,sz - i));
		}
	}
	int ans = 1e7;
	for(int i = 0 ; i < (int)vv.size();i++){
		if(vv[i].f < vv[i].s){
			ans = min(ans, vv[i].s - 1 - vv[i].f);
		}else if(vv[i].f > vv[i].s){
			ans = min(ans, vv[i].f - vv[i].s);
		}else{
			ans = 0;
			break;
		}
	}
	if(!f)
		ans++;
	printf("%d",ans);
	return 0;
}
