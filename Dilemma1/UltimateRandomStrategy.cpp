#include "UltimateRandomStrategy.h"
#include "StrategyEnum.h"
#include "StrategyFactory.h"

UltimateRandomStrategy::UltimateRandomStrategy() :
        name_("Ultimate Random"), mt_(std::random_device{}()), dist_(0, UltimateRandomEnum - 1) {}

Choice UltimateRandomStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    auto strategy = StrategyFactory::factory(static_cast<StrategyEnum>(dist_(mt_)));
    return strategy->GetMove(table, score_table, place, step);
}

const std::string &UltimateRandomStrategy::GetName() {
    return name_;
}