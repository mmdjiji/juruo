#include <stdio.h>

int main() {

  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    int matrix[205][205];
    int p[400] = {0}, q[400] = {0};
    int ans = 0;
    int run;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
        scanf("%d", &matrix[i][j]);
      }
    }

    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
        p[n+j-i-1] += matrix[i][j];
        q[i+j] += matrix[i][j];
      }
    }
    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
        run = p[n+j-i-1] + q[i+j] - matrix[i][j];
        if(run > ans) ans = run;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}