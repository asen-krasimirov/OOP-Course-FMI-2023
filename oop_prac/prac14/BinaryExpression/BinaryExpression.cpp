#include "BinaryExpression.h"

//namespace {
//    const char AND = '^';
//    const char OR = 'v';
//    const char IMP = '>';
//    const char EQV = '=';
//}

BinaryExpression::BinaryExpression(char operand, BooleanExpression *left, BooleanExpression *right)
    : _operand(operand), _left(left), _right(right) {
    _variablesCount = 0;
    for (size_t i = 0; i < VARIABLES_COUNT; ++i) {
        if (_left->_variables[i] || _right->_variables[i]) {
            _variables[i] = true;
            _variablesCount++;
        }
    }
}

BooleanExpression *BinaryExpression::clone() const {
    return new BinaryExpression(_operand, _left->clone(), _right->clone());
}

bool BinaryExpression::evaluate(const BooleanInterpretation &interpretation) const {
    switch (_operand) {
        case AND: return _left->evaluate(interpretation) && _right->evaluate(interpretation);
        case OR: return _left->evaluate(interpretation) || _right->evaluate(interpretation);
        case IMP: return !_left->evaluate(interpretation) && _right->evaluate(interpretation);
        case EQV: return (_left->evaluate(interpretation) && _right->evaluate(interpretation)) || (!_left->evaluate(interpretation) && !_right->evaluate(interpretation));
        default: return false;
    }
}
