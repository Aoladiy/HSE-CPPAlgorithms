#include <iostream>

int main() {
    int v, t;
    constexpr int road_length = 109;
    std::cin >> v >> t;
    const int distance = v * t;
    int final_location = distance % road_length;
    if (final_location < 0) {
        final_location += road_length;
    }
    std::cout << final_location;
    return 0;
}
