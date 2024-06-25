#include <iostream>
#include <vector>

using namespace std;

bool isPossible(const vector<int>& height, int k) {
  int lastHeight = 0;
  for (int i = 0; i < height.size(); ++i) {
    int jump = height[i] - lastHeight;

    if (k < jump)
      return false;
    else if (k == jump)
      --k;
    lastHeight = height[i];
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int testCases;
  cin >> testCases;

  for (int t = 1; t <= testCases; ++t) {
    int n;
    cin >> n;

    vector<int> height(n);
    int maxJump = 0;
    int lastHeight = 0;

    for (int i = 0; i < n; ++i) {
      cin >> height[i];

      int jump = height[i] - lastHeight;

      if (maxJump < jump)
        maxJump = jump;

      lastHeight = height[i];
    }

    cout << "Case " << t << ": ";

    if (isPossible(height, maxJump))
      cout << maxJump << "\n";
    else {
      int k = maxJump << 1;

      int right = k;
      int left = maxJump;
      int m = (left + right) >> 1;

      while (left < right) {
        if (isPossible(height, m)) {
          k = m;
          right = m;
        } else {
          left = m + 1;
        }
        m = (left + right) >> 1;
      }

      cout << k << endl;
    }
  }

  return 0;
}
