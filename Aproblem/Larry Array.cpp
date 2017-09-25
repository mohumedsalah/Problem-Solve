#include <bits/stdc++.h>

using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        int arr[1000];
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int inv = 0;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                if (arr[i] > arr[j]){
                	swap(arr[i], arr[j]);
                    inv ++;
                }

       printf("Optimal train swapping takes %d swaps.\n", inv);
    }
    return 0;
}
