#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
  int numBeverages, numDependencies, cases = 0, beverageIndex, dependencyIndex, tn, i;
  char beverageName[105], dependencyName[105][105];
  while(scanf("%d", &numBeverages) == 1) {
    map<string, int> beverageIndexMap;
    vector<int> dependencies[105];
    int indegree[105] = {};
    for(i = 0; i < numBeverages; i++) {
      scanf("%s", beverageName);
      beverageIndexMap[beverageName] = i;
    }
    scanf("%d", &numDependencies);
    while(numDependencies--) {
      scanf("%s", beverageName);
      beverageIndex = beverageIndexMap[beverageName];
      scanf("%s", beverageName);
      dependencyIndex = beverageIndexMap[beverageName];
      dependencies[beverageIndex].push_back(dependencyIndex);
      indegree[dependencyIndex]++;
    }
    priority_queue<int, vector<int>, greater<int> > Q;
    for(i = 0; i < numBeverages; i++)
      if(indegree[i] == 0)
        Q.push(i);
    printf("Case #%d: Dilbert should drink beverages in this order:", ++cases);
    while(!Q.empty()) {
      tn = Q.top();
      Q.pop();
      for(vector<int>::iterator it = dependencies[tn].begin();
        it != dependencies[tn].end(); it++) {
        indegree[*it]--;
        if(indegree[*it] == 0)
          Q.push(*it);
      }
      printf(" %s", dependencyName[tn]);
    }
    puts(".\n");
  }
  return 0;
}