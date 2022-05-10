#include <stdio.h>

int main() {

  int t;
  scanf("%d", &t);
  while(t--) {
    int d;
    scanf("%d", &d);
    if(d%10 + d/10%10 + d/100%10 == d/1000%10 + d/10000%10 + d/100000%10) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}