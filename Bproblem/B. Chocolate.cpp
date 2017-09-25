#include <bits/stdc++.h>

using namespace std;

int main(){

	int n ;
	cin >> n;
	long long ret = 1;
	int cnt = -1;
	for(int i = 0 ; i < n;i++){
		int xx;
		cin >> xx;
		if(cnt == -1 && xx == 0)
			continue;
		if(cnt == -1 && xx == 1){
			cnt++;
			continue;
		}
		if(xx == 1){
			ret *= (cnt+1);
			cnt = 0;
		}else{
			cnt++;
		}
	}
	if(cnt == -1)
		cout << 0 << endl;
	else
		cout << ret << endl;



	return 0;
}
