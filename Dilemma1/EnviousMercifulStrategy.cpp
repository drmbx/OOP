#include "EnviousMercifulStrategy.h"

EnviousMercifulStrategy::EnviousMercifulStrategy() :
        name_("Envious Merciful") {}

Choice EnviousMercifulStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    if (step == 0)
        return C;
    switch (place) {
        case 0:
            if (score_table[step - 1][1] > score_table[step - 1][0] &&
                score_table[step - 1][2] > score_table[step - 1][0])
                return D;
            else
                return C;
        case 1:
            if (score_table[step - 1][0] > score_table[step - 1][1] &&
                score_table[step - 1][2] > score_table[step - 1][1])
                return D;
            else
                return C;
        case 2:
            if (score_table[step - 1][0] > score_table[step - 1][2] &&
                score_table[step - 1][1] > score_table[step - 1][2])
                return D;
            else
                return C;
    }
}

const std::string &EnviousMercifulStrategy::GetName() {
    return name_;
}
