#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int numTestCases, testCase = 1;
  cin >> numTestCases;
  while (numTestCases--)
  {
    int numCells;
    cin >> numCells;
    vector<char> field(numCells + 2, '#');
    for (int i = 0; i < numCells; ++i)
      cin >> field[i];

    int numScarecrows = 0;
    for (int i = 0; i < numCells; ++i)
    {
      // Greedily make a scarecrow cover 3 cells.
      if (field[i] == '.')
      {
        field[i] = field[i + 1] = field[i + 2] = '#';
        ++numScarecrows;
      }
    }
    cout << "Case " << testCase++ << ": " << numScarecrows << endl;
  }
  return 0;
}
