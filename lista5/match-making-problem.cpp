#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int numBachelors, numSpinsters, cases = 0;
  int bachelors[10005], spinsters[10005];
  while(scanf("%d %d", &numBachelors, &numSpinsters) == 2) {
    if(numBachelors == 0 && numSpinsters == 0)
      break;
    int minBachelorAge = 0xfffffff, i;
    for(i = 0; i < numBachelors; i++)
      scanf("%d", bachelors+i), minBachelorAge = min(minBachelorAge, bachelors[i]);
    for(i = 0; i < numSpinsters; i++)
      scanf("%d", spinsters+i);
    if(numBachelors <= numSpinsters)
      printf("Case %d: 0\n", ++cases);
    else
      printf("Case %d: %d %d\n", ++cases, numBachelors-numSpinsters, minBachelorAge);
  }
  return 0;
}