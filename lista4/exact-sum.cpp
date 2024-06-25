#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findBooksToBuy(const vector<int>& prices, int targetSum)
{
  int n = prices.size();
  int a = 0;
  int b = 0;
  int middle = targetSum >> 1;
  int minDifference = targetSum;

  for (int i = 0; prices[i] <= middle && i < n; ++i)
  {
    int k = targetSum - prices[i];
    auto j = lower_bound(prices.begin(), prices.end(), k);

    if (j != prices.end() && (int)(j - prices.begin()) != i && *j == k && abs(prices[i] - k) < minDifference)
    {
      b = k;
      a = prices[i];
      minDifference = abs(a - b);
    }
  }

  cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n)
  {
    vector<int> prices(n);

    for (int i = 0; i < n; ++i)
      cin >> prices[i];

    sort(prices.begin(), prices.end());

    int targetSum;
    cin >> targetSum;

    findBooksToBuy(prices, targetSum);
  }

  return 0;
}