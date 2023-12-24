<<<<<<< HEAD
#include "RandomStrategy.h"

RandomStrategy::RandomStrategy() :
        name_("Random"), mt_(std::random_device{}()), dist_(0, 1) {}

Choice RandomStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    return static_cast<Choice>(dist_(mt_));
}

const std::string &RandomStrategy::GetName() {
    return name_;
=======
#include "RandomStrategy.h"

RandomStrategy::RandomStrategy() :
        name_("Random StrategyEnum"), mt_(std::random_device{}()), dist_(0, 1) {}

Choice RandomStrategy::GetMove(const MoveTable &table, int step) {
    return static_cast<Choice>(dist_(mt_));
}

const std::string &RandomStrategy::GetName() {
    return name_;
>>>>>>> d06e24c4321ce550dd3c016247dcbcd40e6427e5
}