#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> ii;
int const mx = 1e5 + 9;
ii arr[mx];
bool cmp(ii a, ii b) {
	return hypot(a.f, a.s) < hypot(b.f, b.s);
}
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	ll xx, yy;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld",&xx,&yy);
		arr[i] = ii(xx, yy);
	}

	sort(arr, arr + n, cmp);
	int k = 0;
	for (int i = 0; i < n; i++) {
			if (arr[i].f == 0) {
					k +=4;
			} else if (arr[i].s == 0) {
				k +=4;
			} else {
				k+=6;
			}
		}
	printf("%d\n",k);
	for (int i = 0; i < n; i++) {
		if (arr[i].f == 0) {
			if (arr[i].s > 0) {
				printf( "1 %lld U\n2\n1 %lld D\n3\n",  arr[i].s , arr[i].s) ;
			} else {
				printf( "1 %lld D\n2\n1 %lld U\n3\n",  -1*arr[i].s , -1*arr[i].s) ;
			}
		} else if (arr[i].s == 0) {
			if (arr[i].f > 0) {
				printf( "1 %lld R\n2\n1 %lld L\n3\n",  arr[i].f , arr[i].f) ;
			} else {
				printf( "1 %lld L\n2\n1 %lld R\n3\n",  -1*arr[i].f , -1*arr[i].f) ;
			}
		} else {
			if (arr[i].f > 0 && arr[i].s > 0) {
				printf("1 %lld R\n1 %lld U\n2\n1 %lld D\n1 %lld L\n3\n", arr[i].f, arr[i].s, arr[i].s, arr[i].f);
				//cout << "1 " << arr[i].f << " R\n1 " << arr[i].s <<  " U\n2\n"<< "1 " << arr[i].s <<  " D\n1 " << arr[i].f << " L\n3\n";
			} else if (arr[i].f < 0 && arr[i].s > 0) {
				printf("1 %lld L\n1 %lld U\n2\n1 %lld D\n1 %lld R\n3\n", -1*arr[i].f, arr[i].s, arr[i].s, -1*arr[i].f);
				//cout << "1 " << -1*arr[i].f << " L\n1 " << arr[i].s <<   " U\n2\n"<< "1 " << arr[i].s <<  " D\n1 " << -1*arr[i].f << " R\n3\n";
			}else if(arr[i].f > 0 && arr[i].s < 0){
				printf("1 %lld R\n1 %lld D\n2\n1 %lld U\n1 %lld L\n3\n", arr[i].f, -1*arr[i].s, -1*arr[i].s, arr[i].f);
				//cout << "1 " << arr[i].f <<  " R\n1 " << -1*arr[i].s << " D\n2\n"<< "1 " << -1*arr[i].s  << " U\n1 " << arr[i].f << " L\n3\n";
			}else{
				printf("1 %lld L\n1 %lld D\n2\n1 %lld U\n1 %lld R\n3\n", -1*arr[i].f, -1*arr[i].s, -1*arr[i].s, -1*arr[i].f);
				//cout << "1 " << -1*arr[i].f << " L\n1 " << -1*arr[i].s << " D\n2\n"<< "1 " << -1*arr[i].s  << " U\n1 " << -1*arr[i].f << " R\n3\n";
			}
		}
	}

	return 0;
}
