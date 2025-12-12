#include <iostream>
#include <cstdlib>  // for atoi

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <num1> <num2>\n";
        return 1;
    }

    int a = std::atoi(argv[1]);
    int b = std::atoi(argv[2]);

    int sum = a + b;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
