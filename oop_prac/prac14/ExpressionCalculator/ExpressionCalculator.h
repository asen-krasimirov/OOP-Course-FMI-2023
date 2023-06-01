#pragma once

#include "../MyString/MyString.h"
#include "../StringView/StringView.h"

#include "../BooleanInterpretation/BooleanInterpretation.h"

#include "../BooleanExpression/BooleanExpression.h"

class ExpressionCalculator {
private:
    BooleanExpression *_expression;

    static BooleanExpression *parseExpression(const StringView &strView);

    bool checkAllVariations(bool expectedValue) const;

public:
    // Big6 (mandatory)
    ExpressionCalculator(const MyString &str);

    bool isTautology() const;
    bool isContradiction() const;

};
