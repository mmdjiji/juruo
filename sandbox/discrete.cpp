#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> a(n), b(n);

  for(int i=0; i<n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  cout << "before: ";
  for(int i=0; i<n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for(int i=0; i<n; ++i)
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

  cout << "after: ";
  for(int i=0; i<n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}

/*
10
1 888 8 -2 6 888 4 6 0 46
*/