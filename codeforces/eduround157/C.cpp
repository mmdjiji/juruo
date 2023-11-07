#include <bits/stdc++.h>

using namespace std;

// Constant
#define INF (0x3f3f3f3f)

// Quick operation
#define debug(x) std::cout << #x << ": " << x << std::endl;
#define mod(x) ((x)%MOD)

#define int long long
// Type
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 2e5+10;

string a[N];
int cnt[N];
map<pair<int, int>, int> mp;

signed main() {
  int n;
  cin >> n;
  
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    for(auto x : a[i]) cnt[i] += x - '0';
    ++mp[{ a[i].size(), cnt[i] }];
  }
  
  int ans = 0;
  
  // for(int i = 0; i < n; ++i) {
  //   ans += mp[{ a[i].size(), cnt[i] }];
  // }
  
  for(int i = 0; i < n; ++i) {
    int lsum = 0;
    for(int j=0; j<a[i].size(); ++j) {
      lsum += a[i][j] - '0';
      int rsum = cnt[i] - lsum;
      if(lsum >= rsum && (j+1)-(a[i].size()-(j+1))>0)
        ans += mp[{ (j+1)-(a[i].size()-(j+1)), lsum-rsum }];
    }
  }

  for(int i = 0; i < n; ++i) {
    reverse(a[i].begin(), a[i].end());
  }

  for(int i = 0; i < n; ++i) {
    int lsum = 0;
    for(int j=0; j<a[i].size()-1; ++j) {
      // 注意这里是 a[i].size()-1 而不是 a[i].size()
      // 例如 12345.size() = 5
      // 1,2,3,4,5 但是这个时候不考虑最后一个5
      // 因为之前考虑过一次直接连接
      lsum += a[i][j] - '0';
      int rsum = cnt[i] - lsum;
      if(lsum >= rsum && (j+1)-(a[i].size()-(j+1))>0)
        ans += mp[{ (j+1)-(a[i].size()-(j+1)), lsum-rsum }];
    }
  }
  cout << ans << endl;
  return 0;
}