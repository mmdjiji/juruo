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

int abs(int x) { return x>0?x:-x; }

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

  int a[2005];

  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i=0; i<2*n; ++i) {
      scanf("%d", &a[i]);
    }
    qsort(a, 0, 2*n-1);
    int lastx, lasty;
    lastx = a[0];
    lasty = a[n];
    int ans = 0;
    for(int i=0; i<n; ++i) {
      ans += abs(a[i] - lastx) + abs(a[n+i] - lasty);
      lastx = a[i];
      lasty = a[n+i];
    }
    printf("%d\n", ans);
    for(int i=0; i<n; ++i) {
      printf("%d %d\n", a[i], a[n+i]);
    }
  }

  return 0;
}