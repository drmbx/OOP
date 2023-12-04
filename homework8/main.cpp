#include <iostream>
#include <fstream>
#include <unordered_set>
#include <list>
#include <unordered_map>

int main() {
    std::string file = "input.txt";
    std::ifstream in(file);

    int n, number, go_before;
    in >> n;

    std::unordered_set<int> on_field;
    std::list<int> players;
    std::unordered_map<int, std::list<int>::iterator> map_num_iter;

    for (int i = 0; i < n; i++) {
        in >> number >> go_before;
        on_field.insert(number);
        if (on_field.contains(go_before)) {
            players.insert(map_num_iter[go_before], number);
            map_num_iter[number] = std::prev(map_num_iter[go_before]);
        } else {
            players.push_back(number);
            map_num_iter[number] = std::prev(players.end());
        }
    }

    for (const auto& player : players)
    {
        std::cout << player << " ";
    }
    std::cout << std::endl;

    return 0;
}