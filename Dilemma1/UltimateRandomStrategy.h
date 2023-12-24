#pragma once

#include <random>
#include "IStrategy.h"

class UltimateRandomStrategy final : public IStrategy {
public:
    UltimateRandomStrategy();

    ~UltimateRandomStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name_;
    std::mt19937 mt_;
    std::uniform_int_distribution<int> dist_;
};