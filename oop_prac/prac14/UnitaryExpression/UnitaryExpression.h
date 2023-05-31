#pragma once

#include "../BooleanExpression/BooleanExpression.h"

class UnitaryExpression : BooleanExpression {
private:
    char _operand;
    BooleanExpression *_expression;

public:
    // Needs Big6 if not inside class of ExpressionCalculator
    UnitaryExpression(char operand, BooleanExpression *expression);

    BooleanExpression *clone() const override;

    bool evaluate(const BooleanInterpretation &interpretation) const override;

};