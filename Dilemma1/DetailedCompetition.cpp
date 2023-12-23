#include "DetailedCompetition.h"

DetailedCompetition::DetailedCompetition(std::array<StrategyEnum, 3> strategies, ReferenceTable reference_table) :
        strategies_({StrategyFactory::factory(strategies[0]),
                     StrategyFactory::factory(strategies[1]),
                     StrategyFactory::factory(strategies[2])}),
        reference_table_(reference_table) {}

void DetailedCompetition::Simulation() {
    for (int step{};; ++step) {
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

        for (int i{}; i < 3; i++)
            std::cout << "Стратегия " << strategies_[i]->GetName()
                      << " решает " << (move_table_[i][step] ? "сотрудничать " : "предать ")
                      << "очков за текущий ход: " << reference_table_
                      [move_table_[step][0]]
                      [move_table_[step][1]]
                      [move_table_[step][2]][i]
                      << " очков всего: " << score_table_[step][i] << std::endl;

        if (std::cin.get() == 'q')
            break;
    }

}