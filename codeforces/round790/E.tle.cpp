#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main() {

  int t;
  scanf("%d", &t);
  while(t--) {
    int n, q;
    int in, rawin;
    int ok = 0, buok = 0x3f3f3f3f;
    priority_queue<int> boxes, last;

    scanf("%d %d", &n, &q);
    for(int i=0; i<n; ++i) {
      scanf("%d", &in);
      boxes.push(in);
    }

    for(int i=0; i<q; ++i) {
      int ans = 0;
      bool flag = false;
      scanf("%d", &rawin);
      if(rawin >= buok) {
        printf("-1\n");
      } else {
        in = rawin;
        last = boxes;
        while(!last.empty()) {
          ++ans;
          in -= last.top();
          if(in <= 0) { // enough
            flag = true;
            if(ok < in) ok = in;
            printf("%d\n", ans);
            break;
          }
          last.pop();
        }
        if(!flag) {
          if(buok > rawin) buok = rawin;
          printf("-1\n");
        }
      }
    }
  }
  return 0;
}