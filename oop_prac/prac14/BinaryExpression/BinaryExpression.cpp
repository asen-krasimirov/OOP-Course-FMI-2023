#include "BinaryExpression.h"

namespace {
    const char AND = '^';
    const char OR = 'v';
    const char IMP = '>';
    const char EQV = '=';
}

BinaryExpression::BinaryExpression(char operand, BooleanExpression *left, BooleanExpression *right) : _operand(operand), _left(left), _right(right) {

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
