#include <iostream>
#include <string_view>

using std::string_view;
using std::cout;

bool NextToken(string_view &sv, const char delimiter, string_view &token) {
    if (sv.empty()) {
        return false;
    }

    const size_t pos = sv.find(delimiter);

    if (pos == string_view::npos) {
        token = sv;
        sv = sv.substr(sv.length());
        return true;
    }

    token = sv.substr(0, pos);
    sv = sv.substr(pos + 1);

    return true;
}

int main() {
    string_view sv = "Hello world and good bye";
    const char delimiter = ' ';
    string_view token;
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        cout << token << "\n";
    }
}