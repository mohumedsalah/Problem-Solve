#include <bits/stdc++.h>

using namespace std;
int arr[105][105];
bool r[105];
bool c[105];
int main() {
	int n, m;
	cin >> n >> m;
	//swap(n , m);
	int i, j;
	int nr = 0, nc = 0;
	for (i = 0; i < n; ++i) {
		bool ret = 1;
		for (j = 0; j < m; ++j) {
			cin >> arr[i][j];
			ret = ret && arr[i][j];
		}
		if (ret) {
			nr++;
			r[i] = 1;
		}
	}
	for (j = 0; j < m; ++j) {
		bool ret = 1;
		for (i = 0; i < n; ++i) {
			ret = ret && arr[i][j];
		}
		if (ret) {
			nc++;
			c[j] = 1;
		}
	}

	int f  = 1;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j){
			if(arr[i][j] == 0)continue;
			if(arr[i][j] == 1 &&( r[i] || c[j]))
				continue;
			f = 0;
			break;
		}
		if(f == 0)
			break;
	}

	if(f == 0 || (nc == 0 && nr != 0) || (nr == 0 && nc != 0)){
		cout <<  "NO" << endl;
	}else{
		cout <<  "YES" << endl;
		for(i = 0 ; i < n ;i++){
			for(j = 0; j < m;j++){
				if(r[i] && c[j])
					cout << "1 ";
				else
					cout << "0 ";
			}
			cout << endl;
		}
	}
	return 0;
}

