#pragma once

#include "IStrategy.h"

class RevengefulStrategy final : public IStrategy{
public:
    RevengefulStrategy();

    ~RevengefulStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name_;
};


