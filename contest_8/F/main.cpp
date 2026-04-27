#include <cmath>
#include <string>
#include <iostream>

class Point {
    int x;
    int y;

public:
    explicit Point(const int x = 0, const int y = 0) : x(x), y(y) {
    }

    [[nodiscard]] int getX() const { return x; }
    [[nodiscard]] int getY() const { return y; }

    [[nodiscard]] std::string toString() const {
        return "(" + std::to_string(x) + "; " + std::to_string(y) + ")";
    }

    void print() const {
        std::cout << "Point(" << x << "; " << y << ")" << std::endl;
    }

    [[nodiscard]] double distance(const Point &other) const {
        return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
    }

    Point operator+(const Point &other) const {
        return Point(x + other.x, y + other.y);
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        os << p.toString();
        return os;
    }
};
