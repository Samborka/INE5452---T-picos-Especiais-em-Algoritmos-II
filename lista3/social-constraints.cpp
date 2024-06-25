#include <cstdio>
#include <algorithm>
using namespace std;

int findPosition(int p, int arr[], int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == p)
      return i;
  }
  return -1;
}

int countSatisfyingArrangements(int n, int m, int constraints[][3]) {
  int arr[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  int ans = 0;

  do {
    bool sat = true;
    for (int i = 0; i < m; i++) {
      int pos1 = findPosition(constraints[i][0], arr, n);
      int pos2 = findPosition(constraints[i][1], arr, n);
      int diff = abs(pos1 - pos2);

      if ((constraints[i][2] > 0 && diff > constraints[i][2]) ||
        (constraints[i][2] < 0 && diff < (-constraints[i][2]))) {
        sat = false;
        break;
      }
    }

    if (sat)
      ans++;
  } while (next_permutation(arr, arr + n));

  return ans;
}

int main() {
  int n, m;
  int constraints[20][3];

  while (scanf("%d %d", &n, &m), n || m) {
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &constraints[i][0], &constraints[i][1],
        &constraints[i][2]);
    }

    int ans = countSatisfyingArrangements(n, m, constraints);
    printf("%d\n", ans);
  }

  return 0;
}