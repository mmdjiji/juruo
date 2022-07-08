#include <stdio.h>
#include <map>
using namespace std;

typedef long long ll;

inline int readint() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

map<int, int> a;

int main() {
  int n, m;
  n = readint();
  m = readint();
  int in;
  for(int i=1; i<=n; ++i) {
    in = readint();
    if(!a[in]) {
      a[in] = i;
    }
  }
  for(int i=1; i<=m; ++i) {
    in = readint();
    if(!a[in]) {
      printf("-1 ");
    } else {
      printf("%d ", a[in]);
    }
  }
  return 0;
}