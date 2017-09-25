#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> ii;
map<ii, bool> mp;
map<pair<ii, ii>, bool> mp1;
map<ii, bool>::iterator it;
map<pair<ii, ii>, bool>::iterator it1;
map<pair<ii, ii>, bool>::iterator it2;
ii arr[4];
int xx, yy, xx1, yy1;
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &xx, &yy, &xx1, &yy1);

		if ((xx - xx1 != 0 && yy - yy1 != 0 )||( hypot(xx-xx1,yy-yy1) == 0)) {
			puts("NO");
			return 0;
		}
		it1 = mp1.find(make_pair(ii(xx, yy), ii(xx1, yy1)));
		it2 = mp1.find(make_pair(ii(xx1, yy1), ii(xx, yy)));
		if (it1 != mp1.end() || it2 != mp1.end()) {
			puts("NO");
			return 0;
		}
		mp1[make_pair(ii(xx, yy), ii(xx1, yy1))] = 1;
		mp1[make_pair(ii(xx1, yy1), ii(xx, yy))] = 1;
		it = mp.find(ii(xx, yy));
		if (it == mp.end())
			mp[ii(xx, yy)] = 1;
		it = mp.find(ii(xx1, yy1));
		if (it == mp.end())
			mp[ii(xx1, yy1)] = 1;
	}

	//cout << mp.size() << endl;
	if (mp.size() == 4) {
		int i = 0;
		for (it = mp.begin(); it != mp.end(); it++, i++)
			arr[i] = it->f;
		sort(arr, arr + 4);
		if (arr[0].s == arr[2].s && arr[1].s == arr[3].s && arr[0].f == arr[1].f
				&& arr[2].f == arr[3].f)

			puts("YES");
		else
			puts("NO");
		return 0;
	}
	puts("NO");

	return 0;
}
