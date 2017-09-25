#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define h second
int arr[110];



//salllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllo7
int main() {
	int n, k,xx, nz = 0;
	cin >> n >> k;
	for(int i = 0 ; i <n;i++){
		cin >> xx ;
		if(xx == 0)
			nz++;
		arr[i] = xx;
	}
	if(nz > k){
		cout << "No" << endl;
		return 0;
	}
	if(k == 1){
		cin >> xx;
		int f = 0;
		for(int i = 0 ; i < n;i++){
			if(arr[i] == 0){
				arr[i] = xx;
			}
		}
		for(int i = 1 ; i < n;i++){
			if(arr[i - 1] < arr[i])
				continue;
			f = 1;
			break;
		}
		if(f)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}
