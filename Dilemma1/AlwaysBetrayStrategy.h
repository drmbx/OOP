#pragma once

#include "IStrategy.h"

class AlwaysBetrayStrategy final : public IStrategy {
public:
    AlwaysBetrayStrategy();

    ~AlwaysBetrayStrategy() final = default;

    Choice GetMove(const MoveTable &table, int step) final;

    const std::string &GetName() final;

private:
    std::string name_;
};
