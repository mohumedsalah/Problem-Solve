#include <bits/stdc++.h>

using namespace std;
struct node{
	char ch;
	int rep;
};
bool cmp(node a, node b){
	if(a.rep == b.rep)return a.ch < b.ch;
	return a.rep < b.rep;
}
map<char, int > mp;
node arr[26];
int main() {

	//cout <<  (int)'a' << endl;
	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		for(int i = 0; i < a.size();i++){
			map<char,int>::iterator it1 =mp.find(a[i]);
			if(it1 != mp.end()){
				mp[a[i]]++;
			}else{
				mp[a[i]] = 1;
			}
		}
		int cnt = 0;
		for (map<char,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
		    arr[cnt].ch =  it->first ,arr[cnt].rep = it->second ,cnt++;
		sort(arr, arr+cnt,cmp);
		//cout << cnt << endl;
		if(cnt % 2 == 0){
			cout << arr[cnt/2 - 1].ch << arr[cnt/2].ch << endl;
		}else{
			cout << arr[cnt/2].ch << endl;
		}
		mp.clear();
	}
	return 0;
}
