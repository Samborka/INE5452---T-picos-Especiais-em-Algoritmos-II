#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int numDrivers, dailyHours, overtimeRate;
  while (cin >> numDrivers >> dailyHours >> overtimeRate, !(numDrivers == 0 && dailyHours == 0 && overtimeRate == 0))
  {
    vector<int> morningRoute(numDrivers);
    vector<int> eveningRoute(numDrivers);

    for (int i = 0; i < numDrivers; ++i)
      cin >> morningRoute[i];
    for (int i = 0; i < numDrivers; ++i)
      cin >> eveningRoute[i];

    sort(morningRoute.begin(), morningRoute.end());
    sort(eveningRoute.rbegin(), eveningRoute.rend());

    int overtimePay = 0;
    for (int i = 0; i < numDrivers; ++i)
    {
      int totalHours = morningRoute[i] + eveningRoute[i];
      overtimePay += totalHours > dailyHours?
               (totalHours - dailyHours) * overtimeRate : 0;
    }
    cout << overtimePay << endl;
  }
  return 0;
}