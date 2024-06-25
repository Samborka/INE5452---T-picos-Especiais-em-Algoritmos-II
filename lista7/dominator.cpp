#include <stdio.h>

int graph[105][105], visited[105], n;
int dominator[105][105];

void dfs(int node, int start) {
  if (node == start) {
    return;
  }
  int i;
  visited[node] = 1;
  for (i = 0; i < n; i++) {
    if (graph[node][i] && !visited[i]) {
      dfs(i, start);
    }
  }
}

int main() {
  int t, i, j, k;
  int cases = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &graph[i][j]);
      }
    }
    int fused[105] = {};
    for (i = 0; i < n; i++) {
      visited[i] = 0;
    }
    dfs(0, -1);
    for (i = 0; i < n; i++) {
      fused[i] = visited[i];
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        visited[j] = 0;
      }
      dfs(0, i);
      for (j = 0; j < n; j++) {
        if (fused[j] && !visited[j]) {
          dominator[i][j] = 1;
        } else {
          dominator[i][j] = 0;
        }
      }
      dominator[i][i] = fused[i];
    }
    printf("Case %d:\n", ++cases);
    putchar('+');
    for (i = -n + 1; i < n; i++) {
      putchar('-');
    }
    puts("+");
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        putchar('|');
        putchar(dominator[i][j] ? 'Y' : 'N');
      }
      puts("|");
      putchar('+');
      for (j = -n + 1; j < n; j++) {
        putchar('-');
      }
      puts("+");
    }
  }
  return 0;
}