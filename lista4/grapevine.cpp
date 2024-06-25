#include <iostream>
#include <algorithm>

using namespace std;

int calculateMaxSize(int n, int m, int number[500][500], int a, int b) {
  int maxSize = 0;
  for (int i = 0; i < n; ++i) {
    int minPosition = lower_bound(number[i], number[i] + m, a) - number[i];
    for (int j = maxSize; j < n; ++j) {
      if (n <= i + j or m <= minPosition + j or b < number[i + j][minPosition + j])
        break;
      maxSize = max(maxSize, j + 1);
    }
  }
  return maxSize;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int rows;
  int columns;
  int number[500][500];

  while (cin >> rows >> columns and (rows or columns)) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j)
        cin >> number[i][j];
    }

    int queries;
    cin >> queries;

    while (queries--) {
      int a;
      int b;
      cin >> a >> b;

      int maxSize = calculateMaxSize(rows, columns, number, a, b);

      cout << maxSize << "\n";
    }
    cout << "-\n";
  }

  return 0;
}
