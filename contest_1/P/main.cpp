#include <iostream>
#include <string>

int main() {
    int x = 0, y = 0;
    std::string direction;
    int distance;

    while (std::cin >> direction >> distance) {
        if (direction == "North") {
            y += distance;
        } else if (direction == "South") {
            y -= distance;
        } else if (direction == "East") {
            x += distance;
        } else if (direction == "West") {
            x -= distance;
        }
    }

    std::cout << x << " " << y;
    return 0;
}
