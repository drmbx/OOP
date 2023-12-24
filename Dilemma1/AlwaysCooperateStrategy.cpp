<<<<<<< HEAD
#include "AlwaysCooperateStrategy.h"

AlwaysCooperateStrategy::AlwaysCooperateStrategy() :
        name_("Always Cooperate") {}

Choice AlwaysCooperateStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    return C;
}

const std::string &AlwaysCooperateStrategy::GetName() {
    return name_;
=======
#include "AlwaysCooperateStrategy.h"

AlwaysCooperateStrategy::AlwaysCooperateStrategy() :
        name_("Always Betray StrategyEnum") {}

Choice AlwaysCooperateStrategy::GetMove(const MoveTable &table, int step) {
    return C;
}

const std::string &AlwaysCooperateStrategy::GetName() {
    return name_;
>>>>>>> d06e24c4321ce550dd3c016247dcbcd40e6427e5
}