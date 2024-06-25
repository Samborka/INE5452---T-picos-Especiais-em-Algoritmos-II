#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<int> valores;
    for (int i = 0; i < n; ++i)
    {
      int valor;
      cin >> valor;
      valores.push_back(valor);
    }

    int soma = 1;
    int moedas = valores.size() > 1 ? 2 : 1;
    // Obter o máximo de moedas de valores menores possível.
    for (int i = 1; i < valores.size() - 1; ++i)
      if (soma + valores[i] < valores[i + 1])
      {
        soma += valores[i];
        ++moedas;
      }

    cout << moedas << endl;
  }
  return 0;
}