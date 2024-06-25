#include <stdio.h>
#include <string.h>

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

char grid[700][700][4];
char visited[700][700];

void dfs(int x, int y, int n, int m) {
  visited[x][y] = 1;
  for(int i = 0, tx, ty; i < 4; i++) {
    tx = x + dx[i], ty = y + dy[i];
    if(tx < 0 || ty < 0 || tx >= n || ty >= m)
      continue;
    if(visited[tx][ty] || grid[x][y][i])
      continue;
    dfs(tx, ty, n, m);
  }
}

int main() {
  int N;
  char line[1024];
  while(scanf("%d", &N) == 1)	 {
    memset(grid, 0, sizeof(grid));
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < 2 * N - 1; i++) {
      scanf("%s", line);
      int x = i, y = x&1;
      for(int j = 0; j < N; j++, y += 2) {
        if(line[j] == 'H') {
          grid[x][y][0] = grid[x + 1][y][1] = 1;
          grid[x][y + 1][0] = grid[x + 1][y + 1][1] = 1;
        } else {
          grid[x][y][2] = grid[x][y + 1][3] = 1;
          grid[x + 1][y][2] = grid[x + 1][y + 1][3] = 1;
        }
      }
    }
    int connectedComponents = 0;
    for(int i = 0; i < 2 * N; i++) {
      for(int j = 0; j < 2 * N + 1; j++) {
        if(!visited[i][j]) {
          dfs(i, j, 2*N, 2*N+1);
          connectedComponents++;
        }
      }
    }
    printf("%d\n", connectedComponents - 1);
  }
  return 0;
}
