#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX_NODES 100010
using namespace std;

vector<int> graph[MAX_NODES];
int stk[MAX_NODES], stackIndex;
int visited[MAX_NODES], inStack[MAX_NODES];
int visitOrder[MAX_NODES], orderIndex;
int leader[MAX_NODES];

int findStronglyConnectedComponents(int node) {
  visited[node] = inStack[node] = 1;
  stk[++stackIndex] = node;
  visitOrder[node] = ++orderIndex;
  int minOrder = visitOrder[node];
  for(vector<int>::iterator it = graph[node].begin(); it != graph[node].end(); it++) {
    if(!visited[*it]) {
      minOrder = min(minOrder, findStronglyConnectedComponents(*it));
    }
    if(inStack[*it]) {
      minOrder = min(minOrder, visitOrder[*it]);
    }
  }
  if(minOrder == visitOrder[node]) {
    do {
      leader[stk[stackIndex]] = node;
      inStack[stk[stackIndex]] = 0;
    } while(stk[stackIndex--] != node);
  }
  return minOrder;
}

int main() {
  int numNodes, numEdges, numTests, x, y;
  int i;
  scanf("%d", &numTests);
  while(numTests--) {
    scanf("%d %d", &numNodes, &numEdges);
    for(i = 1; i <= numNodes; i++) {
      graph[i].clear();
      visitOrder[i] = visited[i] = inStack[i] = 0;
      leader[i] = i;
    }
    while(numEdges--) {
      scanf("%d %d", &x, &y);
      graph[x].push_back(y);
    }
    for(i = 1; i <= numNodes; i++) {
      if(!visited[i]) {
        orderIndex = 0, stackIndex = -1;
        findStronglyConnectedComponents(i);
      }
    }
    int inDegree[MAX_NODES] = {};
    for(i = 1; i <= numNodes; i++) {
      for(vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++) {
        if(leader[*it] != *it)
          inDegree[*it]++;
        if(leader[i] != leader[*it])
          inDegree[leader[*it]]++;
      }
    }
    int ans = 0;
    for(i = 1; i <= numNodes; i++)
      if(!inDegree[i] && leader[i] == i)
        ans++;
    printf("%d\n", ans);
  }
  return 0;
}