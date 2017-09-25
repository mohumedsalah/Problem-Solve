//============================================================================
// Name        : projector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> dd;
struct rec {
	double x1;
	double x2;
	double y1;
	double y2;
};
rec xxyy(double x1, double y1, double x2, double y2) {
	rec n;
	n.x1 = x1, n.x2 = x2, n.y1 = y1, n.y2 = y2;
	return n;
}
vector<rec> nn;
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double xx, yy, x, y;
	while (getchar() == 'r') {
		scanf("%lf%lf%lf%lf", &xx, &yy, &x, &y);
		nn.push_back(xxyy(xx, yy, x, y));
		getchar();
	}
	getchar();
	int cnt = 0;
	string s;
	while (scanf("%lf%lf", &xx, &yy)) {
		if(xx == 9999.9 && yy == 9999.9)
			return 0;
		cnt++;
		int f = 1;
		for (int j = 0; j < (int)nn.size(); j++) {
			if (xx> nn[j].x1 && xx < nn[j].x2
					&& yy > nn[j].y2 && yy < nn[j].y1) {
				f = 0;
				printf("Point %d is contained in figure %d\n", cnt , j + 1);
			}
		}
		if(f){
			printf("Point %d is not contained in any figure\n",cnt);
		}
	}
	return 0;
}
