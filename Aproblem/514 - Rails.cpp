#include <bits/stdc++.h>
using namespace std;
int vis[1100];
int arr[1100];
stack<int> s;
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	while (true) {
		int fn = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			if (arr[0] == 0) {
				fn = 1;
				break;
			}
		}
		if(fn){
			scanf("%d", &n);
			printf("\n");
			if(n == 0)
				break;

			fn = 0;
			continue;
		}
		memset(vis, -1, sizeof vis);
		int f1 = 1;
		while(s.size())
			s.pop();
		for(int i = 0; i <n;i++){
			int cur = arr[i];
			if(vis[cur] == -1){
				vis[cur] = 1;
				for(int j = 1; j < cur;j++){
					if(vis[j] != -1)
						continue;
					vis[j] = 1;
					s.push(j);
				}
			}else{
				int curs = s.top();
				if(cur == curs){
					s.pop();
					continue;
				}else{
					f1 = 0;
					break;
				}
			}
		}
		if(f1)
			puts("Yes");
		else
			puts("No");
	}

	return 0;
}
