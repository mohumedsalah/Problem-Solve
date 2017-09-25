#include <bits/stdc++.h>
using namespace std;
int const mx = 1e5 * 3 + 10;
char arr[mx];
int main() {
	int xx;
	char cc;
	int n ;
	int q;
	scanf("%d %d",&n,&q);
	scanf("%s", arr);
	//cout << arr << endl;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == '.') {
			i++;
			while (i < n && arr[i] == '.') {
				cnt++;
				i++;
			}
		}
	}

	while (q--) {
		scanf("%d %c", &xx, &cc);
		//printf("%d %c",xx,cc);
		if (cc == '.' && arr[xx - 1] != '.') {
			arr[xx - 1] = cc;
			if (xx - 2 >= 0 && arr[xx - 2] == '.')
				cnt++;
			if (xx < n && arr[xx] == '.')
				cnt++;
		} else if (cc != '.' && arr[xx - 1] == '.') {
			arr[xx - 1] = cc;
			if (xx - 2 >= 0 && arr[xx - 2] == '.')
				cnt--;
			if (xx < n && arr[xx] == '.')
				cnt--;
		}
		printf("%d\n",cnt);
	}

	return 0;
}
