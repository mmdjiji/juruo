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
    int ok[200000] = {0};
    priority_queue<int> boxes;

    scanf("%d %d", &n, &q);
    for(int i=0; i<n; ++i) {
      scanf("%d", &in);
      boxes.push(in);
    }

    int ans = 0;
    while(!boxes.empty()) {
      ++ans;
      ok[ans] += boxes.top() + ok[ans-1];
      boxes.pop();
    }

    for(int i=0; i<q; ++i) {
      
      scanf("%d", &in);
      
      int left = 0, right = n;
      int tmp;
      bool flag = false;
      while(left < right) {
        tmp = (left + right) / 2;
        if(in < ok[tmp]) {
          right = tmp - 1;
        } else if(in > ok[tmp]) {
          left = tmp + 1;
        } else {
          printf("%d\n", tmp);
          flag = true;
          break;
        }
      }
      if(!flag) {
        if(in > ok[n]) {
          printf("-1\n");
        } else {
          int starter = right + 2;
          for(int j=starter; j>=0; --j) {
            if(ok[j] >= in && ok[j-1] < in) {
              printf("%d\n", j);
              break;
            }
          }
        }
      }
    }
  }
  return 0;
}