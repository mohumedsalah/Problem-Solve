#include <bits/stdc++.h>
using namespace std;
int arr[1000006];
char s[1000006];
int main() {
	scanf("%s",s);
	int n =strlen(s);
	int r = 0, l = n - 1;
	for (int i = 0; i < n; i++)
		if (s[i] == 'l')
			arr[r++] = i + 1;
		else
			arr[l--] = i + 1;
	for (int i = n - 1; i >= 0; i--)
		printf("%d\n", arr[i]);
	return 0;
}
