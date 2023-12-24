#pragma once

#include "IStrategy.h"

class EnviousStrategy final : public IStrategy{
public:
    EnviousStrategy();

    ~EnviousStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name_;
};


