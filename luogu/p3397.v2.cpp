// reference: https://www.luogu.com.cn/blog/QAQAutoMaton/solution-p3397
// 二维差分很显然是一种用空间换时间的做法

// b[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1]

#include <stdio.h>

int a[1005][1005], b[1005][1005];

int main() {

  int n, m;
  int x1, y1, x2, y2;
  scanf("%d %d", &n, &m);

  while(m--) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    ++b[x1][y1];
    --b[x2+1][y1];
    --b[x1][y2+1];
    ++b[x2+1][y2+1];
  }

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      a[i][j] = b[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
