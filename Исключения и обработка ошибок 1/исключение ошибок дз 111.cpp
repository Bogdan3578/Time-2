#include <iostream>
#include <string>
class bad_length {
public:
    bad_length() = default;
};
int function(const std::string& str, int forbidden_length) {
    if (static_cast<int>(str.length()) == forbidden_length) {
        throw bad_length();
    }
    return static_cast<int>(str.length());
}
int main() {
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    if (!(std::cin >> forbidden_length)) {
        std::cerr << "Ошибка ввода запретной длины.\n";
        return 1;
    }
    std::cin.ignore();
    while (true) {
        std::string word;
        std::cout << "Введите слово: ";
        if (!std::getline(std::cin, word)) {
            break;
        }
        try {
            int len = function(word, forbidden_length);
            std::cout << "Длина слова " << word << " " <<  "равна " << len << "\n";
        } catch (const bad_length&) {
            std::cout << "Вы ввели слово запретной длины! До свидания\n";
            break;
        }
    }

    return 0;
}
