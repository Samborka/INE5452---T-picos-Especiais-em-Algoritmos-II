#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;

typedef vector<int> vi;

#define INF 1e9
#define MAX_V 105

int residual[MAX_V][MAX_V], max_flow, flow, source, sink;
vector<vi> adjacency_list;
vi parent;

int m, w, V;

void augment(int v, int min_edge) {
  if (v == source) {
    flow = min_edge;
    return;
  } else if (parent[v] != -1) {
    augment(parent[v], min(min_edge, residual[parent[v]][v]));
    residual[parent[v]][v] -= flow;
    residual[v][parent[v]] += flow;
  }
}

void EdmondKarps() {
  max_flow = 0;
  while (1) {
    flow = 0;
    bitset<MAX_V> visited;
    visited.set(source);
    queue<int> q;
    q.push(source);
    parent.assign(MAX_V, -1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == sink)
        break;
      for (int i = 0; i < (int) adjacency_list[u].size(); i++) {
        int v = adjacency_list[u][i];
        if (residual[u][v] > 0 && !visited.test(v)) {
          visited.set(v);
          q.push(v);
          parent[v] = u;
        }
      }
    }
    augment(sink, INF);
    if (flow == 0)
      break;
    max_flow += flow;
  }
}

int main() {
  while (scanf("%d %d", &m, &w), m || w) {
    V = m * 2 - 2;
    memset(residual, 0, sizeof residual);
    adjacency_list.assign(V, vi());

    source = 0;
    sink = V - 1;

    for (int i = 0; i < m - 2; i++) {
      int id, c, u, v;
      scanf("%d %d", &id, &c);
      id--;
      u = id + id - 1;
      v = u + 1;

      residual[u][v] = c;
      adjacency_list[u].push_back(v);
      adjacency_list[v].push_back(u);
    }

    for (int i = 0; i < w; i++) {
      int id1, id2, c, u1, u2, v1, v2;
      scanf("%d %d %d", &id1, &id2, &c);
      id1--;
      id2--;

      if (id1 != 0 && id1 != m - 1) {
        u1 = id1 + id1 - 1;
        v1 = u1 + 1;
      } else {
        if (id1 == 0)
          u1 = v1 = 0;
        else
          u1 = v1 = V - 1;
      }

      if (id2 != 0 && id2 != m - 1) {
        u2 = id2 + id2 - 1;
        v2 = u2 + 1;
      } else {
        if (id2 == 0)
          u2 = v2 = id2;
        else
          u2 = v2 = V - 1;
      }

      residual[v1][u2] = c;
      residual[v2][u1] = c;
      adjacency_list[v1].push_back(u2);
      adjacency_list[u2].push_back(v1);
      adjacency_list[v2].push_back(u1);
      adjacency_list[u1].push_back(v2);
    }

    EdmondKarps();
    printf("%d\n", max_flow);
  }

  return 0;
}