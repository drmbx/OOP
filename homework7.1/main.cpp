#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

template <typename String>
using Group = std::vector<String>;

template <typename String>
using Char = typename String::value_type;

template <typename String>
std::set<Char<String>> decomposeString(const String& str)
{
    std::set<Char<String>> set_of_chars;
    for (const auto& c : str)
        set_of_chars.insert(c);
    return (set_of_chars);
}

template <typename String>
std::vector<Group<String>> GroupHeavyStrings(const std::vector<String>& strings) {
    std::map<std::set<Char<String>>, Group<String>> chars_to_strings;
    for (const auto& str : strings)
        chars_to_strings[decomposeString(str)].push_back(str);

    std::vector<Group<String>> to_return;
    to_return.reserve(chars_to_strings.size());

    std::transform(chars_to_strings.begin(), chars_to_strings.end(), std::back_inserter(to_return), [](const auto& pair) {
        return pair.second;
    });

    return std::move(to_return);
}

int main()
{
    Group<std::string> b = {"law", "port", "top", "laptop", "pot", "paloalto", "wall", "awl"};
    std::vector<Group<std::string>> groups = GroupHeavyStrings(b);
    for (const auto& group : groups)
    {
        for (const auto& word : group)
        {
            std::cout << word << " ";
        }
        std::cout << "\n";
    }
}

