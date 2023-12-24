#include "AlwaysBetrayStrategy.h"

AlwaysBetrayStrategy::AlwaysBetrayStrategy() :
        name_("Always Betray") {}

Choice AlwaysBetrayStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    return D;
}

const std::string &AlwaysBetrayStrategy::GetName() {
    return name_;
}

