  #include <bits/stdc++.h>

  using namespace std;

  int main(void)
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int numTestCases;
    cin >> numTestCases;

    for(int testCase = 1; testCase <= numTestCases; ++testCase)
    {
      int numStones;
      int totalDistance;
      cin >> numStones >> totalDistance;

      int size = numStones + 2;
      vector<int> stone(1, 0);

      for(int i = 0; i < numStones; ++i)
      {
        char stoneType;
        char ignore;
        int stoneDistance;
        cin >> stoneType >> ignore >> stoneDistance;

        stone.push_back(stoneDistance);

        if(stoneType == 'B')
        {
          ++size;
          stone.push_back(stoneDistance);
        }
      }

      stone.push_back(totalDistance);

      int minJump = 0;

      for(int i = 3; i < size; ++i)
        minJump = max(minJump, stone[i] - stone[i - 2]);

      for(int i = 2; i < size; ++i)
        minJump = max(minJump, stone[i] - stone[i - 2]);

      cout << "Case " << testCase << ": " << minJump << "\n";
    }

    return 0;
  }