#include <stdio.h>

int main() {
  int x;
  scanf("%d",&x);
  
  while(x != 0) {
    int now = x%10;
    x = (x-now) / 10;
    
    int i;
    for(i=0;i<now;i++) printf("*");
    printf("\n");
  }
}
