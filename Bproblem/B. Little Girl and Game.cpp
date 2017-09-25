#include <bits/stdc++.h>

using namespace std;
int arr[26];
char str[1010];
int main() {
	scanf("%s", str);
	for (int i = 0; i < (int) strlen(str); i++)
		arr[str[i] - 97]++;
	int ret = 0;
	for (int i = 0; i < 26; i++)
		if (arr[i] % 2 != 0)
			ret++;
	ret--;
	if ( ret  < 1 || ret % 2 == 0) {
		puts("First");
	} else {
		puts("Second");
	}
	return 0;
}
