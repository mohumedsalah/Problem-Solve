#include <bits/stdc++.h>

using namespace std;

int main() {
	//cout << 4 % 2 << endl;
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1+=1e5,x2+=1e5,y1+=1e5,y2+=1e5;
	int t1 = abs(x2 - x1);
	int t2 = abs(y2 - y1);
	if(t1 == 0 && t2 == 0){
		cout << "YES" << endl;
		return 0;
	}
	int x, y;
	cin >> x >> y;
	if (t1 == 0) {
		if (t2 >= y && t2 % y == 0 && (t2 / y) % 2 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}
	if (t2 == 0) {
		if (t1 >= x && t1 % x == 0 && (t1 / x) % 2 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}
	if (t1 >= x && t2 >= y && t1 % x == 0 && t2 % y == 0) {
		int te = t1 / x;
		int te2 = t2/y;
		if((te % 2 != 0 && te2 % 2 != 0)||((te % 2 == 0 && te2 % 2 == 0)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
