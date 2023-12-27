#include <iostream>

template<typename Ch, typename Tr, typename... Args, size_t... Is>
auto operator<<(std::basic_ostream<Ch, Tr> &os, std::tuple<Args...> const &t)

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
