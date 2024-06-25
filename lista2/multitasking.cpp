#include <iostream>
#include <bitset>
#include <string>

constexpr int MAX_MINUTES = 1000001;

std::bitset<MAX_MINUTES> minuteSchedule;

std::string checkConflicts(int n, int m, int *oneTimeStart, int *oneTimeEnd, int *repeatStart, int *repeatEnd, int *repeatInterval) {
    for (int i = 0; i < n; ++i) {
        for (int j = oneTimeStart[i]; j < oneTimeEnd[i]; ++j) {
            if (minuteSchedule[j]) {
                return "CONFLICT";
            }
            minuteSchedule.set(j);
        }
    }

    for (int i = 0; i < m; ++i) {
        int start = repeatStart[i];
        int end = repeatEnd[i];
        int interval = repeatInterval[i];

        while (end <= MAX_MINUTES) {
            for (int j = start; j < end; ++j) {
                if (minuteSchedule[j]) {
                    return "CONFLICT";
                }
                minuteSchedule.set(j);
            }
            start += interval;
            end += interval;
        }
    }

    return "NO CONFLICT";
}

int main() {
    for (;;) {
        int n, m;
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        int oneTimeStart[n], oneTimeEnd[n], repeatStart[m], repeatEnd[m], repeatInterval[m];

        for (int i = 0; i < n; ++i) {
            std::cin >> oneTimeStart[i] >> oneTimeEnd[i];
        }

        for (int i = 0; i < m; ++i) {
            std::cin >> repeatStart[i] >> repeatEnd[i] >> repeatInterval[i];
        }

        std::cout << checkConflicts(n, m, oneTimeStart, oneTimeEnd, repeatStart, repeatEnd, repeatInterval) << std::endl;
    }

    return 0;
}
