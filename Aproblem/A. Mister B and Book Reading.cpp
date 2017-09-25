#include <bits/stdc++.h>
using namespace std;
int r = 0, rr = 0, c, v, vm, a, l, cnt = 1;

int main() {
	//file();
	scanf("%d%d%d%d%d", &c, &v, &vm, &a, &l);
	rr = r = v;
	while (rr < c) {
		r = v + (a * cnt);
		if (r > vm)
			r = vm;
		cnt++, rr += r - l;
	}
	cout << cnt;
	return 0;
}
//salahhhhhhhhhhhhhhhhhhhhhhhhooooooooooo
//maxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//meeeeeeeee
