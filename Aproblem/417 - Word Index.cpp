#include <bits/stdc++.h>
using namespace std;
char arr[7];
int rr = 0;
map<string, int> mp;
map<string, int> :: iterator it;
void bfs() {
	queue<string> q;
	for(char i = 'a'; i <= 'z';i++)
		q.push(string(1,i));
	while(!q.empty()){
		string cur = q.front();
		q.pop();
		mp[cur] = ++rr;
		char ll = cur[cur.size()-1];
		if(cur.size() == 5)
			continue;
		for(char i = ll + 1;i <= 'z';i++){
			q.push(cur+i);
		}
	}

}
int main() {
	bfs();
	string a;
	while(cin >> a){
		it = mp.find(a);
		if(it == mp.end())
			puts("0");
		else
			printf("%d\n", it->second);
	}
	return 0;
}
