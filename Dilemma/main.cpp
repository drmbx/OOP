#include <random>
#include <vector>
#include <array>
#include <iostream>

struct TableRow {
    bool did_betray[3];
    int score[3];
};

class ICompetitor {
public :
    virtual bool DidBetray(TableRow table[], size_t turn) = 0;
};

class AlwaysCooperateCompetitor : public ICompetitor {
    bool DidBetray(TableRow table[], size_t turn) override {
        return false;
    }
};

class AlwaysBetrayCompetitor : public ICompetitor {
    bool DidBetray(TableRow table[], size_t turn) override {
        return true;
    }
};

class RandomCompetitor : public ICompetitor {
    bool DidBetray(TableRow table[], size_t turn) override {
        return rand() % 2;
    }
};

template<size_t turns_>
class Arena {
public:
    Arena(ICompetitor &comp0, ICompetitor &comp1, ICompetitor &comp2)
            : comp0_(comp0), comp1_(comp1), comp2_(comp2), log_() {}

    std::array<TableRow, turns_> Competition() {
        for (size_t turn = 0; turn < turns_; ++turn) {
            log_[turn].did_betray[0] = comp0_.DidBetray(log_.data(), turn);
            log_[turn].did_betray[1] = comp1_.DidBetray(log_.data(), turn);
            log_[turn].did_betray[2] = comp2_.DidBetray(log_.data(), turn);

            if (log_[turn].did_betray[0]) {
                if (log_[turn].did_betray[1]) {
                    if (log_[turn].did_betray[2]) {
                        turn == 0 ? log_[turn].score[0] = 1 : log_[turn - 1].score[0] += 1;
                        turn == 0 ? log_[turn].score[1] = 1 : log_[turn - 1].score[1] += 1;
                        turn == 0 ? log_[turn].score[2] = 1 : log_[turn - 1].score[2] += 1;
                    } else {
                        turn == 0 ? log_[turn].score[0] = 5 : log_[turn - 1].score[0] += 5;
                        turn == 0 ? log_[turn].score[1] = 5 : log_[turn - 1].score[1] += 5;
                        turn == 0 ? log_[turn].score[2] = 0 : log_[turn - 1].score[2] += 0;
                    }
                } else {
                    if (log_[turn].did_betray[2]) {
                        turn == 0 ? log_[turn].score[0] = 5 : log_[turn - 1].score[0] += 5;
                        turn == 0 ? log_[turn].score[1] = 0 : log_[turn - 1].score[1] += 0;
                        turn == 0 ? log_[turn].score[2] = 5 : log_[turn - 1].score[2] += 5;
                    } else {
                        turn == 0 ? log_[turn].score[0] = 9 : log_[turn - 1].score[0] += 9;
                        turn == 0 ? log_[turn].score[1] = 3 : log_[turn - 1].score[1] += 3;
                        turn == 0 ? log_[turn].score[2] = 3 : log_[turn - 1].score[2] += 3;
                    }
                }
            } else if (log_[turn].did_betray[1]) {
                if (log_[turn].did_betray[2]) {
                    turn == 0 ? log_[turn].score[0] = 1 : log_[turn - 1].score[0] += 1;
                    turn == 0 ? log_[turn].score[1] = 1 : log_[turn - 1].score[1] += 1;
                    turn == 0 ? log_[turn].score[2] = 1 : log_[turn - 1].score[2] += 1;
                } else {
                    turn == 0 ? log_[turn].score[0] = 5 : log_[turn - 1].score[0] += 5;
                    turn == 0 ? log_[turn].score[1] = 5 : log_[turn - 1].score[1] += 5;
                    turn == 0 ? log_[turn].score[2] = 0 : log_[turn - 1].score[2] += 0;
                }
            } else {
                if (log_[turn].did_betray[2]) {
                    turn == 0 ? log_[turn].score[0] = 5 : log_[turn - 1].score[0] += 5;
                    turn == 0 ? log_[turn].score[1] = 0 : log_[turn - 1].score[1] += 0;
                    turn == 0 ? log_[turn].score[2] = 5 : log_[turn - 1].score[2] += 5;
                } else {
                    turn == 0 ? log_[turn].score[0] = 9 : log_[turn - 1].score[0] += 9;
                    turn == 0 ? log_[turn].score[1] = 3 : log_[turn - 1].score[1] += 3;
                    turn == 0 ? log_[turn].score[2] = 3 : log_[turn - 1].score[2] += 3;
                }
            }

        }
        return std::move(log_);
    }

private:
    ICompetitor &comp0_, &comp1_, &comp2_;
    std::array<TableRow, turns_> log_;
};


int main() {
    AlwaysBetrayCompetitor c0;
    AlwaysCooperateCompetitor c1;
    RandomCompetitor c2;
    Arena<200> arena(c0, c1, c2);
    std::array<TableRow, 200> arr = arena.Competition();
    for (int i = 0; i < 200; i++) {
        for (auto &j: arr[i].did_betray)
            std::cout << j << " ";
        for (auto &j: arr[i].score)
            std::cout << j << " ";
        std::cout << "\n";
    }
    return 0;
}
