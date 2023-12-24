<<<<<<< HEAD
#pragma once

#include <memory>
#include "AlwaysBetrayStrategy.h"
#include "AlwaysCooperateStrategy.h"
#include "RandomStrategy.h"
#include "StrategyEnum.h"

class StrategyFactory {
public:
    static std::unique_ptr<IStrategy> factory(StrategyEnum strategy);
=======
#pragma once

#include <memory>
#include "AlwaysBetrayStrategy.h"
#include "AlwaysCooperateStrategy.h"
#include "RandomStrategy.h"
#include "StrategyEnum.h"

class StrategyFactory {
public:
    static std::unique_ptr<IStrategy> factory(StrategyEnum strategy);
>>>>>>> d06e24c4321ce550dd3c016247dcbcd40e6427e5
};