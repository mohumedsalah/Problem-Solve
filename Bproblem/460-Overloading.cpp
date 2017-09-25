#include <stdio.h>

int min(int a, int b){
 return (a < b)? a : b;
}
int max(int a, int b){
 return (a > b)? a : b;
}
int main(){
 int t,x,y,xx,yy,x1,y1,xx1,yy1,X,Y,XX,YY;
 int line = 0;

 scanf("%d", &t);
 while(t--){
  scanf("%d %d %d %d", &x, &y, &xx, &yy);
  scanf("%d %d %d %d", &x1, &y1, &xx1, &yy1);

  X = max(x, x1);
  Y = max(y, y1);
  XX = min(xx, xx1);
  YY = min(yy, yy1);

  if(line)
   printf("\n");
  line = 1;

  if(X < XX && Y < YY)
   printf("%d %d %d %d\n", X, Y, XX, YY);
  else
   printf("No Overlap\n");
 }

 return 0;
}