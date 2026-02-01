#include <iostream>

int main() {
    int num;
    std::cin >> num;
    switch (num) {
        case 1:
            std::cout << "mon";
            break;
        case 2:
            std::cout << "tue";
            break;
        case 3:
            std::cout << "wed";
            break;
        case 4:
            std::cout << "thu";
            break;
        case 5:
            std::cout << "fri";
            break;
        case 6:
            std::cout << "sat";
            break;
        case 7:
            std::cout << "sun";
            break;
        default: ;
    }
    return 0;
}
