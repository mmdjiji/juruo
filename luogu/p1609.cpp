// luogu p1609
// https://www.luogu.com.cn/problem/P1609
// JiJi <i@mmdjiji.com>

#include <stdio.h>
#include <string.h>

int main() {
  char num[10005] = {0}, ans[10005] = {0};
  scanf("%s", num);
  int len = strlen(num);

  // generate
  for(int i = 0; i <= (len-1) / 2; ++i) {
    ans[i] = ans[len-i-1] = num[i];
  }

  // judge if ans > num
  bool judge = true;
  for(int i=0; i < len; ++i) {
    if(ans[i] > num[i]) {
      break;
    } else if(ans[i] < num[i] || i == len - 1) {
      judge = false;
      break;
    }
  }
  if(judge) {
    printf("%s\n", ans);
  } else {
    bool success = false;
    for(int i=(len-1)/2; i>=0; --i) {
      if(ans[i] < '9') {
        ++ans[i];
        success = true;
        for(int j=i+1; j<=(len-1)/2; ++j) {
          ans[j] = '0';
        }
        break;
      }
    }
    if(success) { // common situation
      for(int i = 0; i <= (len-1) / 2; ++i) {
        ans[len-i-1] = ans[i];
      }
      printf("%s\n", ans);
    } else { // special judge for 999...99 -> 100...001
      printf("1");
      for(int i=0; i<len-1; ++i) {
        printf("0");
      }
      printf("1\n");
    }
  }

  return 0;
}