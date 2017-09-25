#include <bits/stdc++.h>
using namespace std;
bool np[20000010];
vector<pair<int,int> > vv;
void sevie() {
	np[0] = 1, np[1] = 1;
	for (int i = 2; i <= 20000000; i++) {
		if (np[i] == 0) {
			for (int j = i + i; j <= 20000000; j += i) {
				np[j] = 1;
			}
		}
	}
	int b = 2;

	for (int i = 3; i <= 20000000; i++) {
		if (!np[i]) {
			if(abs(i-b) == 2)
				vv.push_back(make_pair(b,i));
			b = i;
		}
	}
}

int main() {
	int n;
	sevie();
	while(cin >> n){
		printf("(%d, %d)\n" ,vv[n-1].first ,vv[n-1].second );
	}
	return 0;
}
