#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int numElements;

  while(cin >> numElements and numElements)
  {
    vector<int> positiveNumbers;
    for(int i = 0; i < numElements; ++i)
    {
      int num;
      cin >> num;
      if(num > 0)
        positiveNumbers.push_back(num);
    }

    int size = positiveNumbers.size();
    if(size)
    {
      for(int i = 0; i < size; ++i)
        cout << positiveNumbers[i] << (i + 1 == size?'\n':' ');
    }
    else
      cout << "0\n";
  }

  return 0;
}