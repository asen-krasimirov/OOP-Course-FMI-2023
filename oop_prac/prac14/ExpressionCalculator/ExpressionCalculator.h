#pragma once

#include "../MyString/MyString.h"
#include "../StringView/StringView.h"

#include "../BooleanInterpretation/BooleanInterpretation.h"

#include "../BooleanExpression/BooleanExpression.h"

class ExpressionCalculator {
private:
    BooleanExpression *_expression;

    static BooleanExpression *parseExpression(const StringView &stringView);

public:
    ExpressionCalculator(const MyString &str);

};
