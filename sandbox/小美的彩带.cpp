#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef struct {
  char c;
  int n;
  int i;
  int l;
  int r;
} Query;

int T;

int cmp(Query a, Query b) {
  if(a.l/T == b.l/T) return a.l < b.l;
  return a.r < b.r;
}

vector<int> map(200010);//, bmap(200010);
// unordered_map<int,int> map, bmap;

int ans;
int bigans = -1;

void add(int x) {
  if(map[x] == 0) {
    ++ans;
  }
  ++map[x];
}

void del(int x) {
  if(map[x] == 1) {
    --ans;
  }
  --map[x];
}

int main() {
  int n, q;
  cin >> n >> q;
  T = sqrt(2*n)*1.5;
  vector<int> a(n*2+10);
  vector<int> b(n);
  vector<Query> query(q);
  vector<int> answer(q);
  for(int i=0; i<n; ++i) {
    cin >> a[i];
    b[i] = a[i];
    // a[n+i] = a[i];
  }
  for(int i=0; i<q; ++i) {
    cin >> query[i].c >> query[i].n;
    query[i].i = i;
  }
  // 把query转换成求a的偏移量，以便具有交换律
  int j = 0; // 1 1 4 5 1 4
  int k = 0;
  for(int i=0; i<q; ++i) {
    if(query[i].c == 'L') {
      query[i].l = j; // >= 0
      query[i].r = j + query[i].n % n - 1; // < 2n
      j = (j + query[i].n % n) % n;
    } else {
      query[i].r = 2*n - k - 1; // < 2n
      query[i].l = 2*n - (k + query[i].n % n); // > 0
      k = (k + query[i].n % n) % n;
    }
  }

  // 对a离散化
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  bigans = b.size();
  for(int i=0; i<n; ++i) {
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    a[n+i] = a[i];
  }

  sort(query.begin(), query.end(), cmp);

  // for(int i=0; i<q; ++i) {
  //   cout << "[" << query[i].i << "]" << query[i].l << "," << query[i].r << endl;
  // }
  // a已扩充2n确保够用
  // 1 1 4 5 1 4 1 1 4 5 1 4
  int l = 0, r = -1;
  for(int i=0; i<q; ++i) {
    if(query[i].n >= n) {
      // if(bigans == -1) { // 等价于求解[0,n-1]
      //   int tmpans = 0;
      //   for(int i=0; i<n; ++i) {
      //     if(bmap[a[i]] == 0) ++tmpans;
      //     ++bmap[a[i]];
      //   }
      //   bigans = tmpans;
      // }
      answer[query[i].i] = bigans;
    } else {
      while(l > query[i].l) add(a[--l]);
      while(l < query[i].l) del(a[l++]);
      while(r > query[i].r) del(a[r--]);
      while(r < query[i].r) add(a[++r]);
      answer[query[i].i] = ans;
    }
  }

  for(int i=0; i<q; ++i) {
    cout << answer[i] << endl;
  }
  return 0;
}

/*

6 3
1 1 4 5 1 4
L 2
L 3
R 12

6 4
1 1 4 5 1 4
L 3
R 2
L 2
R 5

*/