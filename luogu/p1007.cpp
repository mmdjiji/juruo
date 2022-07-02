#include <stdio.h>
#include <math.h>

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

int main() {

  int L, n, p;
  int minimum = 0, maximum = 0;

  scanf("%d", &L);
  scanf("%d", &n);

  for(int i=1; i<=n; ++i) {
    scanf("%d", &p);
    // 至于为什么这里两个最前面都是max()
    // 因为表示的是最后一个士兵的行动，也就是最慢的
    // 只有当最慢的士兵离开独木桥才算结束
    minimum = max(minimum, min(p, L+1-p));
    maximum = max(maximum, max(p, L+1-p));
  }

  printf("%d %d\n", minimum, maximum);

  return 0;
}