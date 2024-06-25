#include <stdio.h>

int card1[50], card2[50];
int used[50];
int numCards, numPairs, flag;

void dfs(int idx, int l) {
  if(idx == numCards) {
    if(l == card1[1])
      flag = 1;
    return;
  }

  int i;

  for(i = 2; i < numPairs+2; i++) {
    if(used[i] == 0) {
      if(l == card1[i]) {
        used[i] = 1;

        dfs(idx+1, card2[i]);

        used[i] = 0;
      }
      if(l == card2[i]) {
        used[i] = 1;

        dfs(idx+1, card1[i]);

        used[i] = 0;
      }
    }
  }
}

int main() {
  int i;

  while(scanf("%d", &numCards) == 1 && numCards) {
    scanf("%d", &numPairs);
    for(i = 0; i < numPairs+2; i++) {
      scanf("%d %d", &card1[i], &card2[i]);
      used[i] = 0;
    }

    flag = 0;

    dfs(0, card2[0]);
    puts(flag ? "YES" : "NO");
  }

  return 0;
}