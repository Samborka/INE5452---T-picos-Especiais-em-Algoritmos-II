#include <cstdio>
#include <set>
using namespace std;

int bars[30];

int main() {
  int testCases, n;
  long long total, target;
  set<long long> checker;

  scanf("%d", &testCases);
  while (testCases--) {
    scanf("%lld\n%d", &target, &n);

    for (int i = 0; i < n; i++) {
      scanf("%d", &bars[i]);
    }

    int n2 = n / 2, n1 = n - n2;
    for (int s = 0; s < (1 << n1); s++) {
      total = 0;
      for (int i = 0; i < n1; i++) {
        if (1 & (s >> i)) {
          total += bars[i];
        }
      }
      checker.insert(total);
    }

    for (int s = 0; s < (1 << n2); s++) {
      total = 0;
      for (int i = 0; i < n2; i++) {
        if (1 & (s >> i)) {
          total += bars[n1+i];
        }
      }
      if(checker.count(target-total)) break;
    }

    if(checker.count(target-total)) printf("YES\n");
    else printf("NO\n");

    checker.clear();
  }

  return 0;
}