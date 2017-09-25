#include <bits/stdc++.h>

using namespace std;
int arr[26];
int main(){

	int t;
	cin >> t;
	while(t--){
		int n , k;
		cin >> n >> k;
		for(int i = 0; i < 26;i++){
			cin >> arr[i];
		}
		for(int i =0 ; i <n;i++){
			string s;
			cin >> s;
			int sum = 0;
			for(int i = 0; i < s.size();i++){
				sum += arr[s[i]-97];
			}
			if(sum >= k){
				cout << s << endl;
			}
		}
	}




	return 0;
}
