#include "RadioButton.h"

RadioButton::RadioButton(size_t x, size_t y, const Vector <MyString> &options) : Controller(1, options.getSize(), x, y) {
    _options = options;
}

void RadioButton::setDataDialog() {
    char inputText;
    std::cin >> inputText;

    _selectedIndex = inputText - '0';
}
