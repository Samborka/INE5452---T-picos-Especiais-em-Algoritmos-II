#include <stdio.h>

#define MAX_V 10000000
#define MIN_V 0

int graph[101][101];

int maxFlow(int source, int sink, int n) {
  int maxFlow = 0;
  int pre[101], V[101], a, b;
  int Q[10001], Qt;

  while (1) {
    int used[101] = {};

    for (a = 0; a <= n; a++) {
      V[a] = MIN_V;
    }

    V[source] = MAX_V;
    Qt = 0;
    Q[0] = source;
    pre[source] = source;

    for (a = 0; a <= Qt; a++) {
      int tn = Q[a];
      used[tn] = 0;

      for (b = 1; b <= n; b++) {
        int tw = (V[tn] < graph[tn][b]) ? V[tn] : graph[tn][b];

        if (tw > V[b]) {
          V[b] = tw;
          pre[b] = tn;

          if (used[b] == 0) {
            Q[++Qt] = b;
            used[b] = 1;
          }
        }
      }
    }

    if (V[sink] == 0) {
      break;
    }

    maxFlow += V[sink];

    for (a = sink; a != source; a = pre[a]) {
      graph[pre[a]][a] -= V[sink];
      graph[a][pre[a]] += V[sink];
    }
  }

  return maxFlow;
}

int main() {
  int n, m, a, b, v, source, sink, x, y;
  int C = 0;

  while (scanf("%d", &n) == 1 && n) {
    scanf("%d %d %d", &source, &sink, &m);

    for (a = 1; a <= n; a++) {
      for (b = 1; b <= n; b++) {
        graph[a][b] = 0;
      }
    }

    for (a = 0; a < m; a++) {
      scanf("%d %d %d", &x, &y, &v);
      graph[x][y] += v;
      graph[y][x] += v;
    }

    printf("Network %d\n", ++C);
    printf("The bandwidth is %d.\n\n", maxFlow(source, sink, n));
  }

  return 0;
}