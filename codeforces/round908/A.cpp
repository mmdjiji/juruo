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

// 合数分解
int factor(int x) {
  int ans = 0;
  for(int i=2; i<=sqrt(x); ++i) {
    if(x % i == 0) {
      ++ans;
      while(x % i == 0) {
        x /= i;
      }
    }
  }
  if(x != 1) {
    ++ans;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  int n;
  char str[100];
  while(t--) {
    scanf("%d", &n);
    scanf(" %s", str);
    printf("%c\n", str[n-1]);
  }

  return 0;
}