#include <iostream>
#include <string>


struct Point {
    int x;
    int y;
};

struct Character {
    char *name;
    int health;
    Point position;
};

int main() {
    Character hero = {"Артур", 100, {10, 20}};
    std::cout << "Герой: " << hero.name << ", Здоровье: " << hero.health << ", Положение: (" << hero.position.x << ", "
            << hero.position.y << ")\n";
    return 0;
}
