#include <iostream>
#include <cmath>

using namespace std;

int coefficientP;
int coefficientQ;
int coefficientR;
int coefficientS;
int coefficientT;
int coefficientU;

inline double calculateFunction(double x)
{
  return (coefficientP * exp(-x) + coefficientQ * sin(x) + coefficientR * cos(x) + coefficientS * tan(x) + coefficientT * x * x + coefficientU);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(4);

  while(cin >> coefficientP >> coefficientQ >> coefficientR >> coefficientS >> coefficientT >> coefficientU)
  {
    double a = 0;
    double b = 1;

    if(calculateFunction(a) * calculateFunction(b) > 0)
      cout << "No solution\n";
    else
    {
      double m = (a + b) / 2.0;
      double fm = calculateFunction(m);

      while(fabs(fm) > 1.0e-7)
      {
        if(fm * calculateFunction(b) > 0)
          b = m;
        else
          a = m;

        m = (a + b) / 2.0;
        fm = calculateFunction(m);
      }

      cout << fixed << m << "\n";
    }
  }

  return 0;
}