#include <stdio.h>

inline int max(int a, int b) { return a>b?a:b; }

int main() {

  int t, x;

  scanf("%d", &t);


  int maximum = -0x3f3f3f3f, cache = 0;
  while(t--) {
    scanf("%d", &x);

    // cache是每次的一个临时序列和
    // 我们每次计算cache的时候
    // 只有两种情况
    // 1. 继承cache，即cache+x
    // 2. 抛弃cache，即x
    // 当且仅当cache<0的时候抛弃cache

    cache = max(cache + x, x);     // 使用cache作为前缀和优化空间到O(1)
    maximum = max(cache, maximum); // 每次都去判断一下当前不抛弃cache的情况下最优解

  }

  printf("%d\n", maximum);

  return 0;
}