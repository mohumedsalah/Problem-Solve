#include <bits/stdc++.h>

using namespace std;
queue<int> q;
int main(){
	//freopen("in.txt","r", stdin);
	int n, cur;
	while(scanf("%d", &n)&& n){
		ostringstream remain;
		while(q.size())
			q.pop();
		for(int i = 1; i <= n ;i++)
			q.push(i);
		while(q.size() >= 2){
			cur = q.front();
			q.pop();
			if(q.size() == 1)
				remain <<  " "  << cur ;
			else
			remain <<  " "  << cur <<",";
			cur = q.front();
			q.pop();
			q.push(cur);
		}
		string ss = remain.str();
		printf("Discarded cards:%s\n", ss.c_str());
		printf("Remaining card: %d\n",q.front());
	}

	return 0;
}
