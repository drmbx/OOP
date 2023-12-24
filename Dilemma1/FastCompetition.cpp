<<<<<<< HEAD
#include "FastCompetition.h"

FastCompetition::FastCompetition(const std::array<StrategyEnum, 3> &strategies,
                                 ReferenceTable reference_table, int steps) :
        strategies_({StrategyFactory::factory(strategies[0]),
                     StrategyFactory::factory(strategies[1]),
                     StrategyFactory::factory(strategies[2])}),
        reference_table_(reference_table),
        steps_(steps) {}

void FastCompetition::Simulation() {
    for (int step{}; step < steps_; ++step) {
        move_table_.push_back({strategies_[0]->GetMove(move_table_, score_table_, 0, step),
                               strategies_[1]->GetMove(move_table_, score_table_, 1, step),
                               strategies_[2]->GetMove(move_table_, score_table_, 2, step)});
        const std::array<int, 3> &cur_step_results(reference_table_
                                                   [move_table_[step][0]]
                                                   [move_table_[step][1]]
                                                   [move_table_[step][2]]);
        if (step == 0)
            score_table_.push_back(cur_step_results);
        else
            score_table_.push_back({score_table_[step - 1][0] + cur_step_results[0],
                                    score_table_[step - 1][1] + cur_step_results[1],
                                    score_table_[step - 1][2] + cur_step_results[2]});
    }
    for (int i{}; i < 3; i++)
        std::cout << "Стратегия " << strategies_[i]->GetName()
                  << " набирает " << score_table_[steps_ - 1][i] << " очков." << std::endl;

    std::cout << std::endl;
}

const std::array<int, 3> &FastCompetition::GetResults() {
    return score_table_[steps_ - 1];
}
=======
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
>>>>>>> d06e24c4321ce550dd3c016247dcbcd40e6427e5
