#include <iostream>
#include <queue>

int main() {
  int n;
  while (std::cin >> n && n != 0) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; i++) {
      int num;
      std::cin >> num;
      pq.push(num);
    }

    int totalCost = 0;
    while (pq.size() > 1) {
      int num1 = pq.top();
      pq.pop();
      int num2 = pq.top();
      pq.pop();
      int sum = num1 + num2;
      totalCost += sum;
      pq.push(sum);
    }

    std::cout << totalCost << std::endl;
  }

  return 0;
}