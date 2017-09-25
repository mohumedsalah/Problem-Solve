#include <bits/stdc++.h>

using namespace std;
char arr[200005];
int main(){
	//memset(p,-1, sizeof p);
	scanf("%s",arr);
	bool f = 0;
	int rep = 1;
	char b = arr[0];
	printf("%c",arr[0]);
	int n = strlen(arr);
	for(int i = 1;i < n;i++){
		if(b != arr[i]){
			printf("%c",arr[i]);
			b = arr[i];
			if(rep != 2)
				f = 0;
			rep = 1;
		}else{
			rep++;
			if(rep == 2 && f){
				rep = 1;
			}
			else if(rep == 2){
				f =1;
				printf("%c",arr[i]);
			}
			else if(rep == 3){
				rep = 2;
				f = 1;
			}
		}
	}
	return 0;
}
