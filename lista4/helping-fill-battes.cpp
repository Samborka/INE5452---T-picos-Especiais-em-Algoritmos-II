#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  char character;
  int index = 0;
  vector<int> characterIndex[257];

  while(cin.read(&character, 1) and character != '\n')
    characterIndex[character].push_back(index++);

  int queries;
  cin >> queries;
  while(queries--)
  {
    string query;
    cin >> query;

    int firstIndex = 0;
    int lastIndex = -1;
    bool isMatched = true;
    int queryLength = query.length();

    for(index = 0; index < queryLength; ++index)
    {
      vector<int>::iterator iterator = upper_bound(characterIndex[query[index]].begin(), characterIndex[query[index]].end(), lastIndex);

      if(iterator == characterIndex[query[index]].end())
      {
        isMatched = false;
        break;
      }
      lastIndex = *iterator;
      if(!index)
        firstIndex = lastIndex;
    }

    if(isMatched)
      cout << "Matched " << firstIndex << " " << lastIndex << "\n";
    else
      cout << "Not matched\n";
  }

  return 0;
}