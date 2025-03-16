#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int mp[50005];
int ans = -1;
int T;

typedef struct {
  int l, r;
  int i;
} query;

bool cmp(query a, query b) {
  if(a.l/T != b.l/T) return a.l/T < b.l/T;
  return a.r < b.r;
}


void add(int x) {
  ans -= mp[x]*mp[x];
  mp[x]++;
  ans += mp[x]*mp[x];
}

void del(int x) {
  ans -= mp[x]*mp[x];
  mp[x]--;
  ans += mp[x]*mp[x];
}

int main() {
  int n,m,k;
  int arr[50005];
  query q[50005];
  int answer[50005];
  scanf("%d %d %d", &n, &m, &k);
  T = sqrt(n);
  for(int i=1; i<=n; ++i) {
    scanf("%d", &arr[i]);
  }
  for(int i=0; i<m; ++i) {
    q[i].i = i;
    scanf("%d %d", &q[i].l, &q[i].r);
  }

  sort(q, q+m, cmp);

  int l = 0, r = 0;
  for(int i=0; i<m; ++i) {
    // printf("[%d] %d %d\n", q[i].i, q[i].l, q[i].r);
    
    while(r < q[i].r) add(arr[++r]);
    while(r > q[i].r) del(arr[r--]);
    
    answer[q[i].i] = ans;
  }

  for(int i=0; i<m; ++i) {
    printf("%d\n", answer[i]);
  }
  

  return 0;
}

/*

6 4 3
1 3 2 1 1 3
1 4
2 6
3 5
5 6


6 4 3
1 3 2 1 1 3
5 6
3 5
2 6
1 4

*/