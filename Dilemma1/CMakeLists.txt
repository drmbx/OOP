cmake_minimum_required(VERSION 3.26)
project(Dilemma1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Dilemma1 main.cpp
        AlwaysBetrayStrategy.cpp
        AlwaysBetrayStrategy.h
        IStrategy.h
        Choice.h
        AlwaysCooperateStrategy.cpp
        AlwaysCooperateStrategy.h
        RandomStrategy.cpp
        RandomStrategy.h
        StrategyFactory.cpp
        StrategyFactory.h
        StrategyEnum.h
        ICompetition.h
        DetailedCompetition.cpp
        DetailedCompetition.h
        FastCompetition.cpp
        FastCompetition.h
        TournamentCompetition.cpp
        TournamentCompetition.h
        Defaults.h
        CompetitionEnum.h
        EnviousStrategy.cpp
        EnviousStrategy.h
        EnviousMercifulStrategy.cpp
        EnviousMercifulStrategy.h
        RevengefulStrategy.cpp
        RevengefulStrategy.h
        RevengefulMercifulStrategy.cpp
        RevengefulMercifulStrategy.h
        UltimateRandomStrategy.cpp
        UltimateRandomStrategy.h
        Parsers.cpp
        Parsers.h)
