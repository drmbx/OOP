#include <iostream>
#include <list>
#include <vector>
#include <memory>

template<typename T>
class ContiguousAllocator {
public:
    using value_type = T;

    explicit ContiguousAllocator(std::size_t reserveSize) : capacity_(reserveSize), memory_(std::unique_ptr<T[]>(new T[capacity_])) {
        nextIndex_ = 0;
    }

    T* allocate(std::size_t n) {
        if (n > available()) {
            throw std::bad_alloc();
        }
        T* p = &memory_[nextIndex_];
        nextIndex_ += n;
        return p;
    }

    void deallocate(T* p, std::size_t n) {}

private:
    std::size_t available() const {
        return capacity_ - nextIndex_;
    }

    std::size_t capacity_;
    std::unique_ptr<T[]> memory_;
    std::size_t nextIndex_;
};

int main() {
    std::list<int, ContiguousAllocator<int>> myList(10);

    int value = 1;
    for (auto& element : myList) {
        element = value++;
    }

    std::cout << "Elements in the list: ";
    for (const auto& element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Memory addresses: ";
    for (const auto& element : myList) {
        std::cout << &element << " ";
    }
    std::cout << std::endl;

    return 0;
}