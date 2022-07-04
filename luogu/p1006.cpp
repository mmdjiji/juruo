#include <stdio.h>

inline int max(int a, int b) { return a > b ? a : b; }

inline int max(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }

int main() {

  int m, n;
  int a[51][51] = {0};
  int dp[51][51][51][51] = {0};
  scanf("%d %d", &m, &n);

  for(int i=1; i<=m; ++i) {
    for(int j=1; j<=n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  
  for(int i=1; i<=m; ++i) {
    for(int j=1; j<=n; ++j) {
      for(int k=1; k<=m; ++k) {
        for(int l=1; l<=n; ++l) {
          dp[i][j][k][l] = max(
            dp[i-1][j][k-1][l],
            dp[i-1][j][k][l-1],
            dp[i][j-1][k-1][l],
            dp[i][j-1][k][l-1]
          ) + a[i][j] + a[k][l];
          if(i == k && j == l) {
            dp[i][j][k][l] -= a[i][j];
          }
        }
      }
    }
  }

  printf("%d\n", dp[m][n][m][n]);

  return 0;
}