// C Header
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// #include <time.h>

// C++ Header
// #include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
// #include <string>
// #include <map>
// #include <stack>
// #include <queue>

using namespace std;

// !!! DO NOT USE THIS WHEN printf WITH cout !!!
// std::ios::sync_with_stdio(0);

// Constant
#define INF (0x3f3f3f3f)

// Quick operation
#define debug(x) std::cout << #x << ": " << x << std::endl;
#define mod(x) ((x)%MOD)

// Type
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// FastIO
inline int readint() {
  int ret = 0, sgn = 1;
  char ch = getchar();
  while(ch < '0' || ch > '9'){
    if(ch == '-') sgn = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9'){
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * sgn;
}

// qpow
// @Overload *
// @Overload /
template <typename T>
T qpow(T a, ll n) {
  T ans = 1;
  if(n < 0) {
    a = 1.0 / a;
    n = -n;
  }
  while (n) {
    if (n & 1)
      ans = ans * a;
    n >>= 1;
    a = a * a;
  }
  return ans;
}

int gcd(int a, int b) { return (b==0)?a:gcd(b,a%b); }

// qsort(a, 0, n-1);
void qsort(int *s, int l, int r) {
  if(l < r) {
    int i = l, j = r, x = s[l];
    while(i < j){
      while(i < j && s[j] >= x) j--;
      if(i < j) s[i++] = s[j];
      while(i < j && s[i] < x) i++;
      if(i < j) s[j--] = s[i];
    }
    s[i] = x;
    qsort(s, l, i-1);
    qsort(s, i+1, r);
  }
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);
    if(x<y) {
      if(x+k <= y) {
        printf("%d\n", 2*y - (x+k));
      } else {
        printf("%d\n", y);
      }
    }else {
      printf("%d\n", x);
    }
  }

  return 0;
}