#include <stdio.h>

int map[10005][10005];

int main() {
  int n;
  int x, y;
  int a, b, g, k;
  scanf("%d", &n);
  for(int i=1; i<=n; ++i) {
    scanf("%d %d %d %d", &a, &b, &g, &k);
    for(int p=0; p<g; ++p) {
      for(int q=0; q<k; ++q) {
        map[a+p][b+q] = i;
      }
    }
  }
  scanf("%d %d", &x, &y);

  if(map[x][y] == 0) {
    printf("-1\n");
  } else {
    printf("%d\n", map[x][y]);
  }

  return 0;
}