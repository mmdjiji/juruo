#include <stdio.h>

inline int max(int a, int b) { return a > b ? a : b; }

int main() {

  // 四维dp
  
  int n;
  int map[15][15] = {0};
  int dp[15][15][15][15] = {0};

  int x, y, v;

  scanf("%d", &n);

  while (true) {
    scanf("%d %d %d", &x, &y, &v);
    if (x == 0 && y == 0 && v == 0) break;
    map[x][y] = v;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for(int k = 1; k <= n; ++k) {
        for(int l = 1; l <= n; ++l) {
          dp[i][j][k][l] = map[i][j] + map[k][l] +
            max(dp[i - 1][j][k - 1][l], 
              max(dp[i - 1][j][k][l - 1], 
                max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])
              )
            );
          if(i == k && j == l) {
            dp[i][j][k][l] -= map[i][j];
          }
        }
      }
    }
  }

  printf("%d", dp[n][n][n][n]);
  return 0;
}