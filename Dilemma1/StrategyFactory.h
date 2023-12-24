#pragma once

#include <memory>
#include "AlwaysBetrayStrategy.h"
#include "AlwaysCooperateStrategy.h"
#include "RandomStrategy.h"
#include "StrategyEnum.h"

class StrategyFactory {
public:
    static std::unique_ptr<IStrategy> factory(StrategyEnum strategy);
};