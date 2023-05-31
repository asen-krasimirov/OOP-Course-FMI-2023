#include "Variable.h"

Variable::Variable(char ch) : _ch(ch) {

}

BooleanExpression *Variable::clone() const {
    return new Variable(*this);
}

bool Variable::evaluate(const BooleanInterpretation &interpretation) const {
    return interpretation.getVar(_ch);
}
