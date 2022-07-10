#include <stdio.h>
#include <string.h>

int sum(bool *a) {
  int ans = 0;
  for(int i=0; i<26; ++i) {
    ans += a[i] ? 1 : 0;
  }
  return ans;
}

int main() {
  int t;
  char str[200005];
  scanf("%d", &t);

  while(t--) {
    int ans = 0;
    scanf("%s", str);
    bool wd[26] = {0};
    int len = strlen(str);
    for(int i=0; i<len; ++i) {
      if(sum(wd) < 3 || wd[str[i] - 'a']) {
        wd[str[i]-'a'] = true;
      } else {
        ++ans;
        for(int i=0; i<26; ++i) {
          wd[i] = false;
        }
        wd[str[i]-'a'] = true;
      }
    }
    if(sum(wd) != 0) ++ans;
    printf("%d\n", ans);
  }

  return 0;
}