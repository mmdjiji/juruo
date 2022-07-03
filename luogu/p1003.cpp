#include <stdio.h>

typedef struct {
  int a, b, g, k;
} node;

node map[10005];

int main() {
  int n;
  int x, y;

  scanf("%d", &n);
  for(int i=1; i<=n; ++i) {
    scanf("%d %d %d %d", &map[i].a, &map[i].b, &map[i].g, &map[i].k);
  }
  scanf("%d %d", &x, &y);

  int ans = -1;
  
  for(int i=n; i>=1; --i) {
    if(x >= map[i].a && x <= map[i].a + map[i].g && y >= map[i].b && y <= map[i].b + map[i].k) {
      ans = i;
      break;
    }
  }

  printf("%d\n", ans);

  return 0;
}