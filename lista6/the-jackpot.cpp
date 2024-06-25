#include <cstdio>
using namespace std;

int main() {
  int numElements, index, array[100000];

  while (scanf("%d", &numElements), numElements) {
    for (index = 0; index < numElements; index++) {
      scanf("%d", &array[index]);
    }

    int maxSum = 0, currentSum = 0;
    for (index = 0; index < numElements; index++) {
      currentSum += array[index];
      if (currentSum > maxSum)
        maxSum = currentSum;
      if (currentSum < 0)
        currentSum = 0;
    }

    if (maxSum > 0)
      printf("The maximum winning streak is %d.\n", maxSum);
    else
      printf("Losing streak.\n");
  }

  return 0;
}