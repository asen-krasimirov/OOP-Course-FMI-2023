#include "ExpressionCalculator.h"

BooleanExpression *ExpressionCalculator::parseExpression(const StringView &stringView) {
    return nullptr;
}

ExpressionCalculator::ExpressionCalculator(const MyString &str) {
    _expression = parseExpression(str);
}
