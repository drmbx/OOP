#pragma once

#include "ICompetition.h"
#include "IStrategy.h"
#include "StrategyEnum.h"

class TournamentCompetition : public ICompetition {
public:
    TournamentCompetition(ReferenceTable reference_table, int steps);

    void Simulation() final;

private:
    ReferenceTable reference_table_;
    int steps_;

    std::array<int, LastEnum> total_scores_;
};