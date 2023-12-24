#include "AlwaysCooperateStrategy.h"

AlwaysCooperateStrategy::AlwaysCooperateStrategy() :
        name_("Always Cooperate") {}

Choice AlwaysCooperateStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    return C;
}

const std::string &AlwaysCooperateStrategy::GetName() {
    return name_;
}