<<<<<<< HEAD
#include "AlwaysBetrayStrategy.h"

AlwaysBetrayStrategy::AlwaysBetrayStrategy() :
        name_("Always Betray") {}

Choice AlwaysBetrayStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    return D;
}

const std::string &AlwaysBetrayStrategy::GetName() {
    return name_;
}

=======
#include "AlwaysBetrayStrategy.h"

AlwaysBetrayStrategy::AlwaysBetrayStrategy() :
        name_("Always Betray StrategyEnum") {}

Choice AlwaysBetrayStrategy::GetMove(const MoveTable &table, int step) {
    return D;
}

const std::string &AlwaysBetrayStrategy::GetName() {
    return name_;
}

>>>>>>> d06e24c4321ce550dd3c016247dcbcd40e6427e5
