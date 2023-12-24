#include <iostream>
#include <unordered_map>
#include "StrategyFactory.h"
#include "CompetitionEnum.h"
#include "ICompetition.h"
#include "DetailedCompetition.h"
#include "FastCompetition.h"
#include "TournamentCompetition.h"
#include "Parsers.h"

int main(const int argc, const char *argv[]) {
    system("chcp 65001");

    std::vector<std::string> arguments;

    CompetitionEnum mode;
    std::vector<StrategyEnum> strategies_vec;
    int steps;
    ReferenceTable matrix;

    for (int i = 1; i < argc; i++)
        arguments.emplace_back(argv[i]);

    if (arguments.size() < 3) {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }

    try {
        strategies_vec = Parsers::ParseStrategies(arguments);
        mode = Parsers::ParseCompetition(arguments);
        if ((mode != Tournament) && (strategies_vec.size() > 3)) {
            mode = Tournament;
            std::cout << "Mode forced to become Tournament since given number of strategies" << std::endl;
        }
        steps = Parsers::ParseSteps(arguments);
        matrix = Parsers::ParseMatrix(arguments);
    }
    catch (const std::exception &ex) {
        std::cout << "Input failed: " << ex.what() << std::endl;
        return 2;
    }

    std::unique_ptr<ICompetition> competition;
    std::array<StrategyEnum, 3> strategies_arr{strategies_vec[0], strategies_vec[1], strategies_vec[2]};
    switch (mode) {
        case Detailed:
            competition = std::make_unique<DetailedCompetition>(strategies_arr, matrix);
            break;
        case Fast:
            competition = std::make_unique<FastCompetition>(strategies_arr, matrix, steps);
            break;
        case Tournament:
            competition = std::make_unique<TournamentCompetition>(strategies_vec, matrix, steps);
            break;
    }
    competition->Simulation();
    return 0;
}
