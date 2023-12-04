#include <iostream>
import module1;
import module2;
import module3;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << Module1::getMyName();
    return 0;
}
