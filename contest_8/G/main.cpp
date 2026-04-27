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

class Rectangle {
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(const Point top_left, const Point bottom_right)
        : topLeft(top_left), bottomRight(bottom_right) {
    }

    [[nodiscard]] int area() const {
        return std::abs(bottomRight.getX() - topLeft.getX()) *
               std::abs(bottomRight.getY() - topLeft.getY());
    }

    [[nodiscard]] int perimeter() const {
        return 2 * (std::abs(bottomRight.getX() - topLeft.getX()) +
                    std::abs(bottomRight.getY() - topLeft.getY()));
    }

    void print() const {
        std::cout << "Rectangle with top left corner at " << topLeft.toString()
                << " and bottom right corner at " << bottomRight.toString() << std::endl;
    }
};
