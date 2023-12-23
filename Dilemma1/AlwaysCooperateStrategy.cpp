#include "AlwaysCooperateStrategy.h"

AlwaysCooperateStrategy::AlwaysCooperateStrategy() :
        name_("Always Betray StrategyEnum") {}

Choice AlwaysCooperateStrategy::GetMove(const MoveTable &table, int step) {
    return C;
}

const std::string &AlwaysCooperateStrategy::GetName() {
    return name_;
}