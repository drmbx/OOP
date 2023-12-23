#include "FastCompetition.h"

FastCompetition::FastCompetition(std::array<StrategyEnum, 3> strategies, ReferenceTable reference_table, int steps) :
        strategies_({StrategyFactory::factory(strategies[0]),
                     StrategyFactory::factory(strategies[1]),
                     StrategyFactory::factory(strategies[2])}),
        reference_table_(reference_table),
        steps_(steps) {}

void FastCompetition::Simulation() {
    for (int step{}; step < steps_; ++step) {
        for (int i{}; i < 3; i++)
            move_table_[step][i] = strategies_[i]->GetMove(move_table_, step);

        if (step == 0)
            score_table_[step] = reference_table_
            [move_table_[step][0]]
            [move_table_[step][1]]
            [move_table_[step][2]];
        else
            for (int i{}; i < 3; i++)
                score_table_[step][i] = score_table_[step - 1][i] + reference_table_
                [move_table_[step][0]]
                [move_table_[step][1]]
                [move_table_[step][2]][i];
    }
    for (int i{}; i < 3; i++)
        std::cout << "Стратегия " << strategies_[i]->GetName()
                  << " набирает " << score_table_[steps_ - 1][i] << " очков." << std::endl;

    std::cout << std::endl;
    std::cin.get();
}

const std::array<int, 3> &FastCompetition::GetResults() {
    return score_table_[steps_ - 1];
}
