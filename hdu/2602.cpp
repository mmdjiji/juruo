#include <stdio.h>

int max(int a, int b) {
  return a>b?a:b;
}

int main() {
  int t;

  scanf("%d", &t);
  while(t--) {
    int n, v;
    int w[1005], c[1005];
    int dp[1005] = {0};
    scanf("%d %d", &n, &v);
    for(int i=1; i<=n; ++i) {
      scanf("%d", &w[i]);
    }
    for(int i=1; i<=n; ++i) {
      scanf("%d", &c[i]);
    }

    for(int i=1; i<=n; ++i) {
      for(int j=v; j>=c[i]; --j) {
        dp[j] = max(dp[j], dp[j-c[i]] + w[i]);
      }
    }
    printf("%d\n", dp[v]);
  }

  return 0;
}