#include "AlwaysBetrayStrategy.h"

AlwaysBetrayStrategy::AlwaysBetrayStrategy() :
        name_("Always Betray StrategyEnum") {}

Choice AlwaysBetrayStrategy::GetMove(const MoveTable &table, int step) {
    return D;
}

const std::string &AlwaysBetrayStrategy::GetName() {
    return name_;
}

