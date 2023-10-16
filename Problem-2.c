#include <stdio.h>

void printCombinations(int score) {
    int TD_2pt, TD_XP, FG, Safety;
    int total_score;

    for (TD_2pt = 0; TD_2pt * 8 <= score; TD_2pt++) {
        for (TD_XP = 0; TD_XP * 7 <= score; TD_XP++) {
            for (FG = 0; FG * 3 <= score; FG++) {
                for (Safety = 0; Safety * 2 <= score; Safety++) {
                    total_score = TD_2pt * 8 + TD_XP * 7 + FG * 3 + Safety * 2;
                    if (total_score == score) {
                        printf("%d TD + 2pt, %d TD + XP, %d TD, %d 3pt FG, %d Safety\n",
                            TD_2pt, TD_XP, TD_XP, FG, Safety);
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter a non-negative integer: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Terminating the program. Enter a value less than or equal to 1 to quit.\n");
            break;
        }

        printf("Possible combinations of scoring plays for %d:\n", score);
        printCombinations(score);
    }

    return 0;
}
