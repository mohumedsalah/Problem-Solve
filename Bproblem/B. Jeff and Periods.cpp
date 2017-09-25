#include <bits/stdc++.h>

using namespace std;
vector<int> inx[100005];
int flag[100005];
int dif[100005];
int main() {
	int n, xx,cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> xx;
		inx[xx].push_back(i);
	}
	for (int i = 0; i < 100004; i++) {
		sort(inx[i].begin(),inx[i].end());
		flag[i] = 1;
		int &b = dif[i];
		b = 0;
		int c = inx[i].size() - 1;
		if(c < 0){
			flag[i] = 0;
			continue;
		}
		for (int j = 0; j < c ; j++) {
			if (b == 0) {
				b = inx[i][j+1] - inx[i][j];
			}else{
				if(inx[i][j+1] - inx[i][j] != b){
					flag[i] = 0;
					break;
				}
			}
		}
		if(flag[i] == 1){
			cnt++;
		}
	}
	cout << cnt << endl;
	for(int i = 0; i < 100005 ;i++){
		if(flag[i]){
			cout << i << " " << dif[i] << endl;
		}
	}

	return 0;
}
