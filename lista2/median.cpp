#include <iostream>     // std::cout
#include <algorithm>    // std::nth_element, std::random_shuffle
#include <vector>       // std::vector

int main () {
  std::vector<int> myvector;
  int num;

  while (std::cin >> num && !std::cin.eof()) {
    myvector.push_back(num);

    if(myvector.size() % 2 ==0){
      std::nth_element(myvector.begin(), myvector.begin() + myvector.size()/2, myvector.end());

      std::cout << (myvector[myvector.size()/2] + myvector[myvector.size()/2 - 1])/2 << std::endl;
    } else {
      std::nth_element(myvector.begin(), myvector.begin() + myvector.size()/2, myvector.end());
      std::cout << myvector[myvector.size()/2] << std::endl;
    }
  }

  return 0;
}