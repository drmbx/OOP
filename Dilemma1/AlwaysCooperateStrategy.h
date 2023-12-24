#pragma once

#include "IStrategy.h"

class AlwaysCooperateStrategy final : public IStrategy {
public:
    AlwaysCooperateStrategy();

    ~AlwaysCooperateStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name_;
};