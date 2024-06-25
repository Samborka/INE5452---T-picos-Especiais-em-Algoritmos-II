#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;

vector<vector<int>> arrTable;
bitset<30> rw, ld, rd;

void placeCol(int col, vector<int>& row) {
  if (col >= 8) {
    arrTable.push_back(row);
    return;
  } else {
    for (int tryRow = 0; tryRow < 8; tryRow++) {
      if (!rw[tryRow] && !ld[tryRow - col + 8 - 1] && !rd[tryRow + col]) {
        row[col] = tryRow;

        rw[tryRow] = ld[tryRow - col + 8 - 1] = rd[tryRow + col] = true;
        placeCol(col + 1, row);
        rw[tryRow] = ld[tryRow - col + 8 - 1] = rd[tryRow + col] = false;
      }
    }
  }
}

void preproc() {
  arrTable.clear();
  vector<int> row(8, 0);
  placeCol(0, row);
}

int processCase(const vector<int>& origArr) {
  int min = 10, temp;
  for (const auto& arr : arrTable) {
    temp = 0;
    for (int j = 0; j < 8; j++) {
      if (origArr[j] != arr[j])
        temp++;
    }
    if (temp < min)
      min = temp;
    if (min == 0)
      break;
  }
  return min;
}

int main() {
  preproc();

  int count = 0;
  vector<int> origArr(8, 0);

  while (scanf("%d %d %d %d %d %d %d %d", &origArr[0], &origArr[1],
         &origArr[2], &origArr[3], &origArr[4], &origArr[5], &origArr[6],
         &origArr[7]) != EOF) {
    count++;

    for (int i = 0; i < 8; i++)
      origArr[i]--;

    int ans = processCase(origArr);
    printf("Case %d: %d\n", count, ans);
  }

  return 0;
}