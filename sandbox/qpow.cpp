#include <iostream>

template <typename T>
T qpow(T a, T b) {
  T res = 1;
  while(b) {
    if(b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}


int main() {
  std::cout << qpow(2, 10) << std::endl;
  return 0;
}
