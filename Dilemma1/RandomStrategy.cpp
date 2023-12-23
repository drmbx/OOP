#include "RandomStrategy.h"

RandomStrategy::RandomStrategy() :
        name_("Random StrategyEnum"), mt_(std::random_device{}()), dist_(0, 1) {}

Choice RandomStrategy::GetMove(const MoveTable &table, int step) {
    return static_cast<Choice>(dist_(mt_));
}

const std::string &RandomStrategy::GetName() {
    return name_;
}