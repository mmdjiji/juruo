#include <stdio.h>
#include <string.h>

inline int min(int a, int b) { return a < b ? a : b; }

char *best(char *x, char *y) {
  char *a = x, *b = y;
  if(strlen(x) > strlen(y)) {
    a = y; b = x;
  }
  int len = strlen(a);
  for(int i=0; i<len; ++i) {
    if(a[i] > b[i]) return a;
    if(a[i] < b[i]) return b;
  }
  if(strlen(a) == strlen(b)) return a;
  if(a[len - 1] < b[len]) {
    return b;
  }
  return a;
}

int main() {

  int n;
  char a[25][15];
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%s", a[i]);
  }
  for(int t=0; t<n; ++t) {
    char *ans = a[0];
    for(int i=1; i<n; ++i) {
      if(strlen(a[i]) > 0) {
        if(strlen(ans) == 0) {
          ans = a[i];
        } else {
          ans = best(ans, a[i]);
        }
      }
    }
    printf("%s", ans);
    ans[0] = 0;
  }
  return 0;
}