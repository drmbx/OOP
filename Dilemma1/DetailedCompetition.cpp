#include "DetailedCompetition.h"

DetailedCompetition::DetailedCompetition(const std::array<StrategyEnum, 3> &strategies, ReferenceTable reference_table)
        :
        strategies_({StrategyFactory::factory(strategies[0]),
                     StrategyFactory::factory(strategies[1]),
                     StrategyFactory::factory(strategies[2])}),
        reference_table_(reference_table) {}

void DetailedCompetition::Simulation() {
    for (int step{};; ++step) {
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

        std::cout << "Раунд " << step + 1 << ":" << std::endl;
        for (int i{}; i < 3; i++)
            std::cout << "Стратегия " << strategies_[i]->GetName()
                      << " " << (move_table_[step][i] ? "сотрудничетает. " : "предаёт. ")
                      << "Очков за текущий ход: " << cur_step_results[i]
                      << ". Очков всего: " << score_table_[step][i] << std::endl;

        std::string line;
        std::getline(std::cin, line);
        if (line == "quit")
            break;
    }

}