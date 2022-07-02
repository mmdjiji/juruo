#include <stdio.h>

int map[25][25];
int visited[25][25];
int n, m, maX, maY;
int ans = 0;

void setMa(int x, int y) {
  if(x >= 0 && y >= 0) {
    map[x][y] = 1;
  }
}

void next(int x, int y) {
  if(x > n || y > m || map[x][y]) return;
  // printf("%d %d:\n", x, y);
  // for(int i=0; i<n; ++i) {
  //   for(int j=0; j<m; ++j) {
  //     printf("%d ", visited[i][j]);
  //   }printf("\n");
  // }printf("\n");
  if(x == n && y == m) {
    ++ans;
  } else {
    if(!visited[x][y]) {
      visited[x][y] = 1;
      next(x+1, y);
      next(x, y+1);
      visited[x][y] = 0;
    }
  }
}

int main() {
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

  next(0, 0);

  printf("%d\n", ans);

  return 0;
}