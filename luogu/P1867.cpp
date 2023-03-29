#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n); // [1, 20]
  double blood = 10.0;
  int allexp = 0;
  for(int i=0; i<n; ++i) {
    double cost;
    int exp;
    scanf("%lf %d", &cost, &exp);
    blood -= cost;
    if(blood <= 0) break;
    allexp += exp;
    if(blood > 10) blood = 10.0;
  }
  int m = 1;
  int level = 0;
  while(allexp >= m) {
    ++level;
    allexp -= m;
    m *= 2;
  }

  printf("%d %d", level, allexp);
  return 0;
}
