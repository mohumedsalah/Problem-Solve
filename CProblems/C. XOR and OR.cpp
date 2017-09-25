#include <bits/stdc++.h>
using namespace std;
int const mx = 1e6 + 9;
char a[mx];
char b[mx];
int main() {
	scanf("%s", &a);
	scanf("%s", &b);
	int n = strlen(a);
	int m = strlen(b);
	if (n != m) {
		puts("NO");
		return 0;

	}
	int f = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && a[i] == '0')
			continue;
		f = 0;
		break;
	}
	if(f){
		puts("YES");
		return 0;
	}
	int f0 = 0;
	int f1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') {
			f0 = 1;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == '1') {
			f1 = 1;
			break;
		}
	}
	if (f0 && f1)
		puts("YES");
	else
		puts("NO");
	return 0;
}
