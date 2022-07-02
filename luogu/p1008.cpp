#include <stdio.h>

bool check(int a, int b, int c) {
  int flag[10] = {0};
  ++flag[a%10];
  ++flag[a/10%10];
  ++flag[a/100%10];
  ++flag[b%10];
  ++flag[b/10%10];
  ++flag[b/100%10];
  ++flag[c%10];
  ++flag[c/10%10];
  ++flag[c/100%10];
  if(flag[0] > 0) return false;
  for (int i = 1; i < 10; ++i) {
    if (flag[i] > 1) return false;
  }
  return true;
}

int main() {

  for(int i=123; i<=333; ++i) {
    if(check(i, 2*i, 3*i)) {
      printf("%d %d %d\n", i, 2*i, 3*i);
    }
  }
  return 0;
}