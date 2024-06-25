#include <cstdio>
using namespace std;

int main() {
  int testCases, a, b, c;

  scanf("%d", &testCases);
  while (testCases--) {
    scanf("%d %d %d", &a, &b, &c);

    bool solutionFound = false;
    int x, y, z;

    for (x = -22; x <= 22 && !solutionFound; x++)
      if (x * x <= c)
        for (y = -100; y <= 100 && !solutionFound; y++)
          if (y != x && x * x + y * y <= c)
            for (z = -100; z <= 100 && !solutionFound; z++)
              if (z != x && z != y && x + y + z == a
                  && x * y * z == b
                  && x * x + y * y + z * z == c) {
                printf("%d %d %d\n", x, y, z);
                solutionFound = true;
              }
    if (!solutionFound)
      printf("No solution.\n");
  }

  return 0;
}