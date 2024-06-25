#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 1000

int adjacencyMatrix[100][100], numNodes;
int nodeDepth[100], nodeLow[100];
int nodeUsed[100], cutVertices;

int DFS(int node, int depth, int parent) {
  int i, lowestBack = INFINITY, numChildren = 0, tmp, isCutVertex = 0;
  nodeDepth[node] = depth;

  for(i = 1; i <= numNodes; i++) {
    if(adjacencyMatrix[node][i] == 1) {
      if(nodeUsed[i] == 0) {
        nodeUsed[i] = 1;
        tmp = DFS(i, depth+1, node);
        if(tmp >= depth) isCutVertex = 1;
        lowestBack = lowestBack < tmp ? lowestBack : tmp;
        numChildren++;
      } else {
        if(i != parent)
          lowestBack = lowestBack < nodeDepth[i] ? lowestBack : nodeDepth[i];
      }
    }
  }

  nodeLow[node] = lowestBack;

  if(node == 1) {
    if(numChildren > 1)
      cutVertices++;
  } else {
    cutVertices += isCutVertex;
  }

  return nodeLow[node];
}

int main() {
  int x, y;
  char c;

  while(scanf("%d", &numNodes) == 1 && numNodes) {
    memset(adjacencyMatrix, 0, sizeof(adjacencyMatrix));
    memset(nodeDepth, 0, sizeof(nodeDepth));
    memset(nodeLow, 0, sizeof(nodeLow));
    memset(nodeUsed, 0, sizeof(nodeUsed));

    while(scanf("%d", &x) == 1 && x) {
      while(scanf("%d%c", &y, &c) == 2) {
        adjacencyMatrix[x][y] = 1;
        adjacencyMatrix[y][x] = 1;
        if(c == '\n') break;
      }
    }

    nodeUsed[1] = 1;
    cutVertices = 0;
    DFS(1, 1, 0);
    printf("%d\n", cutVertices);
  }

  return 0;
}