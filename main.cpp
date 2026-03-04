#include <iostream>
#include <clang-c/Index.h>

int main() {
    CXIndex index = clang_createIndex(0, 0);
    if (index) {
        std::cout << "Libclang initialized successfully!" << std::endl;
        clang_disposeIndex(index);
    } else {
        std::cerr << "Failed to initialize libclang" << std::endl;
        return 1;
    }
    return 0;
}
