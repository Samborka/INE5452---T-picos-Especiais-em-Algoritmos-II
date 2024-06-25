#include <stdio.h>

int main() {
  int totalDots, totalPairs;
  while(scanf("%d %d", &totalDots, &totalPairs) == 2) {
    int dp1[10205] = {}, dp2[10205] = {};
    int i, j, position, value, answer = 0;
    dp1[0] = 1, dp2[0] = 1;
    for(i = 0; i < totalPairs; i++) {
      scanf("%d %d", &position, &value);
      for(j = totalDots - position; j >= 0; j--) {
        if(dp1[j + position] < dp1[j] + value && dp1[j])
          dp1[j + position] = dp1[j] + value;
      }
      for(j = totalDots - position + 200; j >= 0; j--) {
        if(dp2[j + position] < dp2[j] + value && dp2[j])
          dp2[j + position] = dp2[j] + value;
      }
    }
    for(i = 0; i <= totalDots; i++)
      answer = answer > dp1[i] ? answer : dp1[i];
    for(i = totalDots > 1800 ? 2001 : totalDots + 201; i <= totalDots + 200; i++)
      answer = answer > dp2[i] ? answer : dp2[i];
    printf("%d\n", answer - 1);
  }
  return 0;
}