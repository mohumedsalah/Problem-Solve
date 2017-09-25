/*
 * C. Pocket Book.cpp
 *
 *  Created on: Jun 22, 2017
 *      Author: salah
 */
#include <bits/stdc++.h>
using namespace std;
int arr[110];
char s[110][110];
set<char> st;
int main(){

	int n, m;
	scanf("%d %d",&n,&m);
	long long ret = 1;
	long long mod = pow(10,9)+7;
	for(int i = 0; i < n;i++)
		scanf("%s",s[i]);
	for(int j = 0 ; j < m;j++){
		st.clear();
		for(int i = 0; i < n ;i++){
			st.insert(s[i][j]);
		}
		int r = st.size();
		ret *= r;
		ret = ret % mod;
	}
	cout << ret << endl;
	return 0;
}
