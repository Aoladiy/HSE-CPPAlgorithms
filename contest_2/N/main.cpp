#include <iostream>

bool is_leap(const int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int days_in_month(const int month, const int year) {
    if (month == 2) {
        return is_leap(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int main() {
    int d, m, y;
    std::cin >> d >> m >> y;

    for (int i = 0; i < 2; ++i) {
        ++d;
        if (d > days_in_month(m, y)) {
            d = 1;
            ++m;
            if (m > 12) {
                m = 1;
                ++y;
            }
        }
    }

    std::cout << d << " " << m << " " << y;
    return 0;
}
