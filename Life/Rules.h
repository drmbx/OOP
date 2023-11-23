#include <set>
#include <string>

class Rules {
  std::set<std::pair<int, int>> aliveCells;
  std::set<int> nBirth;
  std::set<int> nSurvive;
 public:
  Rules();
  Rules(const std::string &fileName);
};