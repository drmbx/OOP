#pragma once

#include <iostream>
#include "ICompetition.h"
#include "StrategyFactory.h"

class DetailedCompetition : public ICompetition {
public:
    DetailedCompetition(std::array<StrategyEnum, 3> strategies, ReferenceTable reference_table);

    void Simulation() final;

private:
    std::array<std::unique_ptr<IStrategy>, 3> strategies_;
    ReferenceTable reference_table_;

    MoveTable move_table_;
    ScoreTable score_table_;
};
