#include <stdio.h>
#include <algorithm>
using namespace std;

void calculateIsoscelesTriangles() {
  int numPoints;
  long long x[1024], y[1024];
  while(scanf("%d", &numPoints) == 1 && numPoints) {
    for(int i = 0; i < numPoints; i++)
      scanf("%lld %lld", &x[i], &y[i]);
    long long distances[1024];
    long long count = 0;
    for(int i = 0; i < numPoints; i++) {
      for(int j = 0; j < numPoints; j++)
        distances[j] = (x[i] - x[j]) * (x[i] - x[j]) +
            (y[i] - y[j]) * (y[i] - y[j]);
      sort(distances, distances+numPoints);
      long long totalCount = 1;
      distances[numPoints] = -1;
      for(int j = 1; j <= numPoints; j++) {
        if(distances[j] != distances[j-1]) {
          count += totalCount * (totalCount-1) / 2;
          totalCount = 1;
        } else {
          totalCount++;
        }
      }
    }
    printf("%lld\n", count);
  }
}

int main() {
  calculateIsoscelesTriangles();
  return 0;
}