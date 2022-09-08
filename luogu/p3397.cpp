// reference: https://www.luogu.com.cn/blog/blue/solution-p3397

#include <stdio.h>

int map[1005][1005];

int main() {

  int n, m;
  int x1, y1, x2, y2;
  scanf("%d %d", &n, &m);

  while(m--) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for(int i=x1; i<=x2; ++i) {
      ++map[i][y1];
      --map[i][y2+1];
    }
  }

  // for(int i=1; i<=n; ++i) {
  //   for(int j=1; j<=n; ++j) {
  //     printf("%d ", map[i][j]);
  //   }
  //   printf("\n");
  // }

  int v = 0;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      v += map[i][j];
      printf("%d ", v);
    }
    v += map[i][n+1];
    printf("\n");
  }

  return 0;
}
