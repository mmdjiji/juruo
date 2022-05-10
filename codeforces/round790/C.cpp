#include <stdio.h>
#include <math.h>

int diff(char *s1, char *s2, int len) {
  int ans = 0;
  for(int i=0; i<len; ++i) {
    ans += abs(s1[i] - s2[i]);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    char str[55][10];
    int ans = 0x3f3f3f3f;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i) {
      scanf("%s", str[i]);
    }
    for(int i=0; i<n; ++i) {
      for(int j=i+1; j<n; ++j) {
        int res = diff(str[i], str[j], m);
        if(res < ans) ans = res;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}