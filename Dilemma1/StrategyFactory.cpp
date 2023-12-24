#include "StrategyFactory.h"
#include "StrategyEnum.h"
#include "EnviousStrategy.h"
#include "EnviousMercifulStrategy.h"
#include "RevengefulStrategy.h"
#include "RevengefulMercifulStrategy.h"
#include "UltimateRandomStrategy.h"

std::unique_ptr<IStrategy> StrategyFactory::factory(StrategyEnum strategy) {
    switch (strategy) {
        case AlwaysBetrayEnum:
            return std::make_unique<AlwaysBetrayStrategy>();
        case AlwaysCooperateEnum:
            return std::make_unique<AlwaysCooperateStrategy>();
        case RandomEnum:
            return std::make_unique<RandomStrategy>();
        case EnviousEnum:
            return std::make_unique<EnviousStrategy>();
        case EnviousMercifulEnum:
            return std::make_unique<EnviousMercifulStrategy>();
        case RevengefulEnum:
            return std::make_unique<RevengefulStrategy>();
        case RevengefulMercifulEnum:
            return std::make_unique<RevengefulMercifulStrategy>();
        case UltimateRandomEnum:
            return std::make_unique<UltimateRandomStrategy>();
    }
}