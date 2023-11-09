// C Header
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// #include <time.h>

// C++ Header
#include <bits/stdc++.h>
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

int main() {
  int t;
  scanf("%d", &t);

  int a[200];
  
  while(t--) {
    int n;
    int b[200] = {0};
    int ex[200] = {0};
    int num = 0;

    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
      scanf("%d", &a[i]);
      b[i] = 1;
    }
    for(int i=0; i<n; ++i) {
      for(int j=i+1; j<n; ++j) {
        if(a[i] == a[j]) {
          if(ex[a[i]] > 0) {
            b[j] = ex[a[i]];
          } else {
            ++num;
            if(num == 1) {
              b[j] = 3;
              ex[a[i]] = 3;
            } else {
              b[j] = 2;
              ex[a[i]] = 2;
            }
          }
        }
      }
    }

    int tj = 0;
    for(int i=0; i<200; ++i) {
      if(ex[i] > 0) ++tj;
    }

    if(tj < 2) {
      printf("-1\n");
    } else {
      for(int i=0; i<n; ++i) {
        printf("%d%c", b[i], i==n-1?'\n':' ');
      }
    }
  }

  return 0;
}