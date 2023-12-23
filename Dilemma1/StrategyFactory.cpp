#include "StrategyFactory.h"
#include "StrategyEnum.h"

std::unique_ptr<IStrategy> StrategyFactory::factory(StrategyEnum strategy) {
    switch (strategy) {
        case AlwaysBetrayEnum:
            return std::make_unique<AlwaysBetrayStrategy>();
        case AlwaysCooperateEnum:
            return std::make_unique<AlwaysCooperateStrategy>();
        case RandomEnum:
            return std::make_unique<RandomStrategy>();
    }
}