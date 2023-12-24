#include "RevengefulStrategy.h"

RevengefulStrategy::RevengefulStrategy() :
        name_("Revengeful") {}

Choice RevengefulStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    if (step == 0)
        return C;
    switch (place) {
        case 0:
            if (table[step - 1][1] == D || table[step - 1][2] == D)
                return D;
            else
                return C;
        case 1:
            if (table[step - 1][0] == D || table[step - 1][2] == D)
                return D;
            else
                return C;
        case 2:
            if (table[step - 1][0] == D || table[step - 1][1] == D)
                return D;
            else
                return C;
    }

}

const std::string &RevengefulStrategy::GetName() {
    return name_;
}
