
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll,int> pli;
int n, a,b;
ll d;
pli arr[100005];
int solve(int m){
	long long ret = 0;
	for(int i = 0 ; i <= m ;i++){
		ret += arr[i].f;
		if(ret > d)
			return 0;
	}
	return 1;
}
int main() {
	long long xx , yy;
	int x,y;
	scanf("%d",&n);
	cin >> d;
	scanf("%d %d",&a,&b);
	for(int i = 0; i  < n;i++){
		scanf("%d %d",&x,&y);
		xx = x * (ll)a;
		yy = y * (ll)b;
		arr[i] = pli(xx+yy,i+1);
	}
	sort(arr, arr + n);
	int st = 0,e = n - 1;
	int ans = -1;
	while(st - 1 < e){
		int m = (st + e) /2;
		if(solve(m)){
			st = m +1;
			ans = m;
		}else
			e = m -1;
	}
	printf("%d\n",ans + 1);
	for(int i = 0 ; i <= ans ;i++){
		printf("%d ",arr[i].s);
	}
}
