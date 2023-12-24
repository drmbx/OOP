#pragma once

#include "IStrategy.h"

class EnviousMercifulStrategy final : public IStrategy{
public:
    EnviousMercifulStrategy();

    ~EnviousMercifulStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name_;
};