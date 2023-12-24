#include <iostream>
#include <set>

class Cell {
public:
    explicit Cell(bool is_alive, size_t x, size_t y) : is_alive_(is_alive), x_(x), y_(y) {}

private:
    bool is_alive_;
    size_t x_, y_;
};

class Field {
public:
    Field();


private:

};

class Rules {
    Rules() : n_born_({2}),
              n_survive_({2, 3}),
              width_(400),
              heigth_(400) {}

private:
    std::set<int> n_born_;
    std::set<int> n_survive_;
    int width_, heigth_;
};

class Game {
public:
    Game()=default;
    void game_cycle()
    {



    }
private:
    Rules rules_;
};

int main(int argc, char *argv[]) {
    Game game;
    game.game_cycle();
    return 0;
}
