#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct Contestant {
    int number;
    int problemsSolved;
    int penaltyTime;

    Contestant() : number(0), problemsSolved(0), penaltyTime(0) {}
};

bool compareContestants(const Contestant& c1, const Contestant& c2) {
    if (c1.problemsSolved != c2.problemsSolved) {
        return c1.problemsSolved > c2.problemsSolved;
    } else if (c1.penaltyTime != c2.penaltyTime) {
        return c1.penaltyTime < c2.penaltyTime;
    } else {
        return c1.number < c2.number;
    }
}

int main() {
    int numCases;
    std::cin >> numCases;

    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
        std::map<int, Contestant> contestants;

        while (true) {
            int contestant, problem, time;
            char status;
            std::cin >> contestant;

            if (contestant == 0) {
                break;
            }

            std::cin >> problem >> time >> status;

            if (status == 'C' || status == 'I') {
                Contestant& currentContestant = contestants[contestant];
                currentContestant.number = contestant;

                if (status == 'C') {
                    currentContestant.problemsSolved++;
                    currentContestant.penaltyTime += time;
                } else {
                    currentContestant.penaltyTime += 20;
                }
            }
        }

        std::vector<Contestant> sortedContestants;
        for (const auto& pair : contestants) {
            sortedContestants.push_back(pair.second);
        }
        std::sort(sortedContestants.begin(), sortedContestants.end(), compareContestants);

        if (caseNum > 1) {
            std::cout << std::endl;
        }

        for (const auto& c : sortedContestants) {
            std::cout << c.number << " " << c.problemsSolved << " " << c.penaltyTime << std::endl;
        }
    }

    return 0;
}
