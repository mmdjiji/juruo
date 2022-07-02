#include <stdio.h>

typedef long long ll;
int n, m, maX, maY;
ll dp[25][25];
int ma[25][25];

void setMa(int x, int y) {
  if(x+1 >= 0 && y+1 >= 0) {
    ma[x+1][y+1] = 1;
  }
}

int main() {
  dp[0][1] = 1;

  scanf("%d %d %d %d", &n, &m, &maX, &maY);

  setMa(maX, maY); // P0
  setMa(maX+2, maY+1); // P1
  setMa(maX+1, maY+2); // P2
  setMa(maX-1, maY+2); // P3
  setMa(maX-2, maY+1); // P4
  setMa(maX-2, maY-1); // P5
  setMa(maX-1, maY-2); // P6
  setMa(maX+1, maY-2); // P7
  setMa(maX+2, maY-1); // P8
  
  for (int i = 1; i <= n+1; ++i) {
    for (int j = 1; j <= m+1; ++j) {
      if(!ma[i][j])
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      
        // printf("%d %d:\n", i, j);
        // for(int i=1; i<=n+1; ++i) {
        //   for(int j=1; j<=m+1; ++j) {
        //     printf("%d(%d) ", dp[i][j], ma[i][j]);
        //   }printf("\n");
        // }printf("\n");
    }
  }

  printf("%lld", dp[n+1][m+1]);
  return 0;
}