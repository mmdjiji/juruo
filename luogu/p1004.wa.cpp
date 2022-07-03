#include <stdio.h>

inline int max(int a, int b) { return a > b ? a : b; }

int main() {

  // 这是一个采用二维dp的方法
  // 但是不能解决两条不同路的问题

  int n;
  int map[15][15] = {0};
  int dp[15][15] = {0};

  int x, y, v;

  scanf("%d", &n);

  while (true) {
    scanf("%d %d %d", &x, &y, &v);
    if (x == 0 && y == 0 && v == 0) break;
    map[x][y] = v;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = map[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        printf("%d ", dp[i][j]);
      }
      printf("\n");
    }
    printf("\n\n");
  }

  printf("%d", dp[n][n]);
  return 0;
}