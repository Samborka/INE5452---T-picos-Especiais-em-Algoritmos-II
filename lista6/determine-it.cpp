#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int num, an1;
  while(scanf("%d %d", &num, &an1) == 2) {
    long long matrix[50][50] = {};
    int i, j, k;
    matrix[num][1] = an1;
    for(i = num; i >= 1; i--) {
      for(j = 1; j <= num; j++) {
        if(i == num && j == 1)    continue;
        if(i >= j) {
          long long v1 = 0, v2 = 0;
          for(k = i+1; k <= num; k++)
            v1 = max(v1, matrix[k][1]+matrix[k][j]);
          for(k = 1; k < j; k++)
            v2 = max(v2, matrix[i][k]+matrix[num][k]);
          matrix[i][j] = v1 + v2;
        } else {
          long long &v = matrix[i][j];
          v = 0;
          for(k = i; k < j; k++)
            v = max(v, matrix[i][k]+matrix[k+1][j]);
        }
      }
    }
    printf("%lld\n", matrix[1][num]);
  }
  return 0;
}