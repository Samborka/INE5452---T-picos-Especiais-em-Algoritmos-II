#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int BLACK = 0;
static const int WHITE = 1;
static const int UNKNOWN = 2;

void placeGuards()
{
  int testCases;
  cin >> testCases;
  while (testCases--)
  {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> graph(vertices);
    vector<int> color(vertices, UNKNOWN);
    bool isBipartite = true;

    while (edges--)
    {
      int from, to;
      cin >> from >> to;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    int totalCount = 0;
    for (int j = 0; j < graph.size() && isBipartite; ++j)
    {
      if (color[j] != UNKNOWN)
        continue;

      queue<int> q;
      int count[2] = {0};
      color[j] = BLACK;
      ++count[color[j]];
      q.push(j);
      while (!q.empty() && isBipartite)
      {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); ++i)
        {
          int v = graph[u][i];
          if (color[v] == color[u])
          {
            isBipartite = false;
            break;
          }
          else if (color[v] == UNKNOWN)
          {
            color[v] = 1 - color[u];
            ++count[color[v]];
            q.push(v);
          }
        }
      }
      totalCount += max(1, min(count[BLACK], count[WHITE]));
    }

    if (isBipartite)
      cout << totalCount << endl;
    else
      cout << -1 << endl;
  }
}

int main()
{
  placeGuards();
  return 0;
}