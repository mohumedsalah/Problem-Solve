#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> f;
vector<ll> s;
int main() {
	int n;
	ll xx;
	ll a = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> xx;
		if (xx >= 0) {
			a += xx;
			f.push_back(xx);
		} else {
			b += (-1 * xx);
			s.push_back((-1 * xx));
		}
	}
	if (a > b)
		cout << "first" << endl;
	else if (b > a)
		cout << "second" << endl;
	else {
		for (int i = 0; i < f.size(); i++) {
			if (f[i] > s[i]) {
				cout << "first" << endl;
				return 0;
			}
			if (s[i] > f[i]) {
				cout << "second" << endl;
				return 0;
			}
		}
		if(xx >= 0){
			cout << "first" << endl;
		}else{
			cout << "second" << endl;
		}
	}
	return 0;
}
