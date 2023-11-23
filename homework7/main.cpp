//#include "test_runner.h"

#include <algorithm>
#include <string>
#include <vector>

template <typename String>
using Group = std::vector<String>;

template <typename String>
using Char = typename String::value_type;

template <typename String>
std::vector<Group<String>> GroupHeavyStrings(std::vector<String> strings) {
  std::vector<Group<String>> groups;
  
}
