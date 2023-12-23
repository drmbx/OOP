#pragma once

#include <array>
#include "ICompetition.h"
#include "StrategyEnum.h"
#include "IStrategy.h"
#include "StrategyFactory.h"
#include <iostream>

class FastCompetition : public ICompetition {
public:
    FastCompetition(std::array<StrategyEnum, 3> strategies, ReferenceTable reference_table, int steps);

    void Simulation() final;

    const std::array<int, 3> &GetResults();

private:
    std::array<std::unique_ptr<IStrategy>, 3> strategies_;
    ReferenceTable reference_table_;
    int steps_;

    MoveTable move_table_;
    ScoreTable score_table_;
};