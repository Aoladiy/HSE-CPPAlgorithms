#include <iostream>
#include <string>
#include <vector>

struct Book {
    std::string author;
    std::string name;
    size_t page_count{};
};

Book read() {
    Book b;
    std::cin >> b.name >> b.author >> b.page_count;
    return b;
}

void print(const Book &b) {
    std::cout << "The book \"" << b.name << "\" written by " << b.author << " has " << b.page_count << " pages!";
}


int main() {
    size_t n; std::cin >> n;
    std::vector<Book> v(n);
    for (size_t i = v.size(); i > 0; --i) {
        v[i - 1] = read();
    }
    for (Book cur : v) {
        print(cur);
        std::cout << '\n';
    }
}