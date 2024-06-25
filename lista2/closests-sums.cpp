#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

int findClosestSum(const std::vector<int>& nums, int query) {
  std::set<int> sums;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      int sum = nums[i] + nums[j];
      sums.insert(sum);
    }
  }

  auto it = sums.lower_bound(query);

  if (it == sums.begin()) {
    return *it;
  } else if (it == sums.end()) {
    return *std::prev(it);
  } else {
    int prevSum = *std::prev(it);
    int nextSum = *it;

    if (query - prevSum <= nextSum - query) {
      return prevSum;
    } else {
      return nextSum;
    }
  }
}

int main() {
  int caseNum = 1;
  int n;

  while (std::cin >> n && n != 0) {
    std::vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      std::cin >> nums[i];
    }

    int m;
    std::cin >> m;

    std::cout << "Case " << caseNum << ":" << std::endl;

    for (int i = 0; i < m; i++) {
      int query;
      std::cin >> query;

      int closestSum = findClosestSum(nums, query);

      std::cout << "Closest sum to " << query << " is " << closestSum << "." << std::endl;
    }

    caseNum++;
  }

  return 0;
}