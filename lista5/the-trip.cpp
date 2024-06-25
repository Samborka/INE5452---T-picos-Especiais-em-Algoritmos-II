#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int numKnapsacks;
  int dimensions[10001];

  while(cin >> numKnapsacks and numKnapsacks)
  {
    for(int i = 0; i < numKnapsacks; ++i)
      cin >> dimensions[i];

    int maxOccurrences = 0;
    int currentOccurrences = 1;
    sort(dimensions, dimensions + numKnapsacks);

    dimensions[numKnapsacks] = 0;
    for(int i = 0; i < numKnapsacks; ++i)
    {
      if(dimensions[i] == dimensions[i + 1])
      {
        ++currentOccurrences;
        continue;
      }

      maxOccurrences = max(maxOccurrences, currentOccurrences);
      currentOccurrences = 1;
    }

    cout << maxOccurrences << "\n";

    for(int i = 0; i < maxOccurrences; ++i)
    {
      for(int j = i; j < numKnapsacks; j += maxOccurrences)
      {
        if(j != i)
          cout << " ";
        cout << dimensions[j];
      }
      cout << "\n";
    }

  }

  return 0;
}
