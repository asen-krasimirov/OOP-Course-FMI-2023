#include "UnitaryExpression.h"

UnitaryExpression::UnitaryExpression(char operand, BooleanExpression *expression) : _operand(operand), _expression(expression) {

}

BooleanExpression *UnitaryExpression::clone() const {
    return new UnitaryExpression(_operand, _expression->clone());
}

bool UnitaryExpression::evaluate(const BooleanInterpretation &interpretation) const {
    return !_expression->evaluate(interpretation);
}
