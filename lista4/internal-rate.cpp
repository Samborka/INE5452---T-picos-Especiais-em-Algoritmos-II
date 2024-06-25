#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cmath>

static const double EPS = 1e-9;

double calculateNPV(const std::vector<double>& CF, int T, double IRR)
{
  double npv = CF[0];
  for (int i = 1; i <= T; ++i)
    npv += CF[i] / std::pow(1.0 + IRR, i);

  return npv;
}

int main()
{
  int T;
  while (std::cin >> T && T != 0)
  {
    std::vector<double> CF(T + 1);
    for (int i = 0; i <= T; ++i)
      std::cin >> CF[i];

    // Método da bissecção.
    double L = -0.99, U = std::numeric_limits<double>::max(), IRR = -1.0;
    while (L <= U + EPS)
    {
      double M = (L + U) / 2.0;
      double npv = calculateNPV(CF, T, M);
      if (std::abs(npv) <= EPS)
      {
        IRR = M;
        break;
      }
      if (npv > EPS)
        L = M;
      else
        U = M;
    }
    if (std::abs(IRR + 1.0) <= EPS)
      std::cout << "No" << std::endl;
    else
      std::cout << std::setprecision(2) << std::fixed << IRR << std::endl;
  }
  return 0;
}
