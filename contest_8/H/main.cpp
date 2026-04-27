#include <iostream>
#include <string>
#include <utility>

class ChessPlayer {
public:
    std::string name;
    std::string surname;
    int rating;

    ChessPlayer(std::string p_name, std::string p_surname, const int p_rating)
        : name(std::move(p_name)), surname(std::move(p_surname)), rating(p_rating) {
    }

    void statistics() const {
        std::cout << "Full name: " << name << " " << surname << " Rating: " << rating << std::endl;
    }

    bool operator>(const ChessPlayer &other) const { return rating > other.rating; }
    bool operator<(const ChessPlayer &other) const { return rating < other.rating; }
    bool operator==(const ChessPlayer &other) const { return rating == other.rating; }
    bool operator!=(const ChessPlayer &other) const { return rating != other.rating; }

    bool operator>(const int r) const { return rating > r; }
    bool operator<(const int r) const { return rating < r; }
    bool operator==(const int r) const { return rating == r; }
    bool operator!=(const int r) const { return rating != r; }
};
