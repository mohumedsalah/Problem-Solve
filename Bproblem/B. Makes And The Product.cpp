#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, int> li;
#define f first
#define s second
li arr[100006];
long long v[100006];
int n;
bool cmp(li a, li b) {
	if (a.f == b.f)
		return a.s < a.s;
	return a.f < b.f;
}
bool cmpp(li a, li b) {
	return a.s < a.s;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		arr[i].f = v[i];
		arr[i].s = i;
	}
	sort(arr, arr + n, cmp);
	sort(arr, arr + 3, cmpp);
	int ret = 1;
	for (int i = 0; i < arr[0].s; i++) {
		if(v[i] == arr[0].f)
			ret++;
	}
	for (int i = arr[0].s  ; i < arr[1].s; i++) {
		if(v[i] == arr[1].f)
			ret++;
		if(v[i] == arr[0].f)
			ret++;
	}
	for (int i = arr[1].s; i < arr[2].s; i++) {
		if(v[i] == arr[2].s)
			ret++;
	}
	for (int i = arr[2]; i < n; i++) {

	}

	long long ret = 1;

	cout << ret << endl;

	return 0;
}
