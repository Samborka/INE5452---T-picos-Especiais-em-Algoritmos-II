#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int targetSum, numElements;
int elements[20];
map<vector<int>, bool> solutions;
vector<int> currentCombination;

void search(int k, int m, int sum, vector<int> combination) {
  if (sum == targetSum) {
    if (solutions[combination] == true)
      return;
    solutions[combination] = true;
    for (int i = 0; i < k; i++)
      printf(i == k - 1 ? "%d" : "%d+", combination[i]);
    printf("\n");
    return;
  }
  if (sum > targetSum || m == numElements)
    return;
  for (int i = m; i < numElements; i++) {
    combination.push_back(elements[i]);
    search(k + 1, i + 1, sum + elements[i], combination);
    combination.pop_back();
  }
}

int main() {
  for (;;) {
    scanf("%d %d", &targetSum, &numElements);
    if (targetSum == 0 && numElements == 0)
      break;
    for (int i = 0; i < numElements; i++)
      scanf("%d", &elements[i]);
    solutions.clear();
    printf("Sums of %d:\n", targetSum);
    search(0, 0, 0, currentCombination);
    if (solutions.size() == 0)
      printf("NONE\n");
  }
}
