#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iomanip>

int main() {
    int numCases;
    std::cin >> numCases;

    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
        int numFriends;
        std::cin >> numFriends;

        std::map<int, std::set<int>> stampOwners;
        std::vector<int> friendShares(numFriends);

        for (int friendNum = 0; friendNum < numFriends; ++friendNum) {
            int numStamps;
            std::cin >> numStamps;

            for (int i = 0; i < numStamps; ++i) {
                int stampType;
                std::cin >> stampType;
                stampOwners[stampType].insert(friendNum);
            }
        }

        int uniqueStamps = 0;
        for (const auto& [stamp, owners] : stampOwners) {
            if (owners.size() == 1) {
                friendShares[*owners.begin()]++;
                uniqueStamps++;
            }
        }

        std::cout << "Case " << caseNum << ": ";
        for (int share : friendShares) {
            double percentage = (double) share / uniqueStamps * 100;
            std::cout << std::fixed << std::setprecision(6) << percentage << "%";

            if (&share != &friendShares.back()) {
                std::cout << " ";
            } else {
                std::cout << '\n';
            }
        }
    }

    return 0;
}
