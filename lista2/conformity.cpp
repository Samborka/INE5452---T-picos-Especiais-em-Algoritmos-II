#include <iostream>
#include <map>
#include <set>

int main() {
    while (true) {
        int numSets;
        std::cin >> numSets;

        if (numSets == 0) {
            break;
        }

        std::map<std::set<int>, int> setFrequency;

        for (int i = 0; i < numSets; ++i) {
            int num1, num2, num3, num4, num5;
            std::cin >> num1 >> num2 >> num3 >> num4 >> num5;

            std::set<int> numberSet;
            numberSet.insert(num1);
            numberSet.insert(num2);
            numberSet.insert(num3);
            numberSet.insert(num4);
            numberSet.insert(num5);

            setFrequency[numberSet]++;
        }

        int maxFrequency = 0;
        for (const auto& pair : setFrequency) {
            if (pair.second > maxFrequency) {
                maxFrequency = pair.second;
            }
        }

        int totalCount = 0;
        for (const auto& pair : setFrequency) {
            if (pair.second == maxFrequency) {
                totalCount += maxFrequency;
            }
        }

        std::cout << totalCount << std::endl;
    }

    return 0;
}
