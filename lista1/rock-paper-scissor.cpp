#include <stdio.h>

inline bool isWinningMove(char player1, char player2) {
    return (player1 == 'r' && player2 == 's') ||
           (player1 == 's' && player2 == 'p') ||
           (player1 == 'p' && player2 == 'r');
}

inline int readInt(int *num) {
    static char ch;
    while ((ch = getchar())) {
        if (ch >= '0' && ch <= '9')
            break;
    }
    *num = ch - '0';
    while ((ch = getchar()) >= '0')
        *num = (*num << 3) + (*num << 1) + ch - '0';
    return 1;
}

int main() {
    int numPlayers, numRounds, totalMatches, i, isFirst = 0;
    int scores[105][2], player1, player2;
    char move1[20], move2[20];

    while (scanf("%d %d", &numPlayers, &numRounds) == 2) {
        totalMatches = numRounds * numPlayers * (numPlayers - 1) / 2;

        if (isFirst)
            puts("");
        isFirst = 1;

        for (i = 1; i <= numPlayers; i++)
            scores[i][0] = scores[i][1] = 0;

        while (totalMatches--) {
            readInt(&player1);
            move1[0] = getchar();
            readInt(&player2);
            move2[0] = getchar();
            while (getchar() != '\n');

            if (isWinningMove(move1[0], move2[0]))
                scores[player1][0]++, scores[player2][1]++;
            else if (isWinningMove(move2[0], move1[0]))
                scores[player2][0]++, scores[player1][1]++;
        }

        for (i = 1; i <= numPlayers; i++) {
            if (scores[i][0] + scores[i][1])
                printf("%.3f\n", (float)scores[i][0] / (scores[i][0] + scores[i][1]));
            else
                puts("-");
        }
    }

    return 0;
}