#include <stdio.h>
#include <vector>
#include <queue>
#define MAXN 1000005
using namespace std;

vector<int> graph[MAXN];
int inDegree[MAXN], answer[MAXN];

inline int readChar() {
  const int N = 1048576;
  static char buf[N];
  static char *p = buf, *end = buf;
  if (p == end) {
    if ((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
    p = buf;
  }
  return *p++;
}

inline int readInt(int *x) {
  static char c, neg;
  while ((c = readChar()) < '-') {
    if (c == EOF) return 0;
  }
  neg = (c == '-') ? -1 : 1;
  *x = (neg == 1) ? c - '0' : 0;
  while ((c = readChar()) >= '0')
    *x = (*x << 3) + (*x << 1) + c - '0';
  *x *= neg;
  return 1;
}

int main() {
  int numVertices, numEdges, i, x, y, tn;
  while (readInt(&numVertices)) {
    if (numVertices == 0)  break;
    readInt(&numEdges);
    for (i = 1; i <= numVertices; i++)
      graph[i].clear(), inDegree[i] = 0;
    while (numEdges--) {
      readInt(&x);
      readInt(&y);
      graph[x].push_back(y);
      inDegree[y]++;
    }
    queue<int> Q;
    for (i = 1; i <= numVertices; i++)
      if (inDegree[i] == 0)
        Q.push(i);
    int at = 0;
    while (!Q.empty()) {
      tn = Q.front(), Q.pop();
      answer[at++] = tn;
      for (vector<int>::iterator it = graph[tn].begin();
        it != graph[tn].end(); it++) {
        if (--inDegree[*it] == 0) {
          Q.push(*it);
        }
      }
    }
    if (at != numVertices) puts("IMPOSSIBLE");
    else for (i = 0; i < numVertices; i++)
      printf("%d\n", answer[i]);
  }
  return 0;
}