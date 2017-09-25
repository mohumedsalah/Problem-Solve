#include <bits/stdc++.h>

using namespace std;
int main() {

	string s;
	string a = "heavy", b = "metal";
	cin >> s;
	long long xx = 0, ret = 0;
	int n = s.size();
	for(int i = 0;i < n;i++){
		if(s.substr(i,5) == a){
			xx++;
		}
		if(s.substr(i,5) == b){
			ret+= xx;
		}
	}

	cout << ret << endl;
	return 0;
}
