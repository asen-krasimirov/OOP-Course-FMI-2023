#pragma once

#include "../BooleanExpression/BooleanExpression.h"

class BinaryExpression : BooleanExpression {
private:
    char _operand;
    BooleanExpression *_left;
    BooleanExpression *_right;

public:
    // Needs Big6 if not inside class of ExpressionCalculator
    BinaryExpression(char operand, BooleanExpression *left, BooleanExpression *right);

    BooleanExpression *clone() const;
    bool evaluate(const BooleanInterpretation &interpretation) const override;

};
