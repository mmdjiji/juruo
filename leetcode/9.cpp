typedef long long ll;

class Solution {
public:
  template<typename T>
  T length(T x) {
    if(x == 0) {
      return 0;
    }
    if(x < 0) {
      x = -x;
    }
    return log10(x) + 1;
  }
  template<typename T>
  T qpow(T a, T n) {
    T ans = 1;
    while(n) {
      if(n & 1) {
        ans = ans * a;
      }
      a = a * a;
      n >>= 1;
    }
    return ans;
  }
  bool isPalindrome(int x) {
    if(x < 0) return false; // 负数均不满足回文数定义
    ll len = length(x); // 数学方法计算长度
    if(len > 0 && x%10 == 0) return false; // 优化末尾为0的情况
    for(ll i=0; i<len; ++i) {
      if(x/qpow((ll)10, i)%10 != x/qpow((ll)10, len-i-1)%10) {
        return false;
      }
    }
    return true;
  }
};