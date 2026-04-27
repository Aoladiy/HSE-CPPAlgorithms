#include <iostream>
#include <string>
#include <vector>

struct Point {
    int x;
    int y;
};

struct Item {
    const char* name;
    float weight;
};

struct Character {
    const char* name;
    int health;
    Point position;
    std::vector<Item> inventory;
};

int main() {
    Item sword = {"Меч", 3.5};
    Item shield = {"Щит", 5.0};

    Character hero = {"Артур", 100, {10, 20}, {sword, shield}};
    std::cout << "Персонаж: " << hero.name << ", Здоровье: " << hero.health
              << ", Положение: (" << hero.position.x << ", " << hero.position.y << ")\n";
    std::cout << "Инвентарь:\n";
    for (const Item& item : hero.inventory) {
        std::cout << " - " << item.name << " (Вес: " << item.weight << ")\n";
    }
    return 0;
}