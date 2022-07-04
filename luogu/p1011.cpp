#include <stdio.h>

int fib(int n) {
  if(n == 0) return 0;
  int a = 1, b = 1, c = 1;
  for(int i=0; i<n-2; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int sumfib(int n) {
  int ans = 0;
  for(int i=1; i<=n; ++i) {
    ans += fib(i);
  }
  return ans;
}

int main() {
  int a, n, m, x;

  scanf("%d %d %d %d", &a, &n, &m, &x);

  if(x == 1 || x == 2) {
    printf("%d\n", a);
  } else if (x == 3) {
    printf("%d\n", 2*a);
  } else {
    int na = sumfib(n-5)+2; // a的系数
    int np = sumfib(n-4);   // p的系数

    int p = (m - na * a) / np;

    na = sumfib(x-4)+2;
    np = sumfib(x-3);
    int ans = na * a + np * p;
    printf("%d\n", ans);
  }

  return 0;
}