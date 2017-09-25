#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,i, j, h, v;
	cin>>n;
	set<int> a, b;

    for(i =1; i <= n*n; i++){
        cin>>h>>v;

        if(a.count(h) == 0 && b.count(v) == 0){
            a.insert(h);
            b.insert(v);
            cout<<i<<" ";
        }
    }

    return 0;
}
