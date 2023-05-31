#include "UnitaryExpression.h"

UnitaryExpression::UnitaryExpression(char operand, BooleanExpression *expression) : _operand(operand), _expression(expression) {
    _variablesCount = expression->_variablesCount;
    for (size_t i = 0; i < VARIABLES_COUNT; ++i) {
        _variables[i] = expression->_variables[i];
    }
}

BooleanExpression *UnitaryExpression::clone() const {
    return new UnitaryExpression(_operand, _expression->clone());
}

bool UnitaryExpression::evaluate(const BooleanInterpretation &interpretation) const {
    return !_expression->evaluate(interpretation);
}
