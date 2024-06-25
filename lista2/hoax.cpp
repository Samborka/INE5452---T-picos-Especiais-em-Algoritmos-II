#include <iostream>
#include <set>

int main() {
    while (true) {
        int numSets;
        std::cin >> numSets;

        if (numSets == 0) {
            break;
        }

        std::multiset<int> numbersSet;
        unsigned long long totalSum = 0;

        for (int i = 0; i < numSets; ++i) {
            int setSize;
            std::cin >> setSize;

            for (int j = 0; j < setSize; ++j) {
                int num;
                std::cin >> num;
                numbersSet.insert(num);
            }

            auto maxIt = numbersSet.end();
            --maxIt;
            int maximum = *maxIt;
            numbersSet.erase(maxIt);

            auto minIt = numbersSet.begin();
            int minimum = *minIt;
            numbersSet.erase(minIt);

            int diff = maximum - minimum;
            totalSum += diff;
        }

        std::cout << totalSum << std::endl;
    }

    return 0;
}
