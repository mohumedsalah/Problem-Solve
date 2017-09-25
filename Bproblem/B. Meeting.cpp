#include <bits/stdc++.h>
using namespace std;
typedef pair<int , int> ii;
int n;
pair< pair<int , int >, double> arr[1010];
double dis(int x1, int x2, int y1, int y2){
	return ((x1-x2)*(x1-x2))+ ((y1-y2)*(y1-y2));
}
bool che(int x, int y){
	for(int i = 0; i < n; i++){
		double dist = dis(x,arr[i].first.first,y,arr[i].first.second);
		if(dist <= arr[i].second * arr[i].second)
			return true;
	}
	return false;
}
int main() {
	int xa , ya , xb, yb, xx, yy;
	double zz;
	cin >> xa >> ya >> xb >> yb;
	int x1 = min(xa, xb);
	int x2 = max(xa, xb);
	int y1 = min(ya, yb);
	int y2 = max(ya, yb);
	int ret = 0;
	cin >> n;
	for(int i = 0 ;i < n;i++){
		cin >> xx >> yy >>zz;
		ii b = ii(xx,yy);
		arr[i].first = b;
		arr[i].second = zz;
	}
	for(int i = x1 ; i <= x2;i++){
		if(!che(i,y2))
			ret++;
		if(!che(i,y1))
			ret++;
	}
	for(int i = y1 + 1 ;i< y2;i++){
		if(!che(x1,i))
			ret++;
		if(!che(x2,i))
			ret++;
	}
	cout << ret << endl;
	return 0;
}
