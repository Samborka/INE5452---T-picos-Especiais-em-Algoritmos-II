#include <iostream>
using namespace std;

int calculateConsumption(int price) {
  int consumption = 0;
  consumption += min(max(0, price/2), 100); price -= 2*100;
  consumption += min(max(0, price/3), 9900); price -= 3*9900;
  consumption += min(max(0, price/5), 990000); price -= 5*990000;
  consumption += max(0, price/7);
  return consumption;
}

int calculatePrice(int consumption) {
  int price = 0;
  price += min(max(0, consumption*2), 2*100); consumption -= 100;
  price += min(max(0, consumption*3), 3*9900); consumption -= 9900;
  price += min(max(0, consumption*5), 5*990000); consumption -= 990000;
  price += max(0, consumption*7);
  return price;
}

int main() {
  int a, b;
  while(cin >> a >> b && (a|b)) {
    int totalConsumption = calculateConsumption(a);
    int begin = 0, end = totalConsumption;
    int answer = 0;
    while(begin < end) {
      int mine = (begin+end)/2;
      int diff = calculatePrice(totalConsumption-mine) - calculatePrice(mine);
      if (diff > b)
        begin = mine;
      else if (diff < b)
        end = mine;
      else {
        answer = mine;
        break;
      }
    }

    cout << calculatePrice(answer) << endl;
  }

  return 0;
}