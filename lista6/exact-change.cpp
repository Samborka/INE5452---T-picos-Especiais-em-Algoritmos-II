#include <stdio.h>

int main() {
  int testCases, targetAmount, numCoins, i, j;
  scanf("%d", &testCases);
  while(testCases--) {
    scanf("%d %d", &targetAmount, &numCoins);
    int dp[20000] = {}, maxAmount, coinValue;
    dp[0] = 1, maxAmount = 0;
    for(i = 0; i < numCoins; i++) {
      scanf("%d", &coinValue);
      maxAmount += coinValue;
      if(maxAmount > 20000)  maxAmount = 19999;
      for(j = maxAmount; j >= coinValue; j--) {
        if(dp[j] == 0 || dp[j] > dp[j-coinValue]+1) {
          if(dp[j-coinValue]) {
            dp[j] = dp[j-coinValue]+1;
          }
        }
      }
    }
    while(dp[targetAmount] == 0)   targetAmount++;
    printf("%d %d\n", targetAmount, dp[targetAmount]-1);
  }
  return 0;
}