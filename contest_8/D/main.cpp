#include <iostream>
#include <string>
#include <utility>

class Profile {
    std::string name;
    std::string gender;
    int age;

public:
    Profile(std::string name, const int age, std::string gender)
        : name(std::move(name)), gender(std::move(gender)), age(age) {
    }

    [[nodiscard]] std::string toString() const {
        return "Profile(Name: " + name + ", Age: " + std::to_string(age) + ", Gender: " + gender + ")";
    }

    void print() const {
        std::cout << toString() << std::endl;
    }

    void happyBirthday() {
        age++;
        std::cout << "Happy Birthday! " << name << " is " << age << "!" << std::endl;
    }
};
