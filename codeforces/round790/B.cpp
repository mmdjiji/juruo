#include <stdio.h>

int main() {

  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    int min = 0x3f3f3f3f;
    int box[100];
    int ans = 0;
    scanf("%d", &n);
    
    for(int i=0; i<n; ++i) {
      scanf("%d", &box[i]);
      if(box[i] < min) {
        min = box[i];
      }
    }
    for(int i=0; i<n; ++i) {
      ans += box[i]-min;
    }
    printf("%d\n", ans);

  }
  return 0;
}