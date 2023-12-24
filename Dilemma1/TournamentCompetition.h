<<<<<<< HEAD
#pragma once

#include <unordered_map>
#include "ICompetition.h"
#include "IStrategy.h"
#include "StrategyEnum.h"

class TournamentCompetition final : public ICompetition {
public:
    TournamentCompetition(std::vector<StrategyEnum> strategies, ReferenceTable reference_table, int steps);

    ~TournamentCompetition() final = default;

    void Simulation() final;

private:
    std::vector<StrategyEnum> strategies_;
    ReferenceTable reference_table_;
    int steps_;

    std::vector<int> total_scores_;
=======
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
>>>>>>> d06e24c4321ce550dd3c016247dcbcd40e6427e5
};